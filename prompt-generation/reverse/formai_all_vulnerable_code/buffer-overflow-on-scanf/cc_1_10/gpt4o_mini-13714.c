//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 20
#define MAX_WIDTH 50

// Function prototypes
void generateFibonacci(int n, long long fib[]);
void visualizeFibonacci(int n, long long fib[]);

int main() {
    long long fib[MAX_TERMS];
    int n;

    printf("Enter the number of Fibonacci terms to visualize (up to %d): ", MAX_TERMS);
    scanf("%d", &n);

    if (n < 1 || n > MAX_TERMS) {
        printf("Please enter a number between 1 and %d.\n", MAX_TERMS);
        return 1;
    }

    generateFibonacci(n, fib);
    visualizeFibonacci(n, fib);

    return 0;
}

// Function to generate the Fibonacci sequence
void generateFibonacci(int n, long long fib[]) {
    fib[0] = 0; // First Fibonacci term
    fib[1] = 1; // Second Fibonacci term
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2]; // Next term is the sum of the previous two
    }
}

// Function to visualize the Fibonacci sequence
void visualizeFibonacci(int n, long long fib[]) {
    printf("\nFibonacci Sequence Visualization (up to term %d):\n", n);
    for (int i = 0; i < n; i++) {
        // Normalize the output size
        int width = (fib[i] > MAX_WIDTH) ? MAX_WIDTH : fib[i];
        printf("%2d: ", i);
        for (int j = 0; j < width; j++) {
            putchar('*'); // Print asterisks for each unit of Fibonacci number
        }
        printf(" (%lld)\n", fib[i]); // Display the actual Fibonacci number alongside
    }
}