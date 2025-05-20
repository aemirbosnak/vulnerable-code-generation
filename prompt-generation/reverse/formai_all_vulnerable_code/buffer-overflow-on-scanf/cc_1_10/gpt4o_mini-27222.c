//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 50

// Function prototypes
void generate_fibonacci(int n, long long *fib_sequence);
void display_fibonacci(long long *fib_sequence, int n);
void print_visualization(long long *fib_sequence, int n);

// Main Function
int main() {
    int n;
    long long fib_sequence[MAX_TERMS];

    printf("Welcome to the Fibonacci Sequence Visualizer!\n");
    printf("Enter the number of terms you want to generate (1 to %d): ", MAX_TERMS);
    scanf("%d", &n);

    if (n < 1 || n > MAX_TERMS) {
        printf("Invalid input! Please enter a number between 1 and %d.\n", MAX_TERMS);
        return 1;
    }

    generate_fibonacci(n, fib_sequence);
    display_fibonacci(fib_sequence, n);
    print_visualization(fib_sequence, n);

    return 0;
}

// Function to generate Fibonacci sequence
void generate_fibonacci(int n, long long *fib_sequence) {
    if (n >= 1) fib_sequence[0] = 0; // First Fibonacci number
    if (n >= 2) fib_sequence[1] = 1; // Second Fibonacci number

    for (int i = 2; i < n; i++) {
        fib_sequence[i] = fib_sequence[i - 1] + fib_sequence[i - 2];
    }
}

// Function to display the Fibonacci sequence
void display_fibonacci(long long *fib_sequence, int n) {
    printf("\nFibonacci Sequence:\n");
    for (int i = 0; i < n; i++) {
        printf("%lld ", fib_sequence[i]);
    }
    printf("\n");
}

// Function to print visual representation of Fibonacci numbers
void print_visualization(long long *fib_sequence, int n) {
    printf("\nFibonacci Visualization:\n");
    
    for (int i = 0; i < n; i++) {
        printf("%lld: ", fib_sequence[i]);
        for (long long j = 0; j < fib_sequence[i]; j += 100000) { // Scale for display
            printf("*");
        }
        printf("\n");
    }
}