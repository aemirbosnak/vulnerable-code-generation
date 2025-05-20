//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void main()
{
    int num1, num2, operator, choice;
    float result;

    // Display the calculator menu
    printf("\nWelcome to the Scientific Calculator!\n");
    printf("------------------------\n");
    printf("1. Addition (+) \n");
    printf("2. Subtraction (-) \n");
    printf("3. Multiplication (*) \n");
    printf("4. Division (/)\n");
    printf("5. Square Root (√)\n");
    printf("6. Exponential (x^y)\n");
    printf("Please enter your choice: ");

    // Get the user's choice
    scanf("%d", &choice);

    // Perform the operation based on the user's choice
    switch (choice)
    {
        case 1:
            printf("Enter two numbers: ");
            scanf("%d %d", &num1, &num2);
            result = num1 + num2;
            printf("The result is: %.2f\n", result);
            break;
        case 2:
            printf("Enter two numbers: ");
            scanf("%d %d", &num1, &num2);
            result = num1 - num2;
            printf("The result is: %.2f\n", result);
            break;
        case 3:
            printf("Enter two numbers: ");
            scanf("%d %d", &num1, &num2);
            result = num1 * num2;
            printf("The result is: %.2f\n", result);
            break;
        case 4:
            printf("Enter two numbers: ");
            scanf("%d %d", &num1, &num2);
            result = (float)num1 / num2;
            printf("The result is: %.2f\n", result);
            break;
        case 5:
            printf("Enter a number: ");
            scanf("%d", &num1);
            result = sqrt(num1);
            printf("The result is: %.2f\n", result);
            break;
        case 6:
            printf("Enter two numbers: ");
            scanf("%d %d", &num1, &num2);
            result = num1 ^ num2;
            printf("The result is: %.2f\n", result);
            break;
        default:
            printf("Invalid choice\n");
    }

    // Display the end of the calculator menu
    printf("Thank you for using the Scientific Calculator!\n");
    printf("------------------------\n");
    return;
}