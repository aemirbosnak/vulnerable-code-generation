//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Define the calculator module
void calculator(double num1, double num2, char operator)
{
    double result = 0;

    switch (operator)
    {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 == 0)
            {
                printf("Error: division by zero is not allowed");
                return;
            }
            result = num1 / num2;
            break;
        default:
            printf("Invalid operator");
            return;
    }

    printf("The result is: %.2lf", result);
}

int main()
{
    double num1, num2;
    char operator;

    printf("Enter the first number: ");
    scanf("%lf", &num1);

    printf("Enter the operator (+, -, *, /): ");
    scanf(" %c", &operator);

    printf("Enter the second number: ");
    scanf("%lf", &num2);

    calculator(num1, num2, operator);

    return 0;
}