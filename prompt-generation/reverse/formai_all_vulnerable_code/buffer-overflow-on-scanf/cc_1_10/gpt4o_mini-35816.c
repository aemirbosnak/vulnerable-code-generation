//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: active
#include <stdio.h>

// Function to calculate Fibonacci number using recursion
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Function to print the Fibonacci numbers and its triangle representation
void printFibonacciTriangle(int n) {
    // Print Fibonacci numbers
    printf("Fibonacci sequence up to term %d:\n", n);
    for (int i = 0; i < n; i++) {
        int fib = fibonacci(i);
        printf("%d ", fib); // Print Fibonacci number
    }
    printf("\n\n");

    // Print triangle representation of Fibonacci numbers
    printf("Triangle representation of Fibonacci numbers:\n");
    for (int i = 0; i < n; i++) {
        int fib = fibonacci(i);
        for (int j = 0; j < i; j++) {
            printf(" ");
        }
        printf("%d\n", fib); // Print Fibonacci number with indentation
    }
}

// Main function
int main() {
    int terms;

    // Ask user for number of terms
    printf("Enter the number of Fibonacci terms to generate: ");
    scanf("%d", &terms);

    // Validate user input
    if (terms < 0) {
        printf("Please enter a non-negative integer.\n");
        return 1; // Exit with error code
    }

    // Print Fibonacci numbers and their triangle representation
    printFibonacciTriangle(terms);

    return 0; // Exit successfully
}