//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    int i = 0;
    double number1, number2, result;
    char operator;

    printf("Enter an expression: ");

    // Get the user input
    while (1)
    {
        char character = getchar();

        // Check if the user has entered an operator or a number
        if (character >= 'a' && character <= 'z')
        {
            operator = character;
            break;
        }
        else if (character >= '0' && character <= '9')
        {
            buffer[i++] = character;
        }
        else if (character == '\n')
        {
            break;
        }
    }

    // Convert the user's input into numbers
    number1 = atof(buffer);
    number2 = atof(buffer + i);

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
            printf("Error\n");
            return 1;
    }

    // Print the result
    printf("The result is: %.2lf\n", result);

    return 0;
}