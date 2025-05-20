//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 100

void printFibSequence(int n) {
    long long fib[MAX_TERMS];
    fib[0] = 0;
    fib[1] = 1;

    // Generate Fibonacci sequence
    printf("\nFibonacci Sequence:\n");
    printf("%-10s%-15s\n", "Term", "Value");
    printf("----------------------\n");
    printf("%-10s%-15lld\n", "F(0)", fib[0]);
    printf("%-10s%-15lld\n", "F(1)", fib[1]);

    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
        printf("%-10s%-15lld\n", "F(%d)", fib[i]);
    }
}

void visualizeFibSequence(int n) {
    long long fib[MAX_TERMS];
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    printf("\nFibonacci Sequence Visualizer:\n");
    for (int i = 0; i < n; i++) {
        printf("F(%d): ", i);
        for (int j = 0; j < fib[i]; j++) {
            printf("*");
        }
        printf(" (%lld)\n", fib[i]);
    }
}

int main() {
    int n;

    printf("Welcome to the Fibonacci Sequence Visualizer!\n");
    printf("Please enter the number of terms to display (up to %d): ", MAX_TERMS);
    scanf("%d", &n);

    if (n < 1 || n > MAX_TERMS) {
        printf("Invalid input! Please enter a number between 1 and %d.\n", MAX_TERMS);
        return -1;
    }

    printFibSequence(n);
    visualizeFibSequence(n);

    printf("\nThank you for using the Fibonacci Sequence Visualizer!\n");
    return 0;
}