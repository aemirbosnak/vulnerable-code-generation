//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Function to generate Fibonacci sequence
void generateFibonacci(int n, unsigned long long *fib) {
    if (n >= 1) {
        fib[0] = 0;
    }
    if (n >= 2) {
        fib[1] = 1;
    }
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

// Function to visualize Fibonacci sequence
void visualizeFibonacci(int n, unsigned long long *fib) {
    printf("\nFibonacci Sequence up to %d terms:\n\n", n);
    for (int i = 0; i < n; i++) {
        // Print Fibonacci number
        printf("%llu ", fib[i]);

        // Visualize Fibonacci number with ASCII representation
        for (unsigned long long j = 0; j < fib[i]; j += 1000000) {
            printf("*");
        }

        // Newline after each fibonacci number for better visualization
        printf("\n");
    }
}

// Main function
int main() {
    int n;
    printf("Welcome to the Fibonacci Sequence Visualizer!\n");
    printf("Enter the number of terms you wish to visualize (max 90): ");
    scanf("%d", &n);
    
    if (n < 1 || n > 90) {
        printf("Please enter a valid number of terms (1-90).\n");
        return 1;
    }

    // Allocate memory for Fibonacci numbers
    unsigned long long *fib = (unsigned long long *)malloc(n * sizeof(unsigned long long));
    if (fib == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Generate Fibonacci sequence
    generateFibonacci(n, fib);

    // Visualize Fibonacci sequence
    visualizeFibonacci(n, fib);

    // Free allocated memory
    free(fib);
    printf("Thank you for using the Fibonacci Sequence Visualizer!\n");
    return 0;
}