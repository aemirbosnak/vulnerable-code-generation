//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define WIDTH 80
#define HEIGHT 25

int main() {
    int i, j, k;
    int fib[WIDTH];
    int fib_prev[WIDTH];
    int fib_next[WIDTH];

    // Initialize Fibonacci sequence
    fib[0] = 1;
    fib[1] = 1;
    for (i = 2; i < WIDTH; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    // Initialize the screen buffer
    char screen[HEIGHT][WIDTH];
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            screen[i][j] = ' ';
        }
    }

    // Visualize Fibonacci sequence
    while (1) {
        // Clear the screen
        for (i = 0; i < HEIGHT; i++) {
            for (j = 0; j < WIDTH; j++) {
                screen[i][j] = ' ';
            }
        }

        // Calculate the next Fibonacci numbers
        for (i = 2; i < WIDTH; i++) {
            fib_next[i] = fib[i - 1] + fib[i - 2];
        }

        // Shift the Fibonacci numbers
        for (i = WIDTH - 1; i >= 0; i--) {
            fib_prev[i] = fib[i];
            fib[i] = fib_next[i];
        }

        // Draw the Fibonacci sequence
        for (i = 0; i < HEIGHT; i++) {
            for (j = 0; j < WIDTH; j++) {
                if (fib[j] >= i) {
                    screen[i][j] = '*';
                }
            }
        }

        // Print the screen buffer
        for (i = 0; i < HEIGHT; i++) {
            for (j = 0; j < WIDTH; j++) {
                printf("%c", screen[i][j]);
            }
            printf("\n");
        }

        // Sleep for a bit
        usleep(100000);
    }

    return 0;
}