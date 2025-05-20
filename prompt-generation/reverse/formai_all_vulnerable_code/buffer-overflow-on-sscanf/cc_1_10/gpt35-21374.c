//FormAI DATASET v1.0 Category: Arithmetic ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT 100

int main(void)
{
    char input[MAX_INPUT];
    int num1, num2;
    char op;

    printf("Enter a mathematical expression: ");
    fgets(input, MAX_INPUT, stdin);

    // Remove trailing newline
    input[strcspn(input, "\n")] = 0;

    // Parse input
    if (sscanf(input, "%d %c %d", &num1, &op, &num2) != 3)
    {
        printf("Invalid input.\n");
        return 1;
    }

    // Perform operation
    switch (op)
    {
        case '+':
            printf("%d + %d = %d\n", num1, num2, num1 + num2);
            break;
        case '-':
            printf("%d - %d = %d\n", num1, num2, num1 - num2);
            break;
        case '*':
            printf("%d * %d = %d\n", num1, num2, num1 * num2);
            break;
        case '/':
            if (num2 == 0)
            {
                printf("Division by zero error.\n");
                return 1;
            }
            printf("%d / %d = %d\n", num1, num2, num1 / num2);
            break;
        case '%':
            if (num2 == 0)
            {
                printf("Division by zero error.\n");
                return 1;
            }
            printf("%d %% %d = %d\n", num1, num2, num1 % num2);
            break;
        default:
            printf("Invalid operator '%c'\n", op);
            return 1;
    }

    return 0;
}