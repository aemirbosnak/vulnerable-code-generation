//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: grateful
#include <stdio.h>
#include <math.h>

int main()
{
    int choice;
    double num, result;

    printf("Welcome to C Scientific Calculator Implementation! \n");
    printf("Please choose an option \n");
    printf("1. Addition \n2. Subtraction \n3. Multiplication \n4. Division \n5. Sin \n6. Cos \n7. Tan \n8. Log \n");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter two numbers to add: \n");
            scanf("%lf%lf", &num, &result);
            printf("Result: %lf \n", num + result);
            break;

        case 2:
            printf("Enter two numbers to subtract: \n");
            scanf("%lf%lf", &num, &result);
            printf("Result: %lf \n", num - result);
            break;

        case 3:
            printf("Enter two numbers to multiply: \n");
            scanf("%lf%lf", &num, &result);
            printf("Result: %lf \n", num * result);
            break;

        case 4:
            printf("Enter two numbers to divide: \n");
            scanf("%lf%lf", &num, &result);
            if (result == 0)
                printf("Error! Divide by zero is not possible. \n");
            else
                printf("Result: %lf \n", num / result);
            break;

        case 5:
            printf("Enter the angle in degrees: \n");
            scanf("%lf", &num);
            result = sin(num * M_PI / 180);
            printf("Result: %lf \n", result);
            break;

        case 6:
            printf("Enter the angle in degrees: \n");
            scanf("%lf", &num);
            result = cos(num * M_PI / 180);
            printf("Result: %lf \n", result);
            break;

        case 7:
            printf("Enter the angle in degrees: \n");
            scanf("%lf", &num);
            result = tan(num * M_PI / 180);
            printf("Result: %lf \n", result);
            break;

        case 8:
            printf("Enter a number to find its natural log: \n");
            scanf("%lf", &num);
            result = log(num);
            printf("Result: %lf \n", result);
            break;

        default:
            printf("Invalid Input! \n");
    }

    return 0;
}