//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 256

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    char operator;
    double number1, number2;
    double result;
    int i = 0;

    printf("Enter an expression: ");

    // Get the expression from the user
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    // Iterate over the expression to find the operator
    for (i = 0; buffer[i] != '\0'; i++)
    {
        if (buffer[i] == '+' || buffer[i] == '-' || buffer[i] == '*' || buffer[i] == '/')
        {
            operator = buffer[i];
            break;
        }
    }

    // Extract the numbers from the expression
    number1 = atof(buffer);
    number2 = atof(buffer + i + 1);

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
            if (number2 == 0)
            {
                printf("Error: division by zero\n");
            }
            else
            {
                result = number1 / number2;
            }
            break;
        default:
            printf("Error: invalid operator\n");
    }

    // Display the result
    printf("The result is: %.2lf\n", result);

    return 0;
}