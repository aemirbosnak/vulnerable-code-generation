//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: recursive
#include <stdio.h>

// Function to print the Fibonacci sequence
void printFibonacci(int n, int first, int second) {
    if (n > 0) {
        printf("%d ", first);
        // Move to next term in Fibonacci sequence
        printFibonacci(n - 1, second, first + second);
    }
}

// Function to display the Fibonacci series
void displayFibonacciSeries(int terms) {
    if (terms < 1) {
        printf("Please enter a positive integer greater than 0.\n");
        return;
    }
    printf("Fibonacci Series of %d terms: ", terms);
    printFibonacci(terms, 0, 1);
    printf("\n");
}

// Function to compute the nth Fibonacci number recursively
int computeFibonacci(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return computeFibonacci(n - 1) + computeFibonacci(n - 2);
    }
}

// Function to display Fibonacci numbers with factorials
void displayFibonacciWithFactorials(int terms) {
    if (terms < 1) {
        printf("Please enter a positive integer greater than 0.\n");
        return;
    }
    printf("Fibonacci Series with Factorials:\n");
    for (int i = 0; i < terms; i++) {
        int fib = computeFibonacci(i);
        printf("F(%d) = %d, F(%d) Factorial = %d\n", i, fib, i, factorial(i));
    }
}

// Helper function to compute factorial
int factorial(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Main function
int main() {
    int terms;

    printf("Enter the number of terms for the Fibonacci series: ");
    scanf("%d", &terms);
    displayFibonacciSeries(terms);

    // Additional demonstration of Fibonacci series with factorial for the same number of terms
    printf("\n");
    displayFibonacciWithFactorials(terms);

    return 0;
}