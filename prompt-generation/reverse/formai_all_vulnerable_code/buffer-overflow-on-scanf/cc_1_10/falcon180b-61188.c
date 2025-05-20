//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_TERMS 100
#define MAX_COLUMNS 100

// Function to calculate the nth Fibonacci number
long double fibonacci(int n) {
    long double fib_n1 = 0, fib_n2 = 1, fib_n;

    for (int i = 2; i <= n; ++i) {
        fib_n = fib_n1 + fib_n2;
        fib_n1 = fib_n2;
        fib_n2 = fib_n;
    }

    return fib_n;
}

// Function to print the Fibonacci sequence up to n terms
void print_fibonacci_sequence(int n) {
    printf("Fibonacci sequence up to %d terms:\n", n);

    int columns = (int)ceil(log10(n));
    for (int i = 0; i < n; ++i) {
        printf("%*ld ", columns, fibonacci(i));
    }
}

// Function to visualize the Fibonacci sequence up to n terms
void visualize_fibonacci_sequence(int n) {
    printf("Visualizing Fibonacci sequence up to %d terms:\n", n);

    int columns = (int)ceil(log10(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < columns; ++j) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int n;

    printf("Enter the number of terms to visualize: ");
    scanf("%d", &n);

    if (n > MAX_TERMS) {
        printf("Error: Number of terms exceeds maximum limit of %d.\n", MAX_TERMS);
        return 1;
    }

    if (n <= 0) {
        printf("Error: Number of terms must be positive.\n");
        return 1;
    }

    print_fibonacci_sequence(n);
    visualize_fibonacci_sequence(n);

    return 0;
}