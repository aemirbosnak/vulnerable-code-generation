//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Function to generate Fibonacci Sequence
void generateFibonacci(int n, int *fibSequence) {
    fibSequence[0] = 0;
    fibSequence[1] = 1;
    for (int i = 2; i < n; i++) {
        fibSequence[i] = fibSequence[i - 1] + fibSequence[i - 2];
    }
}

// Function to visualize the Fibonacci Sequence
void visualizeFibonacci(int n, int *fibSequence) {
    printf("\nFibonacci Sequence:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", fibSequence[i]);
        for (int j = 0; j < fibSequence[i]; j++) {
            printf("*");
        }
        printf("\n");
        sleep(1); // Delay for visualization effect
    }
}

int main() {
    int n; // Number of Fibonacci numbers to generate
    printf("Enter the number of Fibonacci numbers to visualize: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }
    
    // Dynamically allocate memory for Fibonacci sequence
    int *fibSequence = (int *)malloc(n * sizeof(int));
    if (fibSequence == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Generate Fibonacci numbers
    generateFibonacci(n, fibSequence);

    // Visualize Fibonacci sequence
    visualizeFibonacci(n, fibSequence);

    // Free the allocated memory
    free(fibSequence);
    return 0;
}