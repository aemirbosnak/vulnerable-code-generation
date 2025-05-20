//FormAI DATASET v1.0 Category: Calculator ; Style: brave
#include<stdio.h>

int main()
{
    int num1, num2, result;
    char operator;

    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    printf("Enter the operator(+,-,*,/): ");
    scanf(" %c", &operator);

    switch(operator)
    {
        case '+':
            result = num1 + num2;
            printf("%d %c %d = %d", num1, operator, num2, result);
            break;

        case '-':
            result = num1 - num2;
            printf("%d %c %d = %d", num1, operator, num2, result);
            break;

        case '*':
            result = num1 * num2;
            printf("%d %c %d = %d", num1, operator, num2, result);
            break;

        case '/':
            if(num2 == 0)
            {
                printf("Cannot divide by zero");
            }
            else
            {
                result = num1 / num2;
                printf("%d %c %d = %d", num1, operator, num2, result);
            }
            break;

        default:
            printf("Invalid operator");
            break;
    }

    return 0;
}