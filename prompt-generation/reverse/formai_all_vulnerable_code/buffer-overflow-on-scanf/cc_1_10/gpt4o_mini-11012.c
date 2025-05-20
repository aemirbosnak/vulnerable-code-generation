//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: introspective
#include <stdio.h>

// Function declarations
int factorial(int n);
int fibonacci(int n);
void introspectFactorial(int n);
void introspectFibonacci(int n);
void printBacktrace(const char *funcName, int n);

// Main function
int main() {
    int num;

    // User input
    printf("Enter a non-negative integer to compute factorial and Fibonacci: ");
    scanf("%d", &num);

    if(num < 0) {
        printf("Please enter a non-negative integer.\n");
        return 1;
    }

    // Factorial Computation
    printf("\n--- Factorial Computation ---\n");
    introspectFactorial(num);

    // Fibonacci Computation
    printf("\n--- Fibonacci Computation ---\n");
    introspectFibonacci(num);

    return 0;
}

// Factorial function: computes factorial of a number
int factorial(int n) {
    printBacktrace("factorial", n);
    if (n == 0 || n == 1) return 1; // Base case
    return n * factorial(n - 1);   // Recursive case
}

// Fibonacci function: computes Fibonacci of a number
int fibonacci(int n) {
    printBacktrace("fibonacci", n);
    if (n == 0) return 0;           // Base case
    if (n == 1) return 1;           // Base case
    return fibonacci(n - 1) + fibonacci(n - 2); // Recursive case
}

// Function to introspectively showcase Factorial computation
void introspectFactorial(int n) {
    printf("Calculating Factorial of %d:\n", n);
    int result = factorial(n);
    printf("Factorial of %d is %d\n", n, result);
}

// Function to introspectively showcase Fibonacci computation
void introspectFibonacci(int n) {
    printf("Calculating Fibonacci of %d:\n", n);
    int result = fibonacci(n);
    printf("Fibonacci of %d is %d\n", n, result);
}

// Function to print the recursion backtrace
void printBacktrace(const char *funcName, int n) {
    printf("Entering %s(%d)\n", funcName, n);
}