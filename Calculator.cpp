#include <cstdlib>   // EXIT_FAILURE
#include <iostream>
#include <stdexcept> // std::logic_error

float calculate(const char operation, const float left, const float right)
{
    switch (operation)
    {
        case '+': return left + right;
        case '-': return left - right;
        case '*': return left * right;
        case '/': return left / right;
        default: throw std::logic_error("unsupported operator");
    }
}

int main()
{
    std::cout << "Enter your two numbers: \n\n";
    float left, right;
    std::cin >> left >> right;

    std::cout << "\nEnter your operation (+, -, *, /): ";
    char operation;
    std::cin >> operation;

    // terminate right away if dividing by zero
    if (operation == '/' && right == 0)
    {
        std::cerr << "Cannot divide by 0";
        return EXIT_FAILURE;
    }

    float result;

    // attempt the calculation (will throw if failed)
    try
    {
        result = calculate(operation, left, right);
    }
    // if it fails - catch exception, display it, then terminate
    catch (std::logic_error const& e)
    {
        std::cerr << "Error: " << e.what();
        return EXIT_FAILURE;
    }

    std::cout << "\nResult = " << result;
}
