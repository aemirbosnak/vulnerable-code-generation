//Code Llama-13B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Ken Thompson
/*
 * Scientific Calculator Implementation in C
 *
 * This program implements a simple scientific calculator in C.
 * It allows the user to perform basic arithmetic operations,
 * as well as trigonometric and exponential functions.
 */

#include <stdio.h>
#include <math.h>

int main() {
    char operation;
    double num1, num2;

    printf("Welcome to the Scientific Calculator!\n");

    // Get the first number
    printf("Enter the first number: ");
    scanf("%lf", &num1);

    // Get the operation
    printf("Enter the operation (+, -, *, /, sin, cos, tan, exp): ");
    scanf(" %c", &operation);

    // Get the second number
    printf("Enter the second number: ");
    scanf("%lf", &num2);

    // Perform the operation
    switch (operation) {
        case '+':
            printf("The result is: %f\n", num1 + num2);
            break;
        case '-':
            printf("The result is: %f\n", num1 - num2);
            break;
        case '*':
            printf("The result is: %f\n", num1 * num2);
            break;
        case '/':
            printf("The result is: %f\n", num1 / num2);
            break;
        case 's':
            printf("The result is: %f\n", sin(num1));
            break;
        case 'c':
            printf("The result is: %f\n", cos(num1));
            break;
        case 't':
            printf("The result is: %f\n", tan(num1));
            break;
        case 'e':
            printf("The result is: %f\n", exp(num1));
            break;
        default:
            printf("Invalid operation.\n");
            break;
    }

    return 0;
}