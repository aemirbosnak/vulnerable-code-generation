//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    int i = 0;
    char operator;
    double num1, num2, result;

    printf("Enter an expression: ");

    // Loop to read the expression character by character
    while (buffer[i] = getchar() != '\n')
    {
        i++;
    }

    // Calculate the operator
    operator = buffer[i - 1];

    // Extract the two numbers
    num1 = atof(buffer);
    num2 = atof(buffer + i);

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
        default:
            printf("Error: Invalid operator.\n");
            return 1;
    }

    // Display the result
    printf("The result is: %.2lf\n", result);

    return 0;
}