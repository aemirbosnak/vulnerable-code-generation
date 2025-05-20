//Gemma-7B DATASET v1.0 Category: Math exercise ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double x, y, z, result;
    int choice;

    printf("Enter your choice:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Square\n");
    printf("6. Cube\n");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter two numbers:");
            scanf("%lf %lf", &x, &y);
            result = x + y;
            printf("The result is: %.2lf", result);
            break;

        case 2:
            printf("Enter two numbers:");
            scanf("%lf %lf", &x, &y);
            result = x - y;
            printf("The result is: %.2lf", result);
            break;

        case 3:
            printf("Enter two numbers:");
            scanf("%lf %lf", &x, &y);
            result = x * y;
            printf("The result is: %.2lf", result);
            break;

        case 4:
            printf("Enter two numbers:");
            scanf("%lf %lf", &x, &y);
            result = x / y;
            printf("The result is: %.2lf", result);
            break;

        case 5:
            printf("Enter a number:");
            scanf("%lf", &x);
            result = x * x;
            printf("The result is: %.2lf", result);
            break;

        case 6:
            printf("Enter a number:");
            scanf("%lf", &x);
            result = x * x * x;
            printf("The result is: %.2lf", result);
            break;

        default:
            printf("Invalid choice");
    }

    return 0;
}