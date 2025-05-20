//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    int i = 0;
    double num1, num2, result;
    char operator;

    // Get the calculator input from the user
    printf("Enter an expression: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    // Parse the input expression
    for (i = 0; buffer[i] != '\0'; i++)
    {
        // Check if the character is an operator
        if (buffer[i] == '+' || buffer[i] == '-' || buffer[i] == '*' || buffer[i] == '/')
        {
            operator = buffer[i];
            num1 = atof(buffer + i - 1);
            num2 = atof(buffer + i + 1);

            // Perform the calculation
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
            }

            // Print the result
            printf("The result is: %.2lf\n", result);

            // Reset the buffer and start again
            i = 0;
            memset(buffer, 0, MAX_BUFFER_SIZE);
        }
    }

    return 0;
}