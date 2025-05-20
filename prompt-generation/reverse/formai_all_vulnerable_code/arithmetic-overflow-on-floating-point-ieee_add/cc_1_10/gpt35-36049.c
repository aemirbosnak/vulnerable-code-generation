//FormAI DATASET v1.0 Category: Calculator ; Style: bold
/* Bold Calculator Example Program */

#include <stdio.h>

int main()
{
    float num1, num2, result;
    char operator;

    printf("\nWelcome to the Bold Calculator\n");

    printf("Enter first number: ");
    scanf("%f", &num1);

    printf("Enter second number: ");
    scanf("%f", &num2);

    printf("Enter operator(+,-,*,/): ");
    scanf(" %c", &operator);

    if(operator == '+')
    {
        result = num1 + num2;
    }
    else if(operator == '-')
    {
        result = num1 - num2;
    }
    else if(operator == '*')
    {
        result = num1 * num2;
    }
    else if(operator == '/')
    {
        if(num2 == 0)
        {
            printf("\nError: Divide by zero is not possible!\n");
            return 1;
        }
        else
        {
            result = num1 / num2;
        }
    }
    else
    {
        printf("\nError: Invalid operator entered!\n");
        return 1;
    }

    printf("\nRESULT: %0.2f %c %0.2f = %0.2f\n", num1, operator, num2, result);

    return 0;
}

/* End of Bold Calculator Example Program */