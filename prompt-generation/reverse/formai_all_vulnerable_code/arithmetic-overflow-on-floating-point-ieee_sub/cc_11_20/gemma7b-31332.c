//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

int main()
{
    char buffer[MAX_BUFFER_SIZE] = "";
    char operator;
    double num1, num2;
    double result;
    int i = 0;

    printf("Welcome to the Turbo Scientific Calculator!\n");

    // Loop until the user enters an operator or a valid number
    while (1)
    {
        printf("Enter an operator (+, -, *, /, %): ");
        operator = getchar();

        // Check if the operator is valid
        if (operator == '+' || operator == '-' || operator == '*' || operator == '/')
        {
            break;
        }

        // Clear the buffer
        buffer[0] = '\0';
    }

    // Get the first number
    printf("Enter the first number: ");
    scanf("%lf", &num1);

    // Get the second number
    printf("Enter the second number: ");
    scanf("%lf", &num2);

    // Perform the operation
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
                printf("Error: division by zero is not allowed.\n");
            }
            else
            {
                result = num1 / num2;
            }
            break;
    }

    // Display the result
    printf("The result is: %.2lf\n", result);

    return 0;
}