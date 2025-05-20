//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

void generate_fibonacci(int n, long long *fib) {
    if (n >= 1) fib[0] = 0;
    if (n >= 2) fib[1] = 1;
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

void visualize_fibonacci(int n, long long *fib) {
    printf("\nFibonacci Sequence Visualization:\n");
    for (int i = 0; i < n; i++) {
        printf("%2d: %lld ", i, fib[i]);
        // Visualize Fibonacci numbers with asterisks
        for (long long j = 0; j < fib[i] / 100000; j++) { // Adjust for visibility
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int n;

    // Peaceful introduction
    printf("Welcome to the Fibonacci Sequence Visualizer.\n");
    printf("Explore the beauty of Fibonacci numbers.\n");
    printf("How many Fibonacci numbers would you like to generate? ");
    
    // Input validation
    while (1) {
        if (scanf("%d", &n) != 1 || n <= 0) {
            printf("Please enter a positive integer: ");
            while(getchar() != '\n'); // clear the buffer
        } else {
            break;
        }
    }

    // Allocate memory for Fibonacci numbers
    long long *fib = (long long *)malloc(n * sizeof(long long));
    if (fib == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Generate the Fibonacci sequence
    generate_fibonacci(n, fib);

    // Visualize the Fibonacci sequence
    visualize_fibonacci(n, fib);

    // Clean up and exit
    free(fib);
    printf("Thank you for exploring the Fibonacci sequence. Have a peaceful day!\n");
    return 0;
}