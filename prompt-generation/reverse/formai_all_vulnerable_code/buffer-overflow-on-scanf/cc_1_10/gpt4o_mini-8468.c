//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define MAX_FIB 50

void generateFibonacci(int n, long long fib[]);
void visualizeFibonacci(int n, long long fib[]);
void printBar(long long value);

int main() {
    int n;

    printf("Enter the number of Fibonacci terms to generate (1 - %d): ", MAX_FIB);
    scanf("%d", &n);

    if (n < 1 || n > MAX_FIB) {
        printf("Please enter a number between 1 and %d.\n", MAX_FIB);
        return 1;
    }
    
    long long fib[MAX_FIB];
    generateFibonacci(n, fib);
    visualizeFibonacci(n, fib);

    return 0;
}

void generateFibonacci(int n, long long fib[]) {
    fib[0] = 0;
    if (n > 1) {
        fib[1] = 1;
        for (int i = 2; i < n; i++) {
            fib[i] = fib[i - 1] + fib[i - 2];
        }
    }
}

void visualizeFibonacci(int n, long long fib[]) {
    printf("\nFibonacci Sequence Visualization:\n");
    for (int i = 0; i < n; i++) {
        printf("F[%d]: ", i);
        printBar(fib[i]);
        printf(" %lld\n", fib[i]);
    }
}

void printBar(long long value) {
    int barWidth = value / 100000; // Scale down the value to adjust the bar width
    for (int j = 0; j < barWidth; j++) {
        printf("█"); // Unicode block character for visualization
    }
}