//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

void generateFibonacci(int* fib, int n) {
    if (n >= 1) fib[0] = 0;
    if (n >= 2) fib[1] = 1;
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

void displayShapeShift(int* fib, int n) {
    int max_width = fib[n - 1] * 2; // Define a full width for the last Fibonacci number.
    
    for (int i = 0; i < n; i++) {
        int num_asterisks = fib[i] * 2; // Double for a wider visual effect.
        
        // Centering the Fibonacci number's display.
        int spaces = (max_width - num_asterisks) / 2; 
        for (int j = 0; j < spaces; j++) {
            printf(" ");
        }

        for (int j = 0; j < num_asterisks; j++) {
            printf("*");
        }
        
        printf("\n");
        
        // Shifting shapes based on Fibonacci value
        if (i % 2 == 0) {
            for(int k = 0; k < spaces; k++) printf(" ");
            for(int k = 0; k < num_asterisks; k++) printf(" ");
            printf("\n");
        }
    }
}

int main() {
    int n;
    printf("Enter the number of Fibonacci terms to visualize: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Please enter a number greater than 0.\n");
        return 1;
    }

    int* fib = malloc(n * sizeof(int));
    if (fib == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    generateFibonacci(fib, n);
    displayShapeShift(fib, n);

    free(fib);
    return 0;
}