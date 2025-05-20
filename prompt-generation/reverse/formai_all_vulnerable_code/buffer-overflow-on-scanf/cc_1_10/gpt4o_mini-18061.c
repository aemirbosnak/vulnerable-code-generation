//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: Ada Lovelace
#include <stdio.h>

void generateFibonacci(int n, unsigned long long fib[]);
void printFibonacciArt(unsigned long long fib[], int n);

int main() {
    int n;

    printf("Welcome to the Fibonacci Sequence Generator!\n");
    printf("How many terms of the Fibonacci sequence would you like to see? ");

    // Read the number of terms from the user
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    // Array to hold Fibonacci numbers
    unsigned long long fibonacci[n];

    // Generate Fibonacci sequence
    generateFibonacci(n, fibonacci);

    // Print Fibonacci sequence
    printf("\nFibonacci Sequence:\n");
    for (int i = 0; i < n; i++) {
        printf("%llu ", fibonacci[i]);
    }
    printf("\n\n");

    // Print Fibonacci representation in ASCII Art
    printFibonacciArt(fibonacci, n);

    return 0;
}

// Function to generate the first n Fibonacci numbers
void generateFibonacci(int n, unsigned long long fib[]) {
    fib[0] = 0;
    if (n > 1) {
        fib[1] = 1;
    }
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

// Function to visualize Fibonacci numbers using ASCII Art
void printFibonacciArt(unsigned long long fib[], int n) {
    printf("Fibonacci Visualization:\n");

    for (int i = 0; i < n; i++) {
        // Print the Fibonacci number as a series of '*' characters
        for (unsigned long long j = 0; j < fib[i] / 1000000; j++) {
            printf("*");
        }
        printf(" (%llu)\n", fib[i]);
    }
}