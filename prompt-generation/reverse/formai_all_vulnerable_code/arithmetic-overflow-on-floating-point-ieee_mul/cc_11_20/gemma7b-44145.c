//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    char operator;
    float number1, number2, result;
    int i = 0;

    printf("Enter an expression: ");

    // Get the expression from the user
    while (1)
    {
        char character = getchar();

        // If the user has entered an operator, process it
        if (character == '+' || character == '-' || character == '*' || character == '/')
        {
            operator = character;
            break;
        }

        // If the user has entered a number, add it to the buffer
        else if (character >= '0' && character <= '9')
        {
            buffer[i++] = character;
        }

        // If the user has entered a special character, handle it
        else
        {
            // Handle special characters here
        }
    }

    // Convert the expression into a float
    number1 = atof(buffer);

    // Get the second number from the user
    printf("Enter the second number: ");
    scanf("%f", &number2);

    // Perform the operation
    switch (operator)
    {
        case '+':
            result = number1 + number2;
            break;
        case '-':
            result = number1 - number2;
            break;
        case '*':
            result = number1 * number2;
            break;
        case '/':
            result = number1 / number2;
            break;
        default:
            printf("Error: Invalid operator.\n");
            break;
    }

    // Display the result
    printf("The result is: %.2f\n", result);

    return 0;
}