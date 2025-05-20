//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

#define PI 3.1415926535

void calculator(int num1, int num2, char operator)
{
    switch (operator)
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
                printf("Cannot divide by zero\n");
            }
            else
            {
                printf("%d / %d = %d\n", num1, num2, num1 / num2);
            }
            break;
        default:
            printf("Invalid operator\n");
            break;
    }
}

int main()
{
    int num1, num2;
    char operator;

    printf("Enter operator (+, -, *, /): ");
    scanf("%c", &operator);

    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    calculator(num1, num2, operator);

    return 0;
}