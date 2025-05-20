//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_TERMS 20 // Maximum number of terms in Fibonacci sequence
#define DELAY 500000 // Delay in microseconds for visualization

void print_fibonacci(int n);
void visualize_fibonacci(int n);
void delay(int microseconds);

int main() {
    int n;

    printf("Welcome to the Fibonacci Sequence Visualizer!\n");
    printf("How many terms of the Fibonacci sequence would you like to visualize? (Max %d): ", MAX_TERMS);
    
    // Read user input
    scanf("%d", &n);
    
    // Input validation
    if (n < 1 || n > MAX_TERMS) {
        printf("Please enter a number between 1 and %d.\n", MAX_TERMS);
        return 1;
    }

    // Print the Fibonacci sequence
    print_fibonacci(n);
    // Visualize the Fibonacci sequence
    visualize_fibonacci(n);

    printf("\nThank you for using the Fibonacci Sequence Visualizer!\n");
    return 0;
}

void print_fibonacci(int n) {
    long long first = 0, second = 1, next;

    printf("Fibonacci Sequence:\n");
    for (int i = 0; i < n; ++i) {
        if (i <= 1) {
            next = i; // First two terms are 0 and 1
        } else {
            next = first + second; // Calculate the next term
            first = second; // Move to the next term
            second = next; // Update second
        }
        printf("%lld ", next); // Print the term
    }
    printf("\n");
}

void visualize_fibonacci(int n) {
    long long first = 0, second = 1, next;
    
    printf("\nVisualizing the Fibonacci Sequence:\n");
    for (int i = 0; i < n; ++i) {
        if (i <= 1) {
            next = i; // First two terms are 0 and 1
        } else {
            next = first + second; // Calculate the next term
            first = second; // Move to the next term
            second = next; // Update second
        }

        // Visual Representation
        printf("Term %d (%lld): ", i + 1, next);
        for (int j = 0; j < next; j++) { // Number of asterisks equal to the Fibonacci term
            printf("*");
        }
        printf("\n"); // New line for each term
        delay(DELAY); // Introduce delay for visualization
    }
}

void delay(int microseconds) {
    usleep(microseconds); // Create a delay in execution
}