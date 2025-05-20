//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define FIB_MAX_VALUE 46368            // Maximum value of Fibonacci sequence to visualize
#define FIB_MAX_LENGTH 256               // Maximum length of Fibonacci sequence to visualize
#define FIB_PRECISION (1 << 20)           // Precision of floating-point calculations
#define FIB_ANIMATION_SPEED (1000 * 1000) // Animation speed in microseconds

// Function to calculate Fibonacci sequence
int64_t fib(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fib(n - 1) + fib(n - 2);
    }
}

// Function to visualize Fibonacci sequence
void visualize_fib(int n) {
    // Initialize Fibonacci sequence
    int64_t fib_sequence[FIB_MAX_LENGTH];
    for (int i = 0; i < n; i++) {
        fib_sequence[i] = fib(i);
    }

    // Calculate maximum value of Fibonacci sequence
    int64_t max_value = fib_sequence[n - 1];

    // Calculate scale factor to fit Fibonacci sequence within the screen
    double scale_factor = (double)FIB_PRECISION / (double)max_value;

    // Initialize ASCII art grid
    char grid[FIB_MAX_VALUE][FIB_MAX_LENGTH];
    for (int i = 0; i < FIB_MAX_VALUE; i++) {
        for (int j = 0; j < FIB_MAX_LENGTH; j++) {
            grid[i][j] = ' ';
        }
    }

    // Draw Fibonacci sequence
    for (int i = 0; i < n; i++) {
        int height = (int)(scale_factor * (double)fib_sequence[i]);
        for (int j = 0; j < height; j++) {
            grid[FIB_MAX_VALUE - j - 1][i] = '*';
        }
    }

    // Print ASCII art grid
    for (int i = 0; i < FIB_MAX_VALUE; i++) {
        for (int j = 0; j < FIB_MAX_LENGTH; j++) {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }

    // Delay for animation effect
    usleep(FIB_ANIMATION_SPEED);
}

int main() {
    // Visualize Fibonacci sequence up to the maximum length
    for (int i = 1; i <= FIB_MAX_LENGTH; i++) {
        visualize_fib(i);
    }

    return 0;
}