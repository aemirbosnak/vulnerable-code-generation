//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Function to calculate and print Fibonacci sequence
void printFibonacci(int count) {
    long long* fibonacci = malloc(sizeof(long long) * count);
    if (!fibonacci) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    fibonacci[0] = 0;
    if (count > 1) {
        fibonacci[1] = 1;
    }

    printf("Fibonacci Sequence:\n");
    printf("%lld\n", fibonacci[0]);
    if (count > 1) {
        printf("%lld\n", fibonacci[1]);
    }

    // Calculate Fibonacci sequence
    for (int i = 2; i < count; i++) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
        printf("%lld\n", fibonacci[i]);
    }

    // Visualize Fibonacci
    printf("\nVisualization of Fibonacci Sequence:\n");
    for (int i = 0; i < count; i++) {
        printf("%lld: ", fibonacci[i]);

        // Draw a line proportional to the Fibonacci number
        for (long long j = 0; j < fibonacci[i]; j++) {
            if (j > 50) break; // Limit length for visualization
            printf("=");
        }
        printf("\n");
    }

    free(fibonacci);
}

int main() {
    int count;

    printf("Enter the number of Fibonacci numbers to visualize (e.g., 10): ");
    scanf("%d", &count);

    if (count < 1) {
        printf("Please enter a positive integer greater than 0.\n");
        return EXIT_FAILURE;
    }

    printFibonacci(count);

    return EXIT_SUCCESS;
}