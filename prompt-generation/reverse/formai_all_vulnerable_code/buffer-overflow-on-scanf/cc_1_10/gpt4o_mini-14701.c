//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: safe
#include <stdio.h>
#include <stdlib.h>

// Function to compute Fibonacci numbers recursively
unsigned long long fibonacci(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// Function to print Fibonacci series up to 'count' terms
void printFibonacciSeries(int count) {
    for (int i = 0; i < count; i++) {
        printf("%llu ", fibonacci(i));
    }
    printf("\n");
}

// Function to read a positive integer from the user
int readPositiveInteger() {
    int num;
    char term;

    while (1) {
        printf("Enter the number of Fibonacci terms (positive integer): ");
        if (scanf("%d%c", &num, &term) != 2 || term != '\n' || num < 1) {
            // Clear the input buffer
            while ((term = getchar()) != '\n' && term != EOF);
            printf("Invalid input. Please try again.\n");
        } else {
            break;
        }
    }
    return num;
}

int main() {
    // Welcome message
    printf("Welcome to the Fibonacci Series Generator!\n");

    // Read user input
    int count = readPositiveInteger();

    // Print the Fibonacci series
    printf("Fibonacci series up to %d terms:\n", count);
    printFibonacciSeries(count);

    // Exit message
    printf("Thank you for using the Fibonacci Series Generator. Goodbye!\n");
    return 0;
}