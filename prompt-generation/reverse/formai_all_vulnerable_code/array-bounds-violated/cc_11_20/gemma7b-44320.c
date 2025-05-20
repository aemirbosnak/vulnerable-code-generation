//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    char operator;
    double num1, num2, result;
    int i = 0;

    printf("Enter an expression: ");
    scanf("%s", buffer);

    // Parse the expression
    for (i = 0; buffer[i] != '\0'; i++)
    {
        // Check if the character is an operator
        if (buffer[i] == '+' || buffer[i] == '-' || buffer[i] == '*' || buffer[i] == '/')
        {
            operator = buffer[i];
            num1 = atof(buffer[i - 1] == ' ' ? buffer[i - 1] : "");
            num2 = atof(buffer[i + 1] == ' ' ? buffer[i + 1] : "");

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
            }

            // Print the result
            printf("%f", result);
            printf("\n");
        }
    }

    return 0;
}