//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    char operator;
    double operand1, operand2, result;

    printf("Enter an expression: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    // Parse the expression
    operator = buffer[0];
    operand1 = atof(buffer + 1);

    // Calculate the result
    switch (operator)
    {
        case '+':
            operand2 = atof(buffer + 2);
            result = operand1 + operand2;
            break;
        case '-':
            operand2 = atof(buffer + 2);
            result = operand1 - operand2;
            break;
        case '*':
            operand2 = atof(buffer + 2);
            result = operand1 * operand2;
            break;
        case '/':
            operand2 = atof(buffer + 2);
            if (operand2 == 0)
            {
                printf("Cannot divide by zero\n");
                return 1;
            }
            result = operand1 / operand2;
            break;
        default:
            printf("Invalid operator\n");
            return 1;
    }

    // Display the result
    printf("The result is: %.2lf\n", result);

    return 0;
}