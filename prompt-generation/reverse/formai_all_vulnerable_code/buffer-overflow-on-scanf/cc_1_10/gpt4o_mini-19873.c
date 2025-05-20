//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// Function to generate and visualize Fibonacci sequence
void visualizeFibonacci(int limit) {
    long long* fib = (long long*) malloc(sizeof(long long) * limit);
    if (fib == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    // First two Fibonacci numbers
    fib[0] = 0;
    fib[1] = 1;

    // Generate Fibonacci sequence
    printf("Generating Fibonacci sequence up to the %dth term:\n\n", limit);
    
    for (int i = 2; i < limit; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    // Visualize the Fibonacci sequence in a visually appealing way
    for (int i = 0; i < limit; i++) {
        printf("Fibonacci[%d]: ", i);

        // Print the stars proportional to the Fibonacci number
        for (long long j = 0; j < fib[i] / ((i + 3) * 2); j++) {
            printf("*");
        }

        // Align the output for clarity
        printf(" (%lld)\n", fib[i]);
        usleep(500000); // Pause for half a second for better visualization
    }

    // Free allocated memory
    free(fib);
}

// Main function to execute the program
int main() {
    int terms;

    printf("Welcome to the Fibonacci Sequence Visualizer!\n");
    printf("Enter the number of terms you want to visualize (greater than 2): ");
    
    // Ensure the user inputs a valid number
    while (1) {
        scanf("%d", &terms);
        if (terms > 2) break;
        printf("Please enter a number greater than 2: ");
    }

    // Call the visualization function
    visualizeFibonacci(terms);

    printf("\nThank you for using the Fibonacci Sequence Visualizer!\n");
    return 0;
}