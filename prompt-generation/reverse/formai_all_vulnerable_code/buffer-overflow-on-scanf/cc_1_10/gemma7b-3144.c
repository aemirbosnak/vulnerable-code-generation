//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char operator;
    float num1, num2, result;
    int flag = 0;

    printf("Enter Operator (+, -, *, /): ");
    operator = getchar();

    printf("Enter First Number: ");
    scanf("%f", &num1);

    printf("Enter Second Number: ");
    scanf("%f", &num2);

    switch (operator)
    {
        case '+':
            result = num1 + num2;
            flag = 1;
            break;
        case '-':
            result = num1 - num2;
            flag = 1;
            break;
        case '*':
            result = num1 * num2;
            flag = 1;
            break;
        case '/':
            if (num2 == 0)
            {
                printf("Cannot divide by zero\n");
            }
            else
            {
                result = num1 / num2;
                flag = 1;
            }
            break;
        default:
            printf("Invalid Operator\n");
            flag = 1;
            break;
    }

    if (flag == 1)
    {
        printf("The result is: %.2f\n", result);
    }

    return 0;
}