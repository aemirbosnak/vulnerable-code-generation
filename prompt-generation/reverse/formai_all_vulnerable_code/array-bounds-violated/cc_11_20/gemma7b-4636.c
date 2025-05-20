//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    int i, stack[MAX_BUFFER_SIZE], top = -1, num1, num2, operator;

    printf("Welcome to the Crazy Calculator!\n");
    printf("Please enter your calculator expression: ");

    // Get the user input
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    // Tokenize the input
    i = 0;
    num1 = -1;
    num2 = -1;
    operator = -1;

    // Loop over the input to find operators and numbers
    while (buffer[i] != '\0')
    {
        // Check for numbers
        if (buffer[i] >= '0' && buffer[i] <= '9')
        {
            // Convert the number to an integer
            num2 = num2 * 10 + buffer[i] - '0';
            i++;

            // If there is a number before the operator, store it
            if (num1 != -1)
            {
                stack[++top] = num1;
            }

            num1 = num2;
        }

        // Check for operators
        else if (buffer[i] == '+' || buffer[i] == '-' || buffer[i] == '*' || buffer[i] == '/')
        {
            operator = buffer[i];
            i++;

            // If there is a number before the operator, store it
            if (num1 != -1)
            {
                stack[++top] = num1;
            }
        }
    }

    // Calculate the result
    if (num1 != -1)
    {
        stack[++top] = num1;
    }

    switch (operator)
    {
        case '+':
            num1 = stack[top] + stack[top - 1];
            break;
        case '-':
            num1 = stack[top] - stack[top - 1];
            break;
        case '*':
            num1 = stack[top] * stack[top - 1];
            break;
        case '/':
            num1 = stack[top] / stack[top - 1];
            break;
    }

    // Print the result
    printf("The result is: %d\n", num1);

    return 0;
}