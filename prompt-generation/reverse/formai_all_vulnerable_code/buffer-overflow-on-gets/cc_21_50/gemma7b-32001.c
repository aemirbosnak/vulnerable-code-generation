//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    int i, j, n, sign, result = 0, number_of_operations = 0;
    char operator;

    printf("Enter an expression: ");

    // Get the expression from the user
    gets(buffer);

    // Tokenize the expression
    n = 0;
    for (i = 0; buffer[i] != '\0'; i++)
    {
        if (buffer[i] >= 'a' && buffer[i] <= 'z')
        {
            buffer[i] = buffer[i] - 32;
        }
        else if (buffer[i] >= 'A' && buffer[i] <= 'Z')
        {
            buffer[i] = buffer[i] - 32;
        }
        else if (buffer[i] == '+')
        {
            operator = '+';
            number_of_operations++;
        }
        else if (buffer[i] == '-')
        {
            operator = '-';
            number_of_operations++;
        }
        else if (buffer[i] == '*')
        {
            operator = '*';
            number_of_operations++;
        }
        else if (buffer[i] == '/')
        {
            operator = '/';
            number_of_operations++;
        }
        else if (buffer[i] == '(')
        {
            buffer[i] = ')';
        }
        else if (buffer[i] == ')')
        {
            buffer[i] = '(';
        }
        else if (buffer[i] == ')')
        {
            buffer[i] = '(';
        }
        n++;
    }

    // Calculate the result
    if (number_of_operations > 0)
    {
        for (i = 0; i < n; i++)
        {
            if (buffer[i] >= 'a' && buffer[i] <= 'z')
            {
                buffer[i] = buffer[i] - 32;
            }
            else if (buffer[i] >= 'A' && buffer[i] <= 'Z')
            {
                buffer[i] = buffer[i] - 32;
            }
            else if (buffer[i] == '+')
            {
                sign = 1;
            }
            else if (buffer[i] == '-')
            {
                sign = -1;
            }
            else if (buffer[i] == '*')
            {
                buffer[i] = ' ';
            }
            else if (buffer[i] == '/')
            {
                buffer[i] = ' ';
            }
            else if (buffer[i] == '(')
            {
                buffer[i] = ')';
            }
            else if (buffer[i] == ')')
            {
                buffer[i] = '(';
            }
            else if (buffer[i] == ')')
            {
                buffer[i] = '(';
            }
        }

        for (i = 0; i < n; i++)
        {
            if (buffer[i] >= 'a' && buffer[i] <= 'z')
            {
                buffer[i] = buffer[i] - 32;
            }
            else if (buffer[i] >= 'A' && buffer[i] <= 'Z')
            {
                buffer[i] = buffer[i] - 32;
            }
            else if (buffer[i] == '+')
            {
                result += sign * atoi(&buffer[i + 1]) * pow(10, number_of_operations - 1);
            }
            else if (buffer[i] == '-')
            {
                result -= sign * atoi(&buffer[i + 1]) * pow(10, number_of_operations - 1);
            }
            else if (buffer[i] == '*')
            {
                result *= sign * atoi(&buffer[i + 1]) * pow(10, number_of_operations - 1);
            }
            else if (buffer[i] == '/')
            {
                result /= sign * atoi(&buffer[i + 1]) * pow(10, number_of_operations - 1);
            }
            number_of_operations--;
        }
    }

    // Print the result
    printf("The result is: %d\n", result);

    return 0;
}