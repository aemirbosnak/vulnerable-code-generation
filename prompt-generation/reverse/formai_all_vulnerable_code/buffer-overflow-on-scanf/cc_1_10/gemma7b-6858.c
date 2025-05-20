//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int choice, num1, num2, operator;
    float result;

    // Shape-shifting menu
    printf("------------------------------------------------------------------------\n");
    printf("   /|\t\t\t\t\t\t\t\t\t\t/|\n");
    printf("  || \t\t\t\t\t\t\t\t\t|| |\n");
    printf("  \__) \t\t\t\t\t\t\t\t\__) |\n");
    printf("------------------------------------------------------------------------\n");

    // Select operator
    printf("Enter operator (+, -, *, /, %): ");
    scanf("%c", &operator);

    // Enter numbers
    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    // Calculate result
    switch (operator)
    {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            result = (float)num1 / num2;
            break;
        case '%':
            result = num1 % num2;
            break;
        default:
            printf("Invalid operator.\n");
            return 1;
    }

    // Display result
    printf("The result is: %.2f\n", result);

    return 0;
}