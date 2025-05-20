//FormAI DATASET v1.0 Category: Calculator ; Style: minimalist
#include <stdio.h>

int main()
{
    int num1, num2, choice, result;

    printf("Calculator\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > 4)
    {
        printf("Invalid choice. Exiting...\n");
        return 0;
    }

    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    switch (choice)
    {
        case 1:
            result = num1 + num2;
            printf("%d + %d = %d", num1, num2, result);
            break;
        case 2:
            result = num1 - num2;
            printf("%d - %d = %d", num1, num2, result);
            break;
        case 3:
            result = num1 * num2;
            printf("%d * %d = %d", num1, num2, result);
            break;
        case 4:
            if (num2 == 0)
            {
                printf("Division by zero error. Exiting...\n");
                return 0;
            }
            result = num1 / num2;
            printf("%d / %d = %d", num1, num2, result);
            break;
    }

    return 0;
}