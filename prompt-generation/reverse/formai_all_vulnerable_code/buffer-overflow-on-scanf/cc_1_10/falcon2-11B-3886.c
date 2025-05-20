//Falcon2-11B DATASET v1.0 Category: Warehouse Management System ; Style: mathematical
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
        printf("Error: Division by zero is not allowed\n");
        exit(1);
    }
    return a / b;
}

// Function to calculate the factorial of a number
int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int num1, num2;
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);
    
    int result = add(num1, num2);
    printf("Addition: %d\n", result);
    
    result = subtract(num1, num2);
    printf("Subtraction: %d\n", result);
    
    result = multiply(num1, num2);
    printf("Multiplication: %d\n", result);
    
    result = divide(num1, num2);
    printf("Division: %d\n", result);
    
    int n = 5;
    int factorial_result = factorial(n);
    printf("Factorial of %d: %d\n", n, factorial_result);
    
    return 0;
}