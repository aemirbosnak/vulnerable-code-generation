//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: safe
#include <stdio.h>
#include <stdlib.h>

void generate_fibonacci(int n, long long int *fib_sequence) {
    if (n < 1) {
        printf("Number of Fibonacci terms must be at least 1\n");
        return;
    }
    fib_sequence[0] = 0;
    if (n > 1) {
        fib_sequence[1] = 1;
    }
    for (int i = 2; i < n; i++) {
        fib_sequence[i] = fib_sequence[i - 1] + fib_sequence[i - 2];
    }
}

void print_fibonacci_visualization(int n, long long int *fib_sequence) {
    printf("\nFibonacci Sequence Visualization:\n");
    for (int i = 0; i < n; i++) {
        // Print each Fibonacci number
        printf("%lld: ", fib_sequence[i]);
        // Visualize with asterisks
        for (long long int j = 0; j < fib_sequence[i]; j += 100000) {  // Scaling for large numbers
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the number of Fibonacci terms to generate (at least 1): ");
    
    while (1) {
        if (scanf("%d", &n) != 1) {
            printf("Invalid input. Please enter a valid integer: ");
            while(getchar() != '\n'); // Clear the invalid input
            continue;
        }
        if (n < 1) {
            printf("Number must be at least 1. Please try again: ");
        } else {
            break;
        }
    }
    
    long long int *fib_sequence = malloc(n * sizeof(long long int));
    if (fib_sequence == NULL) {
        fprintf(stderr, "Memory allocation failed. Exiting...\n");
        return EXIT_FAILURE;
    }

    generate_fibonacci(n, fib_sequence);
    print_fibonacci_visualization(n, fib_sequence);

    free(fib_sequence); // Free allocated memory
    return EXIT_SUCCESS;
}