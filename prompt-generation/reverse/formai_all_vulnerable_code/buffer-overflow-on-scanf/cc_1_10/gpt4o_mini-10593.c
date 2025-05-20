//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

void printFibonacci(int n) {
    long long *fibonacci = (long long *)malloc(n * sizeof(long long));
    if (fibonacci == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Initialization
    fibonacci[0] = 0;
    if (n > 1) {
        fibonacci[1] = 1;
    }

    // Generate Fibonacci sequence
    for (int i = 2; i < n; i++) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }

    // Display Fibonacci sequence
    printf("Fibonacci Sequence (First %d terms):\n", n);
    for (int i = 0; i < n; i++) {
        printf("%lld ", fibonacci[i]);
    }
    printf("\n");
    
    // ASCII Visualization
    printf("\nASCII Visualization of Fibonacci Sequence:\n");
    for (int i = 0; i < n; i++) {
        int numChars = fibonacci[i] / 100000; // Adjust scale for ASCII visualization
        printf("%lld: ", fibonacci[i]);
        for (int j = 0; j < numChars; j++) {
            printf("*");
        }
        printf("\n");
    }

    // Clean up
    free(fibonacci);
}

int main() {
    int terms;

    printf("Enter the number of terms in the Fibonacci sequence to display: ");
    if (scanf("%d", &terms) != 1 || terms <= 0) {
        fprintf(stderr, "Invalid input. Please enter a positive integer.\n");
        return EXIT_FAILURE;
    }

    printFibonacci(terms);
    return EXIT_SUCCESS;
}