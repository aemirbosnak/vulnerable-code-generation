//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159

int main()
{
    int num1, num2, choice;
    float result;

    printf("Welcome to the Scientific Calculator!\n");
    printf("Please enter two numbers: ");

    scanf("%d %d", &num1, &num2);

    printf("Please select an operation: \n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exponentiation\n");
    printf("6. Square Root\n");
    printf("7. Pi (π)\n");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            result = num1 + num2;
            break;
        case 2:
            result = num1 - num2;
            break;
        case 3:
            result = num1 * num2;
            break;
        case 4:
            result = num1 / num2;
            break;
        case 5:
            result = num1 ^ num2;
            break;
        case 6:
            result = sqrt(num1);
            break;
        case 7:
            result = PI;
            break;
        default:
            printf("Invalid input. Please try again.\n");
    }

    printf("The result is: %.2f\n", result);

    return 0;
}