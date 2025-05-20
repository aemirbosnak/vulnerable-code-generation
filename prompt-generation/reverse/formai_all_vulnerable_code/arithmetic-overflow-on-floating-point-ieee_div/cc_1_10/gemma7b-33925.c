//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 256

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    char operator;
    double number1, number2;

    printf("Enter an expression: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    // Parse the expression
    operator = buffer[0];
    number1 = atof(buffer + 1);
    number2 = atof(buffer + 3);

    // Calculate the result
    double result = 0;
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
    }

    // Display the result
    if (result != 0)
    {
        printf("The result is: %.2lf\n", result);
    }
    else
    {
        printf("Error: invalid expression\n");
    }

    return 0;
}