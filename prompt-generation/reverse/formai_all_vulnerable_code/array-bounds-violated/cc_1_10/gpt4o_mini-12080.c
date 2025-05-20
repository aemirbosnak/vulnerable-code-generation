//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

void visualizeFibonacci(int n);
void printFibonacciTerms(int term, int value);

int main() {
    int n;

    printf("Welcome to the Fibonacci Sequence Visualizer!\n");
    printf("How many terms of the Fibonacci sequence would you like to visualize? ");
    scanf("%d", &n);

    // Input validation
    if (n <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    visualizeFibonacci(n);

    printf("Thank you for using the Fibonacci Sequence Visualizer!\n");
    return 0;
}

// Function to visualize the Fibonacci series
void visualizeFibonacci(int n) {
    int fib[n];
    fib[0] = 0;
    fib[1] = 1;

    // Calculate Fibonacci numbers
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    // Print the Fibonacci numbers with visual representation
    for (int i = 0; i < n; i++) {
        printFibonacciTerms(i + 1, fib[i]);
    }
}

// Function to print individual Fibonacci terms visually
void printFibonacciTerms(int term, int value) {
    printf("Term %2d: %d ", term, value);
    for (int j = 0; j < value; j++) {
        putchar('*');
    }
    putchar('\n');
}