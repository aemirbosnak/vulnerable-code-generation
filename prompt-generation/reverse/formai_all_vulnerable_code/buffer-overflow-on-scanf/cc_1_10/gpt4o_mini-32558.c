//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void printFibVisual(int n) {
    // Initial Fibonacci sequence variables
    unsigned long long fib1 = 0, fib2 = 1, nextFib;
    
    // Moving cursor back to the beginning of the line to clear the previous line
    printf("\033[H\033[J"); // Clear screen command
    printf("Fibonacci Sequence Visualizer\n");
    printf("===============================\n");
    
    for (int i = 0; i < n; i++) {
        // Calculate next Fibonacci number
        if (i <= 1) {
            nextFib = i; // First two Fibonacci numbers are defined
        } else {
            nextFib = fib1 + fib2;
            fib1 = fib2; // Shift values for next iteration
            fib2 = nextFib;
        }

        // Visual representation: Print the number with a bar representation
        printf("%-3d: ", nextFib);
        int length = nextFib / 1000; // Scale down the number for visual representation
        for (int j = 0; j < length; j++) {
            printf("=");
        }
        printf(" (%llu)\n", nextFib);
        
        // Introduce a slight delay for better readability
        usleep(500000); // Delay in microseconds (0.5 seconds)
    }
}

int main() {
    int n;

    printf("Enter the number of terms in Fibonacci sequence to visualize: ");
    // Get the number of terms from the user
    if (scanf("%d", &n) != 1 || n < 1) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }
    
    // Start visualizing the Fibonacci sequence
    printFibVisual(n);
    
    printf("\nFibonacci visualization complete!\n");
    return 0;
}