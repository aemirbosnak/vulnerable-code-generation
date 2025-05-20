//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void generate_fibonacci(int n, long long *fib) {
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

void visualize_fibonacci(long long *fib, int n) {
    printf("\nFibonacci Number Visualization:\n");
    printf("------------------------------------\n");
    for (int i = 0; i < n; i++) {
        // Print each Fibonacci number with visual representation based on its value
        printf("F(%d): %lld\t", i, fib[i]);
        for (long long j = 0; j < fib[i] / 10000000; j++) {
            printf("|");
        }
        printf("\n");
        usleep(500000);  // Delay for a better visual effect
    }
    printf("------------------------------------\n");
}

int main() {
    int n;

    printf("Welcome to the Fibonacci Sequence Visualizer! 🌟\n");
    printf("How many Fibonacci numbers would you like to visualize? ");
    scanf("%d", &n);
    
    // Ensure the input is greater than 2 for visualization
    if (n < 2) {
        printf("Please enter a number greater than 2.\n");
        return 1;
    }

    // Dynamically allocate memory for Fibonacci numbers
    long long *fib = (long long *)malloc(n * sizeof(long long));
    if (fib == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    // Generate the Fibonacci sequence
    generate_fibonacci(n, fib);

    // Visualize the Fibonacci sequence
    visualize_fibonacci(fib, n);

    // Free allocated memory
    free(fib);
    printf("Thank you for using the Fibonacci Sequence Visualizer! 🌈\n");
    
    return 0;
}