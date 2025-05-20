//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    char operator;
    double num1, num2;

    printf("Welcome to the Electric Boogaloo Scientific Calculator!\n");
    printf("Please enter your calculator expression: ");

    // Get the user input
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    // Parse the input
    num1 = atof(buffer);
    operator = buffer[strlen(buffer) - 1];
    num2 = atof(buffer + strlen(buffer) - 1);

    // Perform the calculation
    switch (operator)
    {
        case '+':
            printf("The result is: %.2lf\n", num1 + num2);
            break;
        case '-':
            printf("The result is: %.2lf\n", num1 - num2);
            break;
        case '*':
            printf("The result is: %.2lf\n", num1 * num2);
            break;
        case '/':
            if (num2 == 0)
            {
                printf("Error: division by zero is not allowed.\n");
            }
            else
            {
                printf("The result is: %.2lf\n", num1 / num2);
            }
            break;
        default:
            printf("Error: invalid operator.\n");
            break;
    }

    return 0;
}