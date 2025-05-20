//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    int num1, num2, choice, i, j, k, result;
    char op;

    printf("Welcome to the Arithmetic Calculator!\n");
    printf("Please choose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Square root\n");
    scanf("%d", &choice);

    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);

    switch(choice)
    {
        case 1:
            result = num1 + num2;
            printf("The result is %d\n", result);
            break;
        case 2:
            result = num1 - num2;
            printf("The result is %d\n", result);
            break;
        case 3:
            result = num1 * num2;
            printf("The result is %d\n", result);
            break;
        case 4:
            if(num2 == 0)
            {
                printf("Division by zero is not allowed!\n");
            }
            else
            {
                result = num1 / num2;
                printf("The result is %d\n", result);
            }
            break;
        case 5:
            if(num1 < 0)
            {
                printf("Square root of negative number is not defined!\n");
            }
            else
            {
                result = sqrt(num1);
                printf("The result is %.2f\n", result);
            }
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}