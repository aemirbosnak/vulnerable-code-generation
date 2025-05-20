//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    char operator;
    double num1, num2, result;

    printf("**Welcome to the Romantic Calculator!**\n");

    // Get the first number
    printf("Enter the first number: ");
    scanf("%lf", &num1);

    // Get the operator
    printf("Enter an operator (+, -, *, /): ");
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
        default:
            printf("Invalid operator.\n");
            return 1;
    }

    // Display the result
    printf("The result is: %.2lf\n", result);

    // Clear the buffer
    memset(buffer, 0, MAX_BUFFER_SIZE);

    // Prompt for additional calculations
    printf("Would you like to continue calculating? (Y/N): ");
    scanf(" %c", buffer);

    // Check if the user wants to continue
    if (strcmp(buffer, "Y") == 0)
    {
        main();
    }

    return 0;
}