//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_BUFFER_SIZE 256

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    double result = 0.0;
    int i = 0;
    int sign = 1;
    char operator = '\0';

    printf("Enter an expression: ");
    scanf("%s", buffer);

    // Loop over the input buffer to identify operators and numbers
    for (i = 0; buffer[i] != '\0'; i++)
    {
        // Check if the character is an operator
        if (buffer[i] >= 'a' && buffer[i] <= 'z')
        {
            operator = buffer[i];
        }
        // Check if the character is a number
        else if (buffer[i] >= '0' && buffer[i] <= '9')
        {
            // Convert the number to an integer
            int number = buffer[i] - '0';

            // Multiply the number by the sign
            number *= sign;

            // Add the number to the result
            result += (double)number;
        }
        // Check if the character is a parenthesis
        else if (buffer[i] == '(')
        {
            // Remember the sign and operator before the parenthesis
            sign = buffer[i - 1] - '0';
            operator = buffer[i - 2];
        }
    }

    // Calculate the result
    switch (operator)
    {
        case '+':
            result *= sign;
            break;
        case '-':
            result *= sign;
            break;
        case '*':
            result *= sign;
            break;
        case '/':
            if (result == 0)
            {
                printf("Cannot divide by zero\n");
            }
            else
            {
                result *= sign;
            }
            break;
        case '^':
            result *= sign;
            break;
    }

    // Display the result
    printf("The result is: %.2lf\n", result);

    return 0;
}