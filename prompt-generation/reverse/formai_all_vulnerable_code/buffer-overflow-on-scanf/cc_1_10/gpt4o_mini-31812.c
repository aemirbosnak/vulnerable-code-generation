//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 20

// Function prototypes
void calculateFibonacci(int n, long long fib[]);
void printFibonacciVisual(long long fib[], int n);

int main() {
    int n;
    long long fib[MAX_TERMS];

    // Prompt user for the number of terms
    printf("Enter the number of terms for the Fibonacci sequence (1 to %d): ", MAX_TERMS);
    scanf("%d", &n);

    // Check for valid input
    if (n < 1 || n > MAX_TERMS) {
        printf("Please enter a valid number between 1 and %d.\n", MAX_TERMS);
        return 1;
    }

    // Calculate Fibonacci sequence
    calculateFibonacci(n, fib);

    // Display Fibonacci sequence visually
    printFibonacciVisual(fib, n);

    return 0;
}

// Function to calculate Fibonacci numbers
void calculateFibonacci(int n, long long fib[]) {
    fib[0] = 0; // First Fibonacci number
    if (n > 1) {
        fib[1] = 1; // Second Fibonacci number
    }

    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2]; // Fibonacci formula
    }
}

// Function to print Fibonacci numbers visually
void printFibonacciVisual(long long fib[], int n) {
    printf("\nFibonacci Sequence Visualizer\n");
    printf("===============================\n");
    printf("Index\tValue\tVisualization\n");
    printf("-------------------------------\n");
    
    for (int i = 0; i < n; i++) {
        printf("%-5d\t%-5lld\t", i, fib[i]);
        
        // Visualize each Fibonacci number using '*' characters
        for (long long j = 0; j < fib[i]; j++) {
            if (j % 10 == 0 && j != 0) {
                printf("|"); // Create bars for every 10
            }
            printf("*");
        }
        printf("\n");
    }
    
    printf("===============================\n");
    printf("End of Visualization\n");
}