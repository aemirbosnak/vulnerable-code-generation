//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 255

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    int i, j, flag = 0, num1 = 0, num2 = 0;

    printf("Enter your expression: ");

    // Get the user's expression
    gets(buffer);

    // Parse the user's expression
    for (i = 0; buffer[i] != '\0'; i++)
    {
        // Check if the character is a number
        if (buffer[i] >= '0' && buffer[i] <= '9')
        {
            // Convert the character to an integer
            num1 = num1 * 10 + buffer[i] - '0';
        }
        // Check if the character is an operator
        else
        {
            // Flag to indicate that an operator has been found
            flag = 1;

            // Store the operator
            num2 = num1;

            // Reset num1
            num1 = 0;
        }
    }

    // Check if the user has entered an operator
    if (flag == 0)
    {
        printf("Error: No operator found.\n");
        return 1;
    }

    // Calculate the result of the expression
    switch (buffer[i - 1])
    {
        case '+':
            num1 = num2 + num1;
            break;
        case '-':
            num1 = num2 - num1;
            break;
        case '*':
            num1 = num2 * num1;
            break;
        case '/':
            if (num2 == 0)
            {
                printf("Error: Division by zero is undefined.\n");
                return 1;
            }
            num1 = num2 / num1;
            break;
    }

    // Print the result of the expression
    printf("The result of your expression is: %d\n", num1);

    return 0;
}