//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: Alan Turing
#include <stdio.h>

// Function prototype
int fibonacci(int n);
void print_fibonacci(int n, int order);
void print_descending(int n);

int main() {
    int terms, choice;

    printf("Welcome to the Fibonacci Sequence Generator!\n");
    printf("How many terms of the Fibonacci sequence would you like to generate? ");
    scanf("%d", &terms);

    if (terms <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    printf("Would you like to display the sequence in:\n");
    printf("1. Ascending order\n");
    printf("2. Descending order\n");
    scanf("%d", &choice);

    printf("Fibonacci Sequence:\n");
    if (choice == 1) {
        print_fibonacci(terms, 1);
    } else if (choice == 2) {
        print_fibonacci(terms, 0);
    } else {
        printf("Invalid choice, please select 1 or 2.\n");
    }

    return 0;
}

// Function to calculate the nth Fibonacci number
int fibonacci(int n) {
    if (n <= 1) {
        return n; // Base case: fib(0) = 0, fib(1) = 1
    }
    return fibonacci(n - 1) + fibonacci(n - 2); // Recursive case
}

// Function to print the Fibonacci series
void print_fibonacci(int n, int order) {
    if (order == 1) {
        // Ascending order
        for (int i = 0; i < n; i++) {
            printf("%d ", fibonacci(i));
        }
    } else {
        // Descending order
        print_descending(n);
    }
    printf("\n");
}

// Function to print the Fibonacci series in descending order
void print_descending(int n) {
    if (n == 0) {
        return; // Base case to stop recursion
    }
    print_descending(n - 1); // Recursive call for the next lower term
    printf("%d ", fibonacci(n - 1)); // Print in reverse order
}