//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: active
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int num1, num2, operator;
    char ch;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &ch);

    switch (ch)
    {
        case '+':
            operator = '+';
            break;
        case '-':
            operator = '-';
            break;
        case '*':
            operator = '*';
            break;
        case '/':
            operator = '/';
            break;
        default:
            printf("Invalid operator.\n");
            return;
    }

    switch (operator)
    {
        case '+':
            num1 += num2;
            break;
        case '-':
            num1 -= num2;
            break;
        case '*':
            num1 *= num2;
            break;
        case '/':
            if (num2 == 0)
            {
                printf("Cannot divide by zero.\n");
                return;
            }
            num1 /= num2;
            break;
        default:
            printf("Invalid operator.\n");
            return;
    }

    printf("The result is: %d\n", num1);
}