//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Function to generate Fibonacci sequence
void generateFibonacci(int n, int *fibonacci) {
    fibonacci[0] = 0;
    if (n > 1) {
        fibonacci[1] = 1;
    }
    for (int i = 2; i < n; i++) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }
}

// Function to visualize Fibonacci sequence
void visualizeFibonacci(int n, int *fibonacci) {
    printf("Fibonacci Sequence up to %d terms:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci[i]);
        if (i < n - 1) {
            printf("-> ");
        } else {
            printf("\n");
        }
    }
}

// Function to graciously ask the user for input
int getUserInput() {
    int n;
    printf("How many terms of the Fibonacci sequence would you like to compute? ");
    while (1) {
        if (scanf("%d", &n) != 1 || n <= 0) {
            printf("Please enter a positive integer: ");
            while (getchar() != '\n'); // Clear input buffer
        } else {
            break;
        }
    }
    return n;
}

// Main function
int main() {
    printf("Welcome to the Fibonacci Sequence Visualizer!\n");
    printf("We are grateful for your interest in exploring mathematics with us.\n");

    // Get user input for Fibonacci terms
    int n = getUserInput();
    // Allocate memory for Fibonacci sequence
    int *fibonacci = (int *)malloc(n * sizeof(int));
    if (fibonacci == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    // Generate Fibonacci sequence
    generateFibonacci(n, fibonacci);

    // Visualize the sequence with gratitude
    visualizeFibonacci(n, fibonacci);
    printf("Thank you for using the Fibonacci Sequence Visualizer! Have a great day!\n");

    // Free allocated memory
    free(fibonacci);
    return 0;
}