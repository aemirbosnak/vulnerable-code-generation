//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the nth Fibonacci number
int fib(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fib(n - 1) + fib(n - 2);
    }
}

// Function to print the Fibonacci sequence up to the nth term
void print_fib(int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", fib(i));
    }
    printf("\n");
}

// Function to draw a visual representation of the Fibonacci sequence
void draw_fib(int n) {
    // Create a 2D array to store the Fibonacci sequence
    int fib_array[n][n];

    // Initialize the first two rows of the array
    fib_array[0][0] = 0;
    fib_array[1][0] = 1;

    // Calculate the remaining rows of the array
    for (int i = 2; i < n; i++) {
        for (int j = 0; j < i; j++) {
            fib_array[i][j] = fib_array[i - 1][j] + fib_array[i - 2][j];
        }
    }

    // Print the Fibonacci sequence in a visual format
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            printf("%d ", fib_array[i][j]);
        }
        printf("\n");
    }
}

// Driver code
int main() {
    // Print the Fibonacci sequence up to the 10th term
    print_fib(10);

    // Draw a visual representation of the Fibonacci sequence up to the 10th term
    draw_fib(10);

    return 0;
}