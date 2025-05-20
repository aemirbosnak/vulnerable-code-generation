//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBER 999

void display_menu()
{
    printf("\nWelcome to the Mighty Calculator of King Arthur!");
    printf("\nPlease select an option:");
    printf("\n1. Addition");
    printf("\n2. Subtraction");
    printf("\n3. Multiplication");
    printf("\n4. Division");
    printf("\n5. Square Root");
    printf("\n6. Exit");
    printf("\nEnter your choice: ");
}

int main()
{
    int choice, num1, num2;
    float result;

    display_menu();
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter the first number: ");
            scanf("%d", &num1);
            printf("Enter the second number: ");
            scanf("%d", &num2);
            result = num1 + num2;
            printf("The result is: %d\n", result);
            break;

        case 2:
            printf("Enter the first number: ");
            scanf("%d", &num1);
            printf("Enter the second number: ");
            scanf("%d", &num2);
            result = num1 - num2;
            printf("The result is: %d\n", result);
            break;

        case 3:
            printf("Enter the first number: ");
            scanf("%d", &num1);
            printf("Enter the second number: ");
            scanf("%d", &num2);
            result = num1 * num2;
            printf("The result is: %d\n", result);
            break;

        case 4:
            printf("Enter the first number: ");
            scanf("%d", &num1);
            printf("Enter the second number: ");
            scanf("%d", &num2);
            result = (float)num1 / num2;
            printf("The result is: %.2f\n", result);
            break;

        case 5:
            printf("Enter the number: ");
            scanf("%d", &num1);
            result = sqrt(num1);
            printf("The square root is: %.2f\n", result);
            break;

        case 6:
            printf("Thank you for using the Mighty Calculator of King Arthur! Farewell!");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
    }

    return 0;
}