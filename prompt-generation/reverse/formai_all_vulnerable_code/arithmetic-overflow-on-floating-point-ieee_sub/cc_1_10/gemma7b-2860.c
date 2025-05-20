//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

void calculate(char **buffer, int *index, double *result)
{
    double num1, num2;
    char operator;

    // Extract operator and operands from the buffer
    operator = buffer[*index];
    num1 = atof(buffer[*index - 1]);
    num2 = atof(buffer[*index - 2]);

    // Perform the calculation
    switch (operator)
    {
        case '+':
            *result = num1 + num2;
            break;
        case '-':
            *result = num1 - num2;
            break;
        case '*':
            *result = num1 * num2;
            break;
        case '/':
            if (num2 == 0)
            {
                printf("Error: division by zero is not allowed\n");
                return;
            }
            *result = num1 / num2;
            break;
        default:
            printf("Error: invalid operator\n");
            return;
    }

    // Increment the index and store the result
    (*index)++;
    buffer[*index] = '\0';
    *result = num1 + num2;
}

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    int index = 0;
    double result = 0;

    // Get the calculator input
    printf("Enter an expression: ");
    scanf("%s", buffer);

    // Calculate the result
    calculate(buffer, &index, &result);

    // Print the result
    if (result != 0)
    {
        printf("The result is: %.2lf\n", result);
    }

    return 0;
}