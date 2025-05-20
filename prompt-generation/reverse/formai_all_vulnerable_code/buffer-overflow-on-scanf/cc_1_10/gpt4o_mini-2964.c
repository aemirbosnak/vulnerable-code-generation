//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

void printFibonacci(int n) {
    unsigned long long int fib[n];
    fib[0] = 0;
    fib[1] = 1;

    printf("Generating Fibonacci Sequence up to %d terms:\n", n);
    printf("------------------------------------------------\n");

    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    for (int i = 0; i < n; i++) {
        printf("Fibonacci[%d] = %llu\n", i, fib[i]);
    }
}

void visualizeFibonacci(int n) {
    unsigned long long int fib[n];
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    printf("\nVisualizing Fibonacci Sequence\n");
    printf("------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("F[%d]: ", i);
        for (unsigned long long int j = 0; j < fib[i]; j += 100000) {  // Visualize using counts
            printf("*");
        }
        printf(" (%llu)\n", fib[i]);
    }
}

int main() {
    int n;
    
    printf("Welcome to the Fibonacci Sequence Visualizer!\n");
    printf("Please enter a number of terms to visualize (max 93): ");
    
    if (scanf("%d", &n) != 1 || n < 1 || n > 93) {
        fprintf(stderr, "Invalid input. Please provide a positive integer not exceeding 93.\n");
        return EXIT_FAILURE;
    }

    printf("\nThank you for contributing to this Fibonacci exploration!\n");
    printFibonacci(n);
    visualizeFibonacci(n);
    
    printf("\nThank you for using the Fibonacci Sequence Visualizer!\n");
    return EXIT_SUCCESS;
}