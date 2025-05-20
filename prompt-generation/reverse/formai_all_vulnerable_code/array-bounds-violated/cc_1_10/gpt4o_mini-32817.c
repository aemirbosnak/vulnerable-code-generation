//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: introspective
#include <stdio.h>

// Function prototypes for modularity and clarity.
void generateFibonacci(int n);
void printFibonacciVisual(int num, int index);

// Main function that initiates the program.
int main() {
    int count;

    printf("Welcome to the Fibonacci Sequence Visualizer!\n");
    printf("How many Fibonacci numbers would you like to visualize? ");
    scanf("%d", &count);

    if (count <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    printf("\nGenerating and visualizing the first %d numbers of the Fibonacci sequence:\n", count);
    generateFibonacci(count);

    printf("\nThank you for using the Fibonacci Sequence Visualizer!\n");
    return 0;
}

// Function to generate Fibonacci numbers and visualize them.
void generateFibonacci(int n) {
    unsigned long long fib[n]; // Array to store Fibonacci numbers.
    fib[0] = 0;                // Starting point of the Fibonacci sequence.
    fib[1] = 1;                // Next number in the sequence.

    // Initialize the first two Fibonacci numbers.
    printFibonacciVisual(fib[0], 0);
    printFibonacciVisual(fib[1], 1);

    // Generate the rest of the Fibonacci numbers and visualize.
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2]; // Fibonacci formula.
        printFibonacciVisual(fib[i], i);
    }
}

// Function that generates a visual representation of a Fibonacci number.
void printFibonacciVisual(int num, int index) {
    printf("Fibonacci[%d] = %d: ", index, num);

    // Each Fibonacci number visualized as a series of asterisks.
    for (int i = 0; i < num; i++) {
        printf("*");
    }

    // Reflecting on the meaning of Fibonacci numbers visually and philosophically.
    if (num > 0) {
        printf(" (The beauty of growth and the nature of sequences.)");
    }
    
    printf("\n"); // New line for clarity in output.
}