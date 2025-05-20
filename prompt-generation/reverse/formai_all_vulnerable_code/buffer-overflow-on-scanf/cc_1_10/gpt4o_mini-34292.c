//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Function to generate Fibonacci numbers and return the count
void generateFibonacci(int n, long long *fibonacci) {
    if (n > 0) {
        fibonacci[0] = 0; // First Fibonacci number
    }

    if (n > 1) {
        fibonacci[1] = 1; // Second Fibonacci number
    }

    for (int i = 2; i < n; i++) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2]; // Generate the sequence
    }
}

// Function to print the Fibonacci numbers with their visual representation
void printFibonacciVisualizer(long long *fibonacci, int n) {
    printf("Fibonacci Sequence Visualizer:\n");
    printf("Index\tValue\tVisualization\n");
    printf("------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%lld\t", i, fibonacci[i]);

        // Visualize the Fibonacci number using asterisks
        for (long long j = 0; j < fibonacci[i]; j++) {
            if (j < 50) { // Limit the number of asterisks to avoid excessive output
                printf("*");
            } else {
                break; // Break if the limit is reached
            }
        }
        
        // Add a newline for the next Fibonacci number
        printf("\n");
    }
}

int main() {
    int n;

    // Ask the user for the number of Fibonacci terms
    printf("Enter the number of Fibonacci terms to generate: ");
    scanf("%d", &n);

    // Validate the input
    if (n <= 0) {
        printf("Please enter a positive integer greater than 0.\n");
        return 1;
    }

    // Allocate memory for the Fibonacci numbers
    long long *fibonacci = (long long *)malloc(n * sizeof(long long));
    if (fibonacci == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Generate the Fibonacci sequence
    generateFibonacci(n, fibonacci);

    // Visualize the Fibonacci sequence
    printFibonacciVisualizer(fibonacci, n);

    // Free allocated memory
    free(fibonacci);

    return 0;
}