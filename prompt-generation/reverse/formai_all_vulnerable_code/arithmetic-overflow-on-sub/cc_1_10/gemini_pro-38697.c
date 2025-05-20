//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: detailed
#include <stdio.h>

// Function to calculate the Fibonacci sequence up to the nth term
int* fibonacci(int n) {
    // Allocate memory for the Fibonacci sequence
    int* fib = malloc(sizeof(int) * n);

    // Initialize the first two terms of the sequence
    fib[0] = 0;
    fib[1] = 1;

    // Calculate the remaining terms of the sequence
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    // Return the Fibonacci sequence
    return fib;
}

// Function to visualize the Fibonacci sequence as a bar chart
void visualize(int* fib, int n) {
    // Get the maximum value in the Fibonacci sequence
    int max = fib[n - 1];

    // Create a bar chart
    for (int i = 0; i < n; i++) {
        // Calculate the height of the bar
        int height = fib[i] * 100 / max;

        // Print the bar
        printf("|");
        for (int j = 0; j < height; j++) {
            printf("=");
        }
        printf("\n");
    }
}

int main() {
    // Get the number of terms in the Fibonacci sequence
    int n;
    printf("Enter the number of terms in the Fibonacci sequence: ");
    scanf("%d", &n);

    // Calculate the Fibonacci sequence
    int* fib = fibonacci(n);

    // Visualize the Fibonacci sequence
    visualize(fib, n);

    // Free the memory allocated for the Fibonacci sequence
    free(fib);

    return 0;
}