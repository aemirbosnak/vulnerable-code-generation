//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>

int main()
{
    int choice;
    char ch;
    float num1, num2, result;
    printf("\nEnter 1 for Addition\n");
    printf("Enter 2 for Subtraction\n");
    printf("Enter 3 for Multiplication\n");
    printf("Enter 4 for Division\n");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
            printf("\nEnter the first number:");
            scanf("%f", &num1);
            printf("\nEnter the second number:");
            scanf("%f", &num2);
            result = num1 + num2;
            printf("\nThe result is: %f", result);
            break;
        case 2:
            printf("\nEnter the first number:");
            scanf("%f", &num1);
            printf("\nEnter the second number:");
            scanf("%f", &num2);
            result = num1 - num2;
            printf("\nThe result is: %f", result);
            break;
        case 3:
            printf("\nEnter the first number:");
            scanf("%f", &num1);
            printf("\nEnter the second number:");
            scanf("%f", &num2);
            result = num1 * num2;
            printf("\nThe result is: %f", result);
            break;
        case 4:
            printf("\nEnter the first number:");
            scanf("%f", &num1);
            printf("\nEnter the second number:");
            scanf("%f", &num2);
            if(num2!= 0)
            {
                result = num1 / num2;
                printf("\nThe result is: %f", result);
            }
            else
            {
                printf("\nCannot divide by zero");
            }
            break;
        default:
            printf("\nInvalid choice");
    }
    printf("\nDo you want to continue? (y/n)");
    scanf("\n%c", &ch);
    if(ch == 'y')
    {
        main();
    }
    else
    {
        printf("\nExiting...");
    }
    return 0;
}