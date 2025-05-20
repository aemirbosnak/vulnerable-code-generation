//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Function to calculate Fibonacci numbers recursively
int fibonacci(int n) {
    if (n <= 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Function to print Fibonacci series up to n
void printFibonacciSeries(int limit) {
    printf("Fibonacci Series up to %d:\n", limit);
    for (int i = 0; i < limit; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
}

// Function to get user input with validation
int getUserInput() {
    int number;
    char buffer[100];
    
    while (1) {
        printf("Enter a positive integer for Fibonacci series (or '-1' to exit): ");
        fgets(buffer, sizeof(buffer), stdin);
        
        // Check if input is negative
        if (buffer[0] == '-' && buffer[1] == '1' && buffer[2] == '\n') {
            printf("Exiting the program. Goodbye!\n");
            exit(0);
        }
        
        // Check if input is numeric
        if (sscanf(buffer, "%d", &number) == 1 && number >= 0) {
            return number;
        } else {
            printf("Invalid input. Please enter a positive integer.\n");
        }
    }
}

int main() {
    printf("Welcome to the Fibonacci Calculator!\n");

    while (1) {
        int limit = getUserInput();
        if (limit >= 0) {
            printFibonacciSeries(limit);
        }
    }

    return 0;
}