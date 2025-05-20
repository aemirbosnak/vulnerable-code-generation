//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Draws a visual representation of the Fibonacci sequence using ASCII characters
void drawFibonacciSequence(int n) {
    // Check for invalid input
    if (n <= 0) {
        printf("Error: Invalid input. The number of Fibonacci numbers must be greater than 0.\n");
        return;
    }

    // Initialize the Fibonacci sequence
    int fib[n];
    fib[0] = 0;
    fib[1] = 1;

    // Calculate the remaining Fibonacci numbers
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    // Draw the visual representation
    for (int i = 0; i < n; i++) {
        // Calculate the number of spaces to indent the number
        int spaces = n - i;

        // Print the spaces
        for (int j = 0; j < spaces; j++) {
            printf(" ");
        }

        // Print the number
        printf("%d", fib[i]);

        // Print a newline character
        printf("\n");
    }
}

int main() {
    // Get the number of Fibonacci numbers to draw from the user
    int n;
    printf("Enter the number of Fibonacci numbers to draw: ");
    scanf("%d", &n);

    // Draw the visual representation
    drawFibonacciSequence(n);

    return 0;
}