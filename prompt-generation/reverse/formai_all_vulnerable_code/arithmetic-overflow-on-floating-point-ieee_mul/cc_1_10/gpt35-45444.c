//FormAI DATASET v1.0 Category: Calculator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Welcome to the Cheerful Calculator!

int main()
{
    char operator;
    float num1, num2;

    printf("Welcome to the Cheerful Calculator!\n\n");

    printf("Enter the operator (+, -, *, /): ");
    scanf("%c", &operator);

    printf("Enter the first number: ");
    scanf("%f", &num1);

    printf("Enter the second number: ");
    scanf("%f", &num2);

    switch(operator)
    {
        case '+':
        printf("%.2f + %.2f = %.2f", num1, num2, num1 + num2);
        break;

        case '-':
        printf("%.2f - %.2f = %.2f", num1, num2, num1 - num2);
        break;

        case '*':
        printf("%.2f * %.2f = %.2f", num1, num2, num1 * num2);
        break;

        case '/':
        if(num2 == 0)
        {
            printf("Error: Cannot divide by zero!");
        }
        else
        {
            printf("%.2f / %.2f = %.2f", num1, num2, num1 / num2);
        }
        break;

        default:
        printf("Error: Invalid operator");
    }

    printf("\n\nThank you for using the Cheerful Calculator! Have a nice day!");

    return 0;
}