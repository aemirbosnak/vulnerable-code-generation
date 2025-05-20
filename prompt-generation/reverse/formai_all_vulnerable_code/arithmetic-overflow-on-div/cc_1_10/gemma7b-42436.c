//Gemma-7B DATASET v1.0 Category: Arithmetic ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2, sum, choice;

    printf("Welcome to the Arithmetic Game!\n");
    printf("Please enter two numbers: ");

    scanf("%d %d", &num1, &num2);

    printf("What operation do you want to perform?\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            sum = num1 + num2;
            printf("The sum of the two numbers is: %d\n", sum);
            break;

        case 2:
            sum = num1 - num2;
            printf("The difference of the two numbers is: %d\n", sum);
            break;

        case 3:
            sum = num1 * num2;
            printf("The product of the two numbers is: %d\n", sum);
            break;

        case 4:
            if (num2 == 0)
            {
                printf("Cannot divide by zero.\n");
            }
            else
            {
                sum = num1 / num2;
                printf("The quotient of the two numbers is: %d\n", sum);
            }
            break;

        default:
            printf("Invalid choice.\n");
    }

    return 0;
}