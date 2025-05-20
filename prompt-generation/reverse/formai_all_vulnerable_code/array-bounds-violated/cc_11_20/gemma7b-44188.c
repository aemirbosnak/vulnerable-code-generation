//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    int i, j, position = 0, sign = 1, number = 0;

    // Get the calculator input
    printf("Enter an expression: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    // Parse the input expression
    for (i = 0; buffer[i] != '\0'; i++)
    {
        // Check if the character is a number
        if (buffer[i] >= '0' && buffer[i] <= '9')
        {
            // Convert the character to an integer
            number = number * 10 + buffer[i] - '0';

            // Store the number
            buffer[position] = number;
            position++;
        }
        // Check if the character is an operator
        else if (buffer[i] == '+' || buffer[i] == '-' || buffer[i] == '*' || buffer[i] == '/')
        {
            // Store the operator
            buffer[position] = buffer[i];
            position++;

            // Check if the operator is a binary operator
            if (buffer[i - 1] == '(')
            {
                sign = -1;
            }
        }
        // Check if the character is a parenthesis
        else if (buffer[i] == ')')
        {
            // Reset the sign
            sign = 1;

            // Calculate the expression
            for (j = position - 1; j >= 0 && buffer[j] != '('; j--)
            {
                int operand2 = buffer[j] - '0';
                int operand1 = buffer[position - 1] - '0';
                int result = 0;

                switch (buffer[j])
                {
                    case '+':
                        result = operand1 + operand2;
                        break;
                    case '-':
                        result = operand1 - operand2;
                        break;
                    case '*':
                        result = operand1 * operand2;
                        break;
                    case '/':
                        result = operand1 / operand2;
                        break;
                }

                // Store the result
                buffer[position] = result;
                position++;
            }
        }
    }

    // Print the result
    printf("The result is: ");
    for (i = 0; buffer[i] != '\0'; i++)
    {
        printf("%c ", buffer[i]);
    }

    printf("\n");

    return 0;
}