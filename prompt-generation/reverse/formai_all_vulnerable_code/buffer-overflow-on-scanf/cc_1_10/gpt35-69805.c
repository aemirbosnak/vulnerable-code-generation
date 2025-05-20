//FormAI DATASET v1.0 Category: Calculator ; Style: brave
#include<stdio.h>

int main()
{
    printf("Welcome to the Brave Calculator :)\n\n");
    printf("Enter your choice of operation:\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    printf("\nEnter your choice: ");

    int choice;
    scanf("%d", &choice);

    float num1, num2, output;

    switch(choice)
    {
        case 1:
            printf("\nEnter the first number: ");
            scanf("%f", &num1);
            printf("Enter the second number: ");
            scanf("%f", &num2);
            output = num1 + num2;
            printf("\n%.2f + %.2f = %.2f\n", num1, num2, output);
            break;

        case 2:
            printf("\nEnter the first number: ");
            scanf("%f", &num1);
            printf("Enter the second number: ");
            scanf("%f", &num2);
            output = num1 - num2;
            printf("\n%.2f - %.2f = %.2f\n", num1, num2, output);
            break;

        case 3:
            printf("\nEnter the first number: ");
            scanf("%f", &num1);
            printf("Enter the second number: ");
            scanf("%f", &num2);
            output = num1 * num2;
            printf("\n%.2f * %.2f = %.2f\n", num1, num2, output);
            break;

        case 4:
            printf("\nEnter the first number: ");
            scanf("%f", &num1);
            printf("Enter the second number: ");
            scanf("%f", &num2);

            if (num2 == 0)
            {
                printf("\nCannot divide by zero.\n");
            }
            else
            {
                output = num1 / num2;
                printf("\n%.2f / %.2f = %.2f\n", num1, num2, output);
            }
            break;

        default:
            printf("\nInvalid choice. Please enter a valid choice.\n");
            break;
    }

    return 0;
}