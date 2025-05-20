//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: modular
#include <stdio.h>

// Function prototype declarations
int fibonacci(int n);
int factorial(int n);
void printFibonacciSeries(int terms);
void printFactorials(int start, int end);

int main() {
    int terms, start, end;

    // User input for Fibonacci series
    printf("Enter the number of terms in Fibonacci series: ");
    scanf("%d", &terms);
    printFibonacciSeries(terms);

    // User input for factorial calculation
    printf("\nEnter the starting and ending numbers for factorial calculation (e.g., 1 5): ");
    scanf("%d %d", &start, &end);
    printFactorials(start, end);

    return 0;
}

// Function to compute the nth Fibonacci number recursively
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Function to compute the factorial of a number recursively
int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

// Function to print the Fibonacci series up to a specified number of terms
void printFibonacciSeries(int terms) {
    printf("Fibonacci series up to %d terms:\n", terms);
    for (int i = 0; i < terms; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
}

// Function to print factorials of numbers in a given range
void printFactorials(int start, int end) {
    printf("Factorials from %d to %d:\n", start, end);
    for (int i = start; i <= end; i++) {
        printf("%d! = %d\n", i, factorial(i));
    }
}