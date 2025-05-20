//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: modular
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
        printf("Error: Division by zero is not allowed.\n");
        exit(1);
    }
    return a / b;
}

// Function to calculate the square of a number
int square(int a) {
    return a * a;
}

// Function to calculate the square root of a number
int sqrt(int a) {
    if (a < 0) {
        printf("Error: Square root of negative number is not allowed.\n");
        exit(1);
    }
    return sqrt(a);
}

// Function to calculate the factorial of a number
int factorial(int a) {
    int result = 1;
    for (int i = 1; i <= a; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int num1, num2, result;

    // Addition
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);
    result = add(num1, num2);
    printf("Result: %d\n", result);

    // Subtraction
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);
    result = subtract(num1, num2);
    printf("Result: %d\n", result);

    // Multiplication
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);
    result = multiply(num1, num2);
    printf("Result: %d\n", result);

    // Division
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);
    result = divide(num1, num2);
    printf("Result: %d\n", result);

    // Square
    printf("Enter a number: ");
    scanf("%d", &num1);
    result = square(num1);
    printf("Result: %d\n", result);

    // Square root
    printf("Enter a number: ");
    scanf("%d", &num1);
    result = sqrt(num1);
    printf("Result: %d\n", result);

    // Factorial
    printf("Enter a number: ");
    scanf("%d", &num1);
    result = factorial(num1);
    printf("Result: %d\n", result);

    return 0;
}