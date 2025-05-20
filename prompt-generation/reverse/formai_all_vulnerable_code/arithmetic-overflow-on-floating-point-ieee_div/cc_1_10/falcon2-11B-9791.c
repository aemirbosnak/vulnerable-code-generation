//Falcon2-11B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double num1, num2, result;
    int choice;

    printf("Welcome to the Scientific Calculator!\n");
    printf("Select an operation:\n1. Add\n2. Subtract\n3. Multiply\n4. Divide\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Enter the first number: ");
            scanf("%lf", &num1);
            printf("Enter the second number: ");
            scanf("%lf", &num2);
            result = num1 + num2;
            printf("Result: %lf\n", result);
            break;

        case 2:
            printf("Enter the first number: ");
            scanf("%lf", &num1);
            printf("Enter the second number: ");
            scanf("%lf", &num2);
            result = num1 - num2;
            printf("Result: %lf\n", result);
            break;

        case 3:
            printf("Enter the first number: ");
            scanf("%lf", &num1);
            printf("Enter the second number: ");
            scanf("%lf", &num2);
            result = num1 * num2;
            printf("Result: %lf\n", result);
            break;

        case 4:
            printf("Enter the first number: ");
            scanf("%lf", &num1);
            printf("Enter the second number: ");
            scanf("%lf", &num2);
            result = num1 / num2;
            if(num2 == 0)
            {
                printf("Error: Division by zero.\n");
            }
            else
            {
                printf("Result: %lf\n", result);
            }
            break;

        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }

    return 0;
}