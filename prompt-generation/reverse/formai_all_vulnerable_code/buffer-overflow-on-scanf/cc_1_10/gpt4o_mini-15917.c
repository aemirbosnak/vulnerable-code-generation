//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Function prototype for the recursive Fibonacci function
int fibonacci(int n);

// Function to print the Fibonacci series
void printFibonacci(int terms);

// Main function
int main() {
    int terms;

    printf("Welcome to the Fibonacci Series Generator!\n");
    printf("Please enter the number of terms you want to generate (1 - 50): ");
    
    // Input validation loop
    while (1) {
        scanf("%d", &terms);
        
        if (terms >= 1 && terms <= 50) {
            break;  // Valid input, exit the loop
        } else {
            printf("Invalid input. Please enter a number between 1 and 50: ");
        }
    }

    printf("\nFibonacci Series up to %d terms:\n", terms);
    printFibonacci(terms);
    
    return 0;
}

// Recursive function to calculate Fibonacci number
int fibonacci(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

// Function to print the Fibonacci series
void printFibonacci(int terms) {
    for (int i = 0; i < terms; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
}