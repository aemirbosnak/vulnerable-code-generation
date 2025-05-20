//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Function to add two numbers
int add(int a, int b) {
    return a + b;
}

// Function to subtract two numbers
int subtract(int a, int b) {
    return a - b;
}

// Function to multiply two numbers
int multiply(int a, int b) {
    return a * b;
}

// Function to divide two numbers
int divide(int a, int b) {
    if (b == 0) {
        printf("Error: Division by zero is not allowed.\n");
        exit(1);
    }
    return a / b;
}

// Function to calculate the power of a number
int power(int a, int b) {
    int result = 1;
    for (int i = 0; i < b; i++) {
        result *= a;
    }
    return result;
}

// Function to calculate the square root of a number
double sqrt(double a) {
    return sqrt(a);
}

// Function to calculate the absolute value of a number
int abs(int a) {
    if (a < 0) {
        return -a;
    }
    return a;
}

int main() {
    int num1, num2;
    char operation;

    printf("Enter two numbers separated by space: ");
    scanf("%d %d", &num1, &num2);

    printf("Enter the operation you want to perform (+, -, *, /, p, s, a): ");
    scanf(" %c", &operation);

    int result;

    switch (operation) {
        case '+':
            result = add(num1, num2);
            break;
        case '-':
            result = subtract(num1, num2);
            break;
        case '*':
            result = multiply(num1, num2);
            break;
        case '/':
            result = divide(num1, num2);
            break;
        case 'p':
            result = power(num1, num2);
            break;
        case's':
            result = sqrt(num1);
            break;
        case 'a':
            result = abs(num1);
            break;
        default:
            printf("Invalid operation. Please enter a valid operation.\n");
            exit(1);
    }

    printf("Result: %d\n", result);

    return 0;
}