//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Function to generate Fibonacci sequence
void generate_fibonacci(int n, long long *fib) {
    if (n >= 1) fib[0] = 0;
    if (n >= 2) fib[1] = 1;
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

// Function to visualize Fibonacci sequence
void visualize_fibonacci(int n, long long *fib) {
    // Create a terminal friendly visualization
    printf("\nFibonacci Sequence Visualization:\n");
    for (int i = 0; i < n; i++) {
        printf("%lld: ", fib[i]);
        for (long long j = 0; j < fib[i]; j+=1000000) {
            // Adapt to avoid terminal overflow
            printf("*");
            fflush(stdout);
            usleep(10); // Speed control: slows down the printing slightly
        }
        printf("\n");
    }
}

// Main function
int main() {
    int n;

    // Get user input
    printf("Enter the number of Fibonacci numbers to generate: ");
    scanf("%d", &n);

    // Allocate memory for Fibonacci numbers
    long long *fib = (long long *)malloc(n * sizeof(long long));
    if (fib == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return EXIT_FAILURE;
    }

    // Generate the Fibonacci sequence
    generate_fibonacci(n, fib);

    // Visualize the Fibonacci sequence
    visualize_fibonacci(n, fib);

    // Clean up and exit
    free(fib);
    printf("\n\nThanks for visualizing the Fibonacci Sequence!\n");
    return EXIT_SUCCESS;
}