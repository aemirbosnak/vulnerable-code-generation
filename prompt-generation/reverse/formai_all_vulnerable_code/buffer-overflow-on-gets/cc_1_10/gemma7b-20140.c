//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    int i, stack[MAX_BUFFER_SIZE], top = -1, num, operator;

    printf("Enter an expression: ");

    // Get the expression from the user
    gets(buffer);

    // Parse the expression
    for (i = 0; buffer[i] != '\0'; i++)
    {
        // Check if the character is an operator
        if (buffer[i] >= 'a' && buffer[i] <= 'z')
        {
            operator = buffer[i];
            num = atoi(&buffer[i - 1]);

            // Push the number onto the stack
            stack[++top] = num;

            // Perform the operation
            switch (operator)
            {
                case '+':
                    stack[++top] = stack[top] + num;
                    break;
                case '-':
                    stack[++top] = stack[top] - num;
                    break;
                case '*':
                    stack[++top] = stack[top] * num;
                    break;
                case '/':
                    if (num == 0)
                    {
                        printf("Cannot divide by 0\n");
                        return 1;
                    }
                    stack[++top] = stack[top] / num;
                    break;
            }
        }
    }

    // Evaluate the remaining expression
    num = stack[top];

    // Print the result
    printf("The result is: %d\n", num);

    return 0;
}