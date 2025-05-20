//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 10

typedef struct Calculator {
    int num1;
    int num2;
    char operator;
} Calculator;

int main()
{
    Calculator calc;
    char input;

    printf("Welcome to the Grand Calculator of Old!\n");

    // Get the first number
    printf("Enter the first number: ");
    scanf("%d", &calc.num1);

    // Get the operator
    printf("Enter the operator (+, -, *, /): ");
    scanf(" %c", &calc.operator);

    // Get the second number
    printf("Enter the second number: ");
    scanf("%d", &calc.num2);

    // Calculate the result
    switch (calc.operator) {
        case '+':
            calc.num1 += calc.num2;
            break;
        case '-':
            calc.num1 -= calc.num2;
            break;
        case '*':
            if (calc.num2 == 0) {
                printf("Error: Cannot divide by zero.\n");
            } else {
                calc.num1 /= calc.num2;
            }
            break;
        case '/':
            if (calc.num2 == 0) {
                printf("Error: Cannot divide by zero.\n");
            } else {
                calc.num1 *= calc.num2;
            }
            break;
        default:
            printf("Error: Invalid operator.\n");
    }

    // Display the result
    printf("The result is: %d\n", calc.num1);

    return 0;
}