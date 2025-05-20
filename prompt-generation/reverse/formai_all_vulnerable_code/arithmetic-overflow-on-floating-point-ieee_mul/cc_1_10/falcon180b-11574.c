//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: beginner-friendly
#include <stdio.h>
#include <math.h>

int main()
{
    float num1, num2, result;
    int choice;

    printf("Enter 1 to add\n");
    printf("Enter 2 to subtract\n");
    printf("Enter 3 to multiply\n");
    printf("Enter 4 to divide\n");

    scanf("%d", &choice);

    printf("Enter two numbers:\n");
    scanf("%f %f", &num1, &num2);

    switch(choice)
    {
        case 1:
            result = num1 + num2;
            printf("Result: %f\n", result);
            break;

        case 2:
            result = num1 - num2;
            printf("Result: %f\n", result);
            break;

        case 3:
            result = num1 * num2;
            printf("Result: %f\n", result);
            break;

        case 4:
            if(num2 == 0)
            {
                printf("Cannot divide by zero.\n");
            }
            else
            {
                result = num1 / num2;
                printf("Result: %f\n", result);
            }
            break;

        default:
            printf("Invalid choice.\n");
    }

    return 0;
}