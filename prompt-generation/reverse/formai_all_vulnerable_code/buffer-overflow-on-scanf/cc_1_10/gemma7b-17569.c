//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    char operator;
    double num1, num2, result;
    int i = 0;

    // Initialize the calculator
    printf("Welcome to the scientific calculator!\n");

    // Get the first number
    printf("Enter the first number: ");
    scanf("%lf", &num1);

    // Get the operator
    printf("Enter the operator (+, -, *, /, %): ");
    scanf(" %c", &operator);

    // Get the second number
    printf("Enter the second number: ");
    scanf("%lf", &num2);

    // Calculate the result
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
            result = num1 / num2;
            break;
        case '%':
            result = fmod(num1, num2);
            break;
        default:
            printf("Invalid operator.\n");
            return 1;
    }

    // Display the result
    printf("The result is: %.2lf\n", result);

    // Repeat for multiple calculations
    printf("Do you want to calculate again? (Y/N): ");
    scanf(" %c", &i);

    if (i == 'Y')
    {
        main();
    }

    return 0;
}