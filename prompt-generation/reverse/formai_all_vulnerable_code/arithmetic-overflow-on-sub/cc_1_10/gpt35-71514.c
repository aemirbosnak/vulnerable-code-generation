//FormAI DATASET v1.0 Category: Arithmetic ; Style: complex
#include <stdio.h>

int main()
{
    int num1, num2, num3, flag = 0;
    char operator;
    float result;

    printf("Enter three integers:\n");
    scanf("%d %d %d", &num1, &num2, &num3);

    printf("Enter operator (+, -, *, /, %%, ^):\n");
    scanf(" %c", &operator);

    if (operator == '+')
    {
        result = num1 + num2 + num3;
    }
    else if (operator == '-')
    {
        result = num1 - num2 - num3;
    }
    else if (operator == '*')
    {
        result = num1 * num2 * num3;
    }
    else if (operator == '/')
    {
        result = (float)num1 / (float)num2 / (float)num3;
    }
    else if (operator == '%')
    {
        result = (num1 % num2) % num3;
    }
    else if (operator == '^')
    {
        result = 1;
        for (int i = 1; i <= num3; i++)
        {
            result *= num1;
        }
        result = result * num2;
    }
    else
    {
        printf("ERROR: Invalid operator!\n");
        flag = 1;
    }

    if (flag == 0)
    {
        printf("\nThe %c of %d, %d and %d is %f\n", operator, num1, num2, num3, result);
    }

    return 0;
}