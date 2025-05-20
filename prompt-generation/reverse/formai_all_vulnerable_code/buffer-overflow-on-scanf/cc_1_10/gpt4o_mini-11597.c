//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

void printColoredFibonacci(int n) {
    printf("\n\033[1;34mFibonacci Sequence up to %d Terms:\033[0m\n", n);
    unsigned long long first = 0, second = 1, next;

    for (int i = 0; i < n; i++) {
        // Change color based on the index
        if (i % 2 == 0) {
            printf("\033[1;32m%llu\033[0m", first); // Green for even index
        } else {
            printf("\033[1;31m%llu\033[0m", first); // Red for odd index
        }
        
        // Print space between numbers
        if (i < n - 1) {
            printf(" -> ");
        }
        
        // Compute next Fibonacci number
        next = first + second;
        first = second;
        second = next;
    }
    printf("\n");
}

int main() {
    int terms;

    printf("\n\033[1;36mWelcome to the Fibonacci Sequence Visualizer!\033[0m\n");
    printf("Let's generate some sequences that will make your head spin!\n");
    
    printf("How many terms of the Fibonacci sequence would you like to visualize? ");
    scanf("%d", &terms);

    // Input validation
    if (terms <= 0) {
        printf("\033[1;31mOops! Please enter a positive integer!\033[0m\n");
        return 1;
    }

    // Call the function to print Fibonacci sequence
    printColoredFibonacci(terms);

    printf("\n\033[1;34mThank you for using the Fibonacci Sequence Visualizer!\033[0m\n");
    printf("\033[1;32mHappy Coding!\033[0m\n");

    return 0;
}