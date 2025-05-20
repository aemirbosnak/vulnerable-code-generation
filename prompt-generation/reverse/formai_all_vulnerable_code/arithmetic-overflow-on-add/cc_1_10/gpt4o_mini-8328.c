//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

void printFibonacci(int n) {
    // Edge case for negative input
    if (n < 0) {
        printf("Please enter a non-negative integer.\n");
        return;
    }

    // Edge case for Fibonacci of 0
    if (n == 0) {
        printf("Fibonacci: 0\n");
        return;
    }

    // Allocate an array to store Fibonacci numbers
    long long *fib = (long long *)malloc((n + 1) * sizeof(long long));
    if (fib == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    // Base cases
    fib[0] = 0;
    fib[1] = 1;
    
    // Calculate Fibonacci numbers iteratively
    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    // Print the Fibonacci series
    printf("Fibonacci Series up to %d terms:\n", n);
    for (int i = 0; i <= n; i++) {
        printf("%lld ", fib[i]);
    }
    printf("\n");

    // Free allocated memory
    free(fib);
}

int main() {
    int n;

    // Get user input
    printf("Enter the number of terms for the Fibonacci series: ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return EXIT_FAILURE;
    }

    // Call the function to print Fibonacci series
    printFibonacci(n);

    return EXIT_SUCCESS;
}