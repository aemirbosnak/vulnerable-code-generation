//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

void displayFibonacci(int n) {
    if (n <= 0) return;

    long long *fibonacci = (long long *)malloc(n * sizeof(long long));
    if (fibonacci == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // Generate the Fibonacci sequence
    fibonacci[0] = 0;
    if (n > 1) 
        fibonacci[1] = 1;
    
    for (int i = 2; i < n; i++) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }

    // Display the Fibonacci sequence
    printf("\nFibonacci Sequence (up to %d terms):\n", n);
    for (int i = 0; i < n; i++) {
        printf("\033[36m%lld\033[0m", fibonacci[i]); // Use color for the output
        if (i < n - 1) {
            printf(" -> "); // Spacing for better visualization
        }
    }
    printf("\n");

    // Clean up memory
    free(fibonacci);
}

void visualizeFibonacci(int n) {
    if (n <= 0) return;
    
    printf("\nVisualizing Fibonacci Sequence:\n");
    printf("Each 'o' represents the Fibonacci number at that position:\n");

    for (int i = 0; i < n; i++) {
        printf("F(%d): ", i);
        for (int j = 0; j < i; j++) {
            printf("o"); // Print visual representation
        }
        printf(" (%d)\n", i);
    }
}

int main() {
    int terms;

    printf("Welcome to the Fibonacci Sequence Visualizer!\n");
    printf("How many terms of Fibonacci would you like to see? ");
    
    // Input prompt loop
    while (scanf("%d", &terms) != 1 || terms <= 0) {
        printf("Please enter a positive integer: ");
        while(getchar() != '\n'); // Clear invalid input
    }

    // Display the Fibonacci Sequence
    displayFibonacci(terms);

    // Visualize the Fibonacci Sequence
    visualizeFibonacci(terms);

    printf("\nThank you for using the Fibonacci Sequence Visualizer!\n");
    return 0;
}