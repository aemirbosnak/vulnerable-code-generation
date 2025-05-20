//FormAI DATASET v1.0 Category: Arithmetic ; Style: Dennis Ritchie
#include <stdio.h>

/* function that calculates the factorial of a number */
int factorial(int num)
{
    if (num == 0 || num == 1)
    {
        return 1;
    }
    else
    {
        return num * factorial(num-1);
    }
}

int main()
{
    int num, choice, i, j;
    float result;

    /* program menu */
    printf("Welcome to the arithmetic program!\n");
    printf("Please select an operation:\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Calculate factorial\n");

    scanf("%d", &choice);

    switch (choice)
    {
        /* addition case */
        case 1:
            printf("Enter first number: ");
            scanf("%d", &i);
            printf("Enter second number: ");
            scanf("%d", &j);
            result = i+j;
            printf("The result is: %.3f\n", result);
            break;

        /* subtraction case */
        case 2:
            printf("Enter first number: ");
            scanf("%d", &i);
            printf("Enter second number: ");
            scanf("%d", &j);
            result = i-j;
            printf("The result is: %.3f\n", result);
            break;

        /* multiplication case */
        case 3:
            printf("Enter first number: ");
            scanf("%d", &i);
            printf("Enter second number: ");
            scanf("%d", &j);
            result = i*j;
            printf("The result is: %.3f\n", result);
            break;

        /* division case */
        case 4:
            printf("Enter numerator: ");
            scanf("%d", &i);
            printf("Enter denominator: ");
            scanf("%d", &j);
            if (j == 0)
            {
                printf("Error: division by zero\n");
                return 0;
            }
            result = (float)i / (float)j;
            printf("The result is: %.3f\n", result);
            break;

        /* factorial case */
        case 5:
            printf("Enter number to calculate factorial: ");
            scanf("%d", &num);
            result = factorial(num);
            printf("%d! is: %.0f\n", num, result);
            break;

        /* default case */
        default:
            printf("Error: invalid selection.\n");
    }

    return 0;
}