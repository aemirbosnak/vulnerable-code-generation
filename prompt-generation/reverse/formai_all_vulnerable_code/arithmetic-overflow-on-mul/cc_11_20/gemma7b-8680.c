//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char buffer[200];
    int i = 0;
    int number1 = 0;
    int number2 = 0;
    char operator = '\0';

    printf("Enter an expression: ");
    fgets(buffer, 200, stdin);

    // Paranoid string parsing
    for (i = 0; buffer[i] != '\0'; i++)
    {
        if (isdigit(buffer[i]))
        {
            number1 = number1 * 10 + buffer[i] - '0';
        }
        else if (buffer[i] == '+')
        {
            operator = '+';
        }
        else if (buffer[i] == '-')
        {
            operator = '-';
        }
        else if (buffer[i] == '*')
        {
            operator = '*';
        }
        else if (buffer[i] == '/')
        {
            operator = '/';
        }
    }

    // Check for valid operator and calculate result
    if (operator != '\0')
    {
        number2 = number1 * 10 + buffer[i] - '0';
        switch (operator)
        {
            case '+':
                printf("The result is: %d\n", number1 + number2);
                break;
            case '-':
                printf("The result is: %d\n", number1 - number2);
                break;
            case '*':
                printf("The result is: %d\n", number1 * number2);
                break;
            case '/':
                if (number2 == 0)
                {
                    printf("Cannot divide by zero.\n");
                }
                else
                {
                    printf("The result is: %d\n", number1 / number2);
                }
                break;
            default:
                printf("Invalid operator.\n");
                break;
        }
    }
    else
    {
        printf("Invalid expression.\n");
    }

    return 0;
}