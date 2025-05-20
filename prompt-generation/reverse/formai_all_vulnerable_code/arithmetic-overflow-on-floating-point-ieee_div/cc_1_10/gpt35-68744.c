//FormAI DATASET v1.0 Category: Calculator ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int option;
    float num1, num2, result;

    while(1)
    {
        printf("\n---------- C Calculator ----------\n\n");
        printf("Choose an operation:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                printf("\nEnter two numbers to add: ");
                scanf("%f %f", &num1, &num2);
                result = num1 + num2;
                printf("Result: %.2f\n", result);
                break;

            case 2:
                printf("\nEnter two numbers to subtract: ");
                scanf("%f %f", &num1, &num2);
                result = num1 - num2;
                printf("Result: %.2f\n", result);
                break;

            case 3:
                printf("\nEnter two numbers to multiply: ");
                scanf("%f %f", &num1, &num2);
                result = num1 * num2;
                printf("Result: %.2f\n", result);
                break;

            case 4:
                printf("\nEnter two numbers to divide: ");
                scanf("%f %f", &num1, &num2);

                if(num2 == 0)
                {
                    printf("Error: division by zero\n");
                    break;
                }

                result = num1 / num2;
                printf("Result: %.2f\n", result);
                break;

            case 5:
                printf("\nThank you for using C Calculator!\n\n");
                exit(0);

            default:
                printf("\nInvalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}