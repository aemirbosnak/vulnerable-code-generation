//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Function to generate Fibonacci numbers and save them to an array
void generate_fibonacci(int n, long long *fibonacci) {
    fibonacci[0] = 0;
    fibonacci[1] = 1;

    for (int i = 2; i < n; i++) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }
}

// Function to visualize Fibonacci numbers using ASCII art
void visualize_fibonacci(int count, long long *fibonacci) {
    printf("\nFibonacci Sequence Visualization (First %d Numbers):\n", count);
    printf("----------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("F[%d] = %lld  ", i, fibonacci[i]);
        
        // Visualizing the Fibonacci number with asterisks
        int bar_length = fibonacci[i] / 100000; // Adjust scaling for better visualization
        for (int j = 0; j < bar_length; j++) {
            printf("*");
        }
        
        printf("\n"); // New line after each bar
    }
    printf("----------------------------------------------------------\n");
}

int main() {
    int count;

    // Prompt user for the number of Fibonacci numbers to generate
    printf("Enter the number of Fibonacci numbers to visualize: ");
    scanf("%d", &count);

    // Allocate memory for the Fibonacci numbers
    long long *fibonacci = (long long *)malloc(count * sizeof(long long));
    if (fibonacci == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1; // Exit if memory allocation fails
    }

    // Generate Fibonacci numbers
    generate_fibonacci(count, fibonacci);

    // Visualize Fibonacci numbers
    visualize_fibonacci(count, fibonacci);

    // Free allocated memory
    free(fibonacci);

    return 0;
}