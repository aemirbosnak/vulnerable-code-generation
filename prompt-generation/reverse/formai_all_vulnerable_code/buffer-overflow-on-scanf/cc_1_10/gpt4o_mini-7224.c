//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: multivariable
#include <stdio.h>

// Function to calculate the nth Fibonacci number using recursion
int fibonacci(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// Function to calculate the factorial of n using recursion
int factorial(int n) {
    if (n < 0) {
        return -1; // Return -1 for negative numbers to indicate error
    } else if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Function to calculate the sum of the first n natural numbers using recursion
int sum_of_natural_numbers(int n) {
    if (n < 0) {
        return 0; // Return 0 for negative numbers
    } else if (n == 0) {
        return 0;
    } else {
        return n + sum_of_natural_numbers(n - 1);
    }
}

// Main function to display results
int main() {
    int n;

    printf("Enter a non-negative integer (for Fibonacci, Factorial, Sum): ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Please enter a non-negative integer.\n");
        return 1; // Error exit code for invalid input
    }

    int fib = fibonacci(n);
    int fact = factorial(n);
    int sum = sum_of_natural_numbers(n);

    printf("Fibonacci of %d: %d\n", n, fib);
    printf("Factorial of %d: %d\n", n, fact);
    printf("Sum of first %d natural numbers: %d\n", n, sum);

    return 0; // Success exit code
}