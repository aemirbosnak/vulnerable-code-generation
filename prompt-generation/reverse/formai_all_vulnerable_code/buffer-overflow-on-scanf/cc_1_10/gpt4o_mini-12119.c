//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: satisfied
#include <stdio.h>

#define MAX_TERMS 20

// Function to generate Fibonacci sequence
void generateFibonacci(int n, int fib[]) {
    fib[0] = 0;
    fib[1] = 1;
    
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

// Function to visualize the Fibonacci sequence
void visualizeFibonacci(int n, int fib[]) {
    printf("\nFibonacci Sequence (%d terms):\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", fib[i]);
    }
    printf("\n\nVisual Representation:\n");

    for (int i = 0; i < n; i++) {
        printf("Term %d: ", fib[i]);
        for (int j = 0; j < fib[i]; j++) {
            printf("█"); // Using block character to visualize
        }
        printf(" (%d)\n", fib[i]);
    }
}

// Function to print the graphical representation of Fibonacci numbers
void printGraph(int n, int fib[]) {
    for (int i = 0; i < n; i++) {
        printf("Fibonacci term %d: ", i);
        for (int j = 0; j < fib[i]; j++) {
            printf("*");
        }
        printf(" (%d)\n", fib[i]);
    }
}

int main() {
    int n; // Number of Fibonacci terms
    int fib[MAX_TERMS]; // Array to hold Fibonacci terms

    printf("Welcome to the Fibonacci Sequence Visualizer!\n");
    printf("How many terms of the Fibonacci sequence would you like to generate? (Max: %d): ", MAX_TERMS);
    
    // Input validation loop
    while (1) {
        scanf("%d", &n);
        if (n > 0 && n <= MAX_TERMS) {
            break;
        } else {
            printf("Please enter a number between 1 and %d: ", MAX_TERMS);
        }
    }

    // Generate Fibonacci sequence
    generateFibonacci(n, fib);

    // Visualize Fibonacci sequence
    visualizeFibonacci(n, fib);

    // Print a graph representation
    printf("\nGraphical Representation:\n");
    printGraph(n, fib);

    printf("\nThank you for using the Fibonacci Sequence Visualizer! Goodbye!\n");
    
    return 0;
}