//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_TERMS 20 // Maximum number of terms in Fibonacci sequence

void generateFibonacci(int n, int fib[]) {
    fib[0] = 0; // First Fibonacci number
    fib[1] = 1; // Second Fibonacci number
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2]; // Fibonacci calculation
    }
}

void printFibonacci(int n, int fib[]) {
    printf("Fibonacci Sequence (up to %d terms):\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", fib[i]);
    }
    printf("\n");
}

void visualizeFibonacci(int n, int fib[]) {
    printf("\nVisualization of Fibonacci Sequence:\n");
    for (int i = 0; i < n; i++) {
        printf("%2d: ", fib[i]);
        for (int j = 0; j < fib[i]; j++) {
            printf("*"); // Visualizing each term with asterisks
        }
        printf("\n");
        usleep(300000); // Sleep for 300ms for better visualization
    }
}

int main() {
    int n, fib[MAX_TERMS];

    printf("Enter the number of terms in the Fibonacci sequence (max %d): ", MAX_TERMS);
    scanf("%d", &n);

    if (n > MAX_TERMS || n < 1) {
        printf("Please enter a number between 1 and %d.\n", MAX_TERMS);
        return 1;
    }
    
    generateFibonacci(n, fib);
    
    printFibonacci(n, fib);
    
    visualizeFibonacci(n, fib);
    
    return 0;
}