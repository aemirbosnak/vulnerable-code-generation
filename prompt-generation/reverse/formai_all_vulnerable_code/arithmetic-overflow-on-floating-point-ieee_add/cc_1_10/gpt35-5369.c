//FormAI DATASET v1.0 Category: Calculator ; Style: introspective
#include <stdio.h>

// function to add two numbers
float add(float a, float b) {
    return a + b;
}

// function to subtract two numbers
float subtract(float a, float b) {
    return a - b;
}

// function to multiply two numbers
float multiply(float a, float b) {
    return a * b;
}

// function to divide two numbers
float divide(float a, float b) {
    if (b == 0) {
        printf("Error: division by zero.\n");
        return 0;
    }
    return a / b;
}

int main() {
    float num1, num2, result;
    char operator;

    printf("Welcome to my introspective calculator program!\n");

    // get input from user
    printf("Enter an operator (+, -, *, /): ");
    scanf("%c", &operator);

    printf("Enter two numbers: ");
    scanf("%f %f", &num1, &num2);

    // perform operation based on operator
    switch(operator) {
        case '+':
            result = add(num1, num2);
            printf("%.2f + %.2f = %.2f\n", num1, num2, result);
            break;
        case '-':
            result = subtract(num1, num2);
            printf("%.2f - %.2f = %.2f\n", num1, num2, result);
            break;
        case '*':
            result = multiply(num1, num2);
            printf("%.2f * %.2f = %.2f\n", num1, num2, result);
            break;
        case '/':
            result = divide(num1, num2);
            if (result != 0) {
                printf("%.2f / %.2f = %.2f\n", num1, num2, result);
            }
            break;
        default:
            printf("Error: invalid operator.\n");
    }

    printf("Thank you for using my introspective calculator program!\n");

    return 0;
}