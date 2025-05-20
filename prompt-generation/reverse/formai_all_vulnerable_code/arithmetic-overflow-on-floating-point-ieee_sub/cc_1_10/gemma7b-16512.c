//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main()
{
    char operator;
    float num1, num2, result;
    int i, choice;

    printf("Enter your choice:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter two numbers: ");
            scanf("%f %f", &num1, &num2);
            result = num1 + num2;
            printf("The result is: %.2f", result);
            break;

        case 2:
            printf("Enter two numbers: ");
            scanf("%f %f", &num1, &num2);
            result = num1 - num2;
            printf("The result is: %.2f", result);
            break;

        case 3:
            printf("Enter two numbers: ");
            scanf("%f %f", &num1, &num2);
            result = num1 * num2;
            printf("The result is: %.2f", result);
            break;

        case 4:
            printf("Enter two numbers: ");
            scanf("%f %f", &num1, &num2);
            result = num1 / num2;
            printf("The result is: %.2f", result);
            break;

        default:
            printf("Invalid choice");
    }

    return 0;
}