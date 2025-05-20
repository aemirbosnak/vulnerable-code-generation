//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: careful
#include <stdio.h>

// Function to print spaces
void printSpaces(int num) {
    for (int i = 0; i < num; i++) {
        printf("  "); // Print 2 spaces for aesthetic spacing
    }
}

// Function to generate the Fibonacci sequence up to n terms
void generateFibonacci(int n, int fib[]) {
    fib[0] = 0;
    if (n > 1) fib[1] = 1;
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

// Function to print Fibonacci Pattern
void printFibonacciPattern(int n) {
    int fib[n]; // Declare array to hold Fibonacci numbers
    generateFibonacci(n, fib); // Generate Fibonacci numbers

    int spaces = n; // Initialize spaces

    for (int i = 0; i < n; i++) {
        printSpaces(spaces); // Print leading spaces
        for (int j = 0; j <= i; j++) {
            printf("%d ", fib[j]); // Print Fibonacci number and space
        }
        spaces--; // Decrease spaces for the next line
        printf("\n"); // Move to the next line
    }
}

// Main function to execute the program
int main() {
    int n;

    printf("Enter the number of terms for the Fibonacci pattern: ");
    scanf("%d", &n); // Read number of terms

    if (n <= 0) {
        printf("Please enter a positive integer.\n");
        return 1; // Exit with error
    }

    printf("Fibonacci Pattern of %d terms:\n", n);
    printFibonacciPattern(n); // Print the pattern
    
    return 0; // Indicate successful completion
}