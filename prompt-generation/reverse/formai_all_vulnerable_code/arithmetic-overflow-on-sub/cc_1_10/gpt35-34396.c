//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: grateful
// Fibonacci Sequence Visualizer
// By [Your Name], Grateful Style

#include <stdio.h>
#include <stdlib.h>

// Function to calculate Fibonacci sequence
int fibonacci(int n) {
    if (n == 0 || n == 1) {
        return n;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

// Function to print sequence as visual bars
void printSequence(int n) {
    int i, j, height;

    printf("\n\n");

    // Calculate height of bars based on maximum value in sequence
    int max_val = fibonacci(n);
    int bar_heights[max_val+1];
    for (i = 0; i <= max_val; i++) {
        bar_heights[i] = 0;
    }
    for (i = 0; i <= n; i++) {
        height = fibonacci(i);
        bar_heights[height]++;
    }

    // Print sequence as visual bars
    for (i = max_val; i >= 0; i--) {
        printf("   ");
        for (j = 0; j <= n; j++) {
            height = fibonacci(j);
            if (bar_heights[i] >= height) {
                printf("**** ");
            } else {
                printf("     ");
            }
        }
        printf("\n");
    }

    printf("\n");
}

// Main function
int main() {
    int n, i;

    printf("Fibonacci Sequence Visualizer\n\n");

    // Get input from user for number of terms
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    // Generate and print Fibonacci sequence
    printf("\nFibonacci Sequence:\n");
    for (i = 0; i <= n; i++) {
        printf("%d ", fibonacci(i));
    }

    // Print sequence as visual bars
    printSequence(n);

    return 0;
}