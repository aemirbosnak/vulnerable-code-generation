//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

void printFibonacci(int n);
void drawLine(char ch, int count);

int main() {
    int n;

    printf("Welcome to the Fibonacci Sequence Visualizer!\n");
    printf("Enter the number of Fibonacci terms you want to visualize: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive integer greater than zero.\n");
        return 1;
    }

    printf("\nGenerating Fibonacci sequence for %d terms:\n", n);
    printFibonacci(n);

    return 0;
}

void printFibonacci(int n) {
    long long int fib1 = 0, fib2 = 1; // Initialize first two Fibonacci numbers
    long long int nextFib;

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            printf("Fibonacci term %d: %lld\n", i + 1, fib1);
            drawLine('*', fib1); // Visualization
        } else if (i == 1) {
            printf("Fibonacci term %d: %lld\n", i + 1, fib2);
            drawLine('*', fib2); // Visualization
        } else {
            nextFib = fib1 + fib2; // Calculate next Fibonacci number
            printf("Fibonacci term %d: %lld\n", i + 1, nextFib);
            drawLine('*', nextFib); // Visualization

            fib1 = fib2; // Shift for next term
            fib2 = nextFib; // Shift for next term
        }
    }

    printf("\nVisualizing the Fibonacci sequence done!\n");
}

void drawLine(char ch, int count) {
    if (count == 0)
        printf("[ ]\n"); // For 0, visualize as empty box
    else {
        printf("[");
        for (int j = 0; j < count; j++) {
            putchar(ch); // Draw the line with 'ch'
        }
        printf("]\n"); // Close the ASCII representation
    }
}