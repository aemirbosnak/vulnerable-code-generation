//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    int i = 0;
    char operator;
    double number1, number2, result;

    // Initialize the buffer to store the input
    buffer[0] = '\0';

    // Loop to get the input from the user
    while (1)
    {
        // Get the next character from the user
        char character = getchar();

        // Check if the character is an operator
        if (character == '+')
        {
            operator = '+';
            break;
        }
        else if (character == '-')
        {
            operator = '-';
            break;
        }
        else if (character == '*')
        {
            operator = '*';
            break;
        }
        else if (character == '/')
        {
            operator = '/';
            break;
        }
        else if (character == '=')
        {
            break;
        }
        else
        {
            // Append the character to the buffer
            buffer[i++] = character;
        }
    }

    // Convert the buffer into a number
    number1 = atof(buffer);

    // Get the operator
    switch (operator)
    {
        case '+':
            // Get the second number
            buffer[0] = '\0';
            i = 0;
            while (1)
            {
                char character = getchar();
                if (character == '=')
                {
                    break;
                }
                else
                {
                    buffer[i++] = character;
                }
            }
            number2 = atof(buffer);
            result = number1 + number2;
            break;
        case '-':
            // Get the second number
            buffer[0] = '\0';
            i = 0;
            while (1)
            {
                char character = getchar();
                if (character == '=')
                {
                    break;
                }
                else
                {
                    buffer[i++] = character;
                }
            }
            number2 = atof(buffer);
            result = number1 - number2;
            break;
        case '*':
            // Get the second number
            buffer[0] = '\0';
            i = 0;
            while (1)
            {
                char character = getchar();
                if (character == '=')
                {
                    break;
                }
                else
                {
                    buffer[i++] = character;
                }
            }
            number2 = atof(buffer);
            result = number1 * number2;
            break;
        case '/':
            // Get the second number
            buffer[0] = '\0';
            i = 0;
            while (1)
            {
                char character = getchar();
                if (character == '=')
                {
                    break;
                }
                else
                {
                    buffer[i++] = character;
                }
            }
            number2 = atof(buffer);
            result = number1 / number2;
            break;
    }

    // Display the result
    printf("The result is: %.2lf\n", result);

    return 0;
}