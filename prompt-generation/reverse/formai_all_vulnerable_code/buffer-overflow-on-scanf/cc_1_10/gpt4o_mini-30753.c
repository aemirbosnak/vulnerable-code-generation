//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// Function to calculate Fibonacci numbers
void generate_fibonacci(int n, long long *fib) {
    fib[0] = 0; // First Fibonacci number
    if (n > 1) {
        fib[1] = 1; // Second Fibonacci number
        for (int i = 2; i < n; i++) {
            fib[i] = fib[i-1] + fib[i-2]; // Fibonacci calculation
        }
    }
}

// Function to visualize the Fibonacci sequence
void visualize_fibonacci(int n, long long *fib) {
    printf("\nFibonacci Sequence Visualizer\n");
    printf("---------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("%3lld: ", fib[i]); // Print the Fibonacci number
        // Visualization with stars
        for (long long j = 0; j < fib[i]; j++) {
            printf("*"); // Print a star for each unit
        }
        printf("\n"); // New line after each row
    }
}

int main() {
    int n;

    printf("Enter the number of Fibonacci numbers to generate: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    long long *fib = (long long *)malloc(n * sizeof(long long));
    if (fib == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    generate_fibonacci(n, fib); // Generate Fibonacci numbers
    visualize_fibonacci(n, fib); // Visualize the sequence

    free(fib); // Free allocated memory
    return 0;
}