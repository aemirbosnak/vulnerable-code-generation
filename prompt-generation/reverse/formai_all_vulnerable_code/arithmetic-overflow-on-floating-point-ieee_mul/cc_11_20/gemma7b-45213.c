//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    int i = 0;
    char operator;
    double number;
    double result = 0.0;

    printf("Enter an expression: ");
    // Read the expression from the user
    while (1)
    {
        char ch = getchar();
        if (ch == '\n')
            break;
        buffer[i++] = ch;
    }

    // Parse the expression
    i = 0;
    while (buffer[i] != '\0')
    {
        // Check if the character is an operator
        if (buffer[i] == '+' || buffer[i] == '-' || buffer[i] == '*' || buffer[i] == '/')
        {
            operator = buffer[i];
            number = atof(buffer + i - 1);
            switch (operator)
            {
                case '+':
                    result += number;
                    break;
                case '-':
                    result -= number;
                    break;
                case '*':
                    result *= number;
                    break;
                case '/':
                    if (number == 0)
                    {
                        printf("Cannot divide by zero\n");
                        return 1;
                    }
                    result /= number;
                    break;
            }
            i++;
        }
        else
        {
            i++;
        }
    }

    // Print the result
    printf("The result is: %.2lf\n", result);

    return 0;
}