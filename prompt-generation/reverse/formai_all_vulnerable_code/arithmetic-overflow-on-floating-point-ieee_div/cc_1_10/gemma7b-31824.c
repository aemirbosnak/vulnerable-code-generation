//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

void clear_buffer(char *);

int main()
{
    char buffer[MAX_BUFFER_SIZE] = "";
    char operator = '\0';
    double num1 = 0.0, num2 = 0.0;

    printf("Enter an operator (+, -, *, /, %): ");
    operator = getchar();

    clear_buffer(buffer);

    printf("Enter the first number: ");
    scanf("%lf", &num1);

    clear_buffer(buffer);

    printf("Enter the second number: ");
    scanf("%lf", &num2);

    clear_buffer(buffer);

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
                printf("Cannot divide by zero!\n");
            }
            else
            {
                printf("The result is: %.2lf\n", num1 / num2);
            }
            break;
        default:
            printf("Invalid operator.\n");
            break;
    }

    return 0;
}

void clear_buffer(char *buffer)
{
    while (*buffer)
    {
        *buffer = '\0';
        buffer++;
    }
}