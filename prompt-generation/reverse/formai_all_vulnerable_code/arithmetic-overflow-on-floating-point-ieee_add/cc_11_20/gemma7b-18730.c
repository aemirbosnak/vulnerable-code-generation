//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    int i = 0;
    char operator;
    double number1, number2, result;

    printf("Enter an expression: ");

    // Get the expression from the user
    while (1)
    {
        char character = getchar();

        // If the user has entered an operator, process it
        if (character == '+' || character == '-' || character == '*' || character == '/')
        {
            operator = character;
            break;
        }

        // If the user has entered a number, add it to the buffer
        else if (character >= '0' && character <= '9')
        {
            buffer[i++] = character;
        }

        // If the user has entered a special character, handle it
        else
        {
            switch (character)
            {
                case '(':
                case ')':
                case '%':
                    break;
            }
        }
    }

    // Convert the buffer into a number
    number1 = atof(buffer);

    // Get the second number from the user
    printf("Enter the second number: ");
    scanf("%lf", &number2);

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
                printf("Error: division by zero is not allowed\n");
            }
            else
            {
                result = number1 / number2;
            }
            break;
    }

    // Display the result
    printf("The result is: %.2lf\n", result);

    return 0;
}