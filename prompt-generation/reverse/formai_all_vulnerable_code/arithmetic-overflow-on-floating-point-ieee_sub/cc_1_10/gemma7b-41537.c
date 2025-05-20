//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_BUFFER_SIZE 256

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    char operator;
    double number1, number2, result;

    printf("Enter an expression: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    // Parse the expression
    operator = buffer[0];
    number1 = atof(buffer + 1);

    // Check for valid operator
    if (operator == '+' || operator == '-' || operator == '*' || operator == '/')
    {
        // Get the second number
        printf("Enter the second number: ");
        fgets(buffer, MAX_BUFFER_SIZE, stdin);
        number2 = atof(buffer);

        // Perform the calculation
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
        }

        // Display the result
        printf("The result is: %.2lf\n", result);
    }
    else
    {
        printf("Invalid operator.\n");
    }

    return 0;
}