//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    char operator;
    float num1, num2, result;
    int i = 0;

    printf("Welcome to the Post-Apocalyptic Scientific Calculator.\n");

    // Get the user input
    printf("Enter an expression: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    // Parse the user input
    operator = buffer[i];
    num1 = atof(buffer[i + 1]);
    num2 = atof(buffer[i + 2]);

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
            if (num2 == 0)
            {
                printf("Error: division by zero is not permitted.\n");
            }
            else
            {
                result = num1 / num2;
            }
            break;
        default:
            printf("Error: invalid operator.\n");
    }

    // Display the result
    if (result != -1)
    {
        printf("The result is: %.2f\n", result);
    }

    return 0;
}