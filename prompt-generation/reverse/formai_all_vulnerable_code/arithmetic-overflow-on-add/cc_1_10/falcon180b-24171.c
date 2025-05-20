//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Function to add two integers
int add(int a, int b) {
    return a + b;
}

// Function to subtract two integers
int subtract(int a, int b) {
    return a - b;
}

// Function to multiply two integers
int multiply(int a, int b) {
    return a * b;
}

// Function to divide two integers
int divide(int a, int b) {
    if (b == 0) {
        printf("Error: Division by zero!\n");
        exit(1);
    }
    return a / b;
}

// Function to calculate the factorial of a number
int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int num1, num2;
    char operator;

    // Get user input for two integers and an operator
    printf("Enter two integers separated by an operator (+, -, *, /):\n");
    scanf("%d %c %d", &num1, &operator, &num2);

    // Perform arithmetic operation based on user input
    switch (operator) {
        case '+':
            printf("Result: %d\n", add(num1, num2));
            break;
        case '-':
            printf("Result: %d\n", subtract(num1, num2));
            break;
        case '*':
            printf("Result: %d\n", multiply(num1, num2));
            break;
        case '/':
            printf("Result: %d\n", divide(num1, num2));
            break;
        default:
            printf("Error: Invalid operator!\n");
            break;
    }

    // Calculate the factorial of a number
    int n;
    printf("Enter a non-negative integer to calculate its factorial:\n");
    scanf("%d", &n);
    printf("Factorial of %d: %d\n", n, factorial(n));

    return 0;
}