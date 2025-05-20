//FormAI DATASET v1.0 Category: Arithmetic ; Style: real-life
#include <stdio.h>

int main()
{
    int num1, num2, choice, result;

    printf("Welcome to our Arithmetic Program!\n");
    printf("Please enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    printf("\nWhat operation would you like to perform?\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
    printf("Please enter the number corresponding to the operation: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            result = num1 + num2;
            printf("\n%d + %d = %d\n", num1, num2, result);
            break;

        case 2:
            result = num1 - num2;
            printf("\n%d - %d = %d\n", num1, num2, result);
            break;

        case 3:
            result = num1 * num2;
            printf("\n%d * %d = %d\n", num1, num2, result);
            break;

        case 4:
            if(num2 == 0)
            {
                printf("\nCannot divide by zero!\n");
            }
            else
            {
                result = num1 / num2;
                printf("\n%d / %d = %d\n", num1, num2, result);
            }
            break;

        default:
            printf("\nInvalid input!");

    }

    return 0;
}