//Gemma-7B DATASET v1.0 Category: Arithmetic ; Style: futuristic
// Future-Tech Arithmetic Calculator

#include <stdio.h>
#include <stdlib.h>

void main()
{
    int num1, num2, choice;

    // Interface glow-up
    system("clear");
    printf("\n");
    printf("Welcome to the Future-Tech Arithmetic Calculator!\n");
    printf("----------------------------------------\n");

    // Menu selection
    printf("Please select an option:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Data gathering
    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Calculation
    switch (choice)
    {
        case 1:
            printf("The sum of %d and %d is: %d\n", num1, num2, num1 + num2);
            break;
        case 2:
            printf("The difference of %d and %d is: %d\n", num1, num2, num1 - num2);
            break;
        case 3:
            printf("The product of %d and %d is: %d\n", num1, num2, num1 * num2);
            break;
        case 4:
            if (num2 == 0)
            {
                printf("Cannot divide by zero!\n");
            }
            else
            {
                printf("The quotient of %d and %d is: %d\n", num1, num2, num1 / num2);
            }
            break;
        default:
            printf("Invalid selection!\n");
    }

    // Ending glow-down
    printf("Thank you for using the Future-Tech Arithmetic Calculator!\n");
    printf("----------------------------------------\n");
    system("pause");
}