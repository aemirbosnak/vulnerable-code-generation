//FormAI DATASET v1.0 Category: Calculator ; Style: innovative
#include <stdio.h>

// Function to add two numbers
float add(float num1, float num2) {
    return (num1 + num2);
}

// Function to subtract two numbers
float subtract(float num1, float num2) {
    return (num1 - num2);
}

// Function to multiply two numbers
float multiply(float num1, float num2) {
    return (num1 * num2);
}

// Function to divide two numbers
float divide(float num1, float num2) {
    if (num2 == 0) {
        return -1;  // Returning -1 indicates an error
    } else {
        return (num1 / num2);
    }
}

int main() {
    float num1, num2;
    char operator;

    printf("Enter two numbers: ");
    scanf("%f %f", &num1, &num2);

    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &operator);

    switch (operator) {
        case '+':
            printf("%.2f + %.2f = %.2f\n", num1, num2, add(num1, num2));
            break;
        case '-':
            printf("%.2f - %.2f = %.2f\n", num1, num2, subtract(num1, num2));
            break;
        case '*':
            printf("%.2f * %.2f = %.2f\n", num1, num2, multiply(num1, num2));
            break;
        case '/':
            if (divide(num1, num2) == -1) {
                printf("Error: division by zero\n");
            } else {
                printf("%.2f / %.2f = %.2f\n", num1, num2, divide(num1, num2));
            }
            break;
        default:
            printf("Invalid operator\n");
    }

    return 0;
}