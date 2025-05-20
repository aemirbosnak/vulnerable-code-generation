//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: Donald Knuth
#include <stdio.h>

// Function prototype declarations.
int fibonacci(int n);
long factorial(int n);
void printFibonacci(int n);

// Main function where execution begins.
int main() {
    int n;

    // Prompt user for input.
    printf("Enter the number of Fibonacci numbers to generate: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Please enter a non-negative integer.\n");
        return 1;
    }

    // Print the Fibonacci sequence.
    printFibonacci(n);

    // Additional functionality: Calculate and print the factorial of the last Fibonacci number.
    if (n > 0) {
        printf("\nFactorial of the %d-th Fibonacci number (%d) is: %ld\n",
               n, fibonacci(n), factorial(fibonacci(n)));
    }

    return 0;
}

// Recursive function to calculate the n-th Fibonacci number.
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// Recursive function to calculate the factorial of a number.
long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1; // Base cases
    } else {
        return n * factorial(n - 1); // Recursive call
    }
}

// Function to print the Fibonacci series up to the n-th number.
void printFibonacci(int n) {
    printf("Fibonacci Series up to %d terms:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i)); // Calling the recursive Fibonacci function
    }
    printf("\n"); // New line for better formatting
}