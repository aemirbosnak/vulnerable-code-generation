//GEMINI-pro DATASET v1.0 Category: Arithmetic ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // Declare variables
    int num1, num2, result;
    char operator;

    // Prompt the user to enter two numbers and an operator
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);
    printf("Enter the operator (+, -, *, /, %): ");
    scanf(" %c", &operator);

    // Perform the arithmetic operation based on the operator entered by the user
    switch (operator) {
        case '+':
            result = num1 + num2;
            printf("The sum of %d and %d is %d\n", num1, num2, result);
            break;
        case '-':
            result = num1 - num2;
            printf("The difference of %d and %d is %d\n", num1, num2, result);
            break;
        case '*':
            result = num1 * num2;
            printf("The product of %d and %d is %d\n", num1, num2, result);
            break;
        case '/':
            if (num2 == 0) {
                printf("Error: Division by 0 is undefined\n");
            } else {
                result = num1 / num2;
                printf("The quotient of %d and %d is %d\n", num1, num2, result);
            }
            break;
        case '%':
            if (num2 == 0) {
                printf("Error: Modulus by 0 is undefined\n");
            } else {
                result = num1 % num2;
                printf("The remainder of %d divided by %d is %d\n", num1, num2, result);
            }
            break;
        default:
            printf("Error: Invalid operator entered\n");
    }

    return 0;
}