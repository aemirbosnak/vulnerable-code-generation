//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    int i = 0;
    char operator;
    double number1, number2, result;

    printf("Enter an expression: ");

    // Get the user input
    while (1)
    {
        char input = getchar();

        // Check if the input is an operator or a number
        if (input >= 'a' && input <= 'z')
        {
            operator = input;
            break;
        }
        else if (input >= '0' && input <= '9')
        {
            buffer[i++] = input;
        }
        else if (input == '\n')
        {
            break;
        }
    }

    // Convert the user input into numbers
    number1 = atof(buffer);

    // Get the operator
    operator = buffer[i - 1];

    // Get the second number
    i = 0;
    buffer[0] = '\0';
    printf("Enter the second number: ");

    // Get the user input
    while (1)
    {
        char input = getchar();

        // Check if the input is a number
        if (input >= '0' && input <= '9')
        {
            buffer[i++] = input;
        }
        else if (input == '\n')
        {
            break;
        }
    }

    // Convert the second number into a number
    number2 = atof(buffer);

    // Calculate the result
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
            printf("Error: invalid operator.\n");
            return 1;
    }

    // Print the result
    printf("The result is: %.2lf\n", result);

    return 0;
}