//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Define colors for terminal output
#define FG_RED "\x1b[31m"
#define FG_GREEN "\x1b[32m"
#define FG_YELLOW "\x1b[33m"
#define FG_BLUE "\x1b[34m"
#define FG_MAGENTA "\x1b[35m"
#define FG_CYAN "\x1b[36m"
#define FG_WHITE "\x1b[37m"

// Define reset color for terminal output
#define RESET_COLOR "\x1b[0m"

// Define the maximum number of Fibonacci numbers to generate
#define MAX_FIB_NUMBERS 100

// Define the width of the visualization grid
#define GRID_WIDTH 80

// Print a Fibonacci number with a specific color
void print_fib_number(int fib_number, char *color) {
    printf("%s%d%s ", color, fib_number, RESET_COLOR);
}

// Visualize the Fibonacci sequence using a grid
void visualize_fibonacci(int *fib_sequence, int num_fib_numbers) {
    // Initialize the visualization grid
    char grid[MAX_FIB_NUMBERS][GRID_WIDTH];
    for (int i = 0; i < MAX_FIB_NUMBERS; i++) {
        for (int j = 0; j < GRID_WIDTH; j++) {
            grid[i][j] = ' ';
        }
    }

    // Mark the Fibonacci numbers in the grid
    int current_row = 0;
    int current_col = 0;
    for (int i = 0; i < num_fib_numbers; i++) {
        // Determine the color of the Fibonacci number
        char *color;
        switch (i) {
            case 0:
                color = FG_RED;
                break;
            case 1:
                color = FG_GREEN;
                break;
            case 2:
                color = FG_YELLOW;
                break;
            case 3:
                color = FG_BLUE;
                break;
            case 4:
                color = FG_MAGENTA;
                break;
            case 5:
                color = FG_CYAN;
                break;
            default:
                color = FG_WHITE;
                break;
        }

        // Print the Fibonacci number in the grid
        print_fib_number(fib_sequence[i], color);

        // Move to the next row and column
        current_col += 10;
        if (current_col >= GRID_WIDTH) {
            current_row++;
            current_col = 0;
        }
    }

    // Print the visualization grid
    for (int i = 0; i < MAX_FIB_NUMBERS; i++) {
        printf("%s", grid[i]);
    }
}

int main() {
    // Initialize the Fibonacci sequence
    int fib_sequence[MAX_FIB_NUMBERS];
    fib_sequence[0] = 0;
    fib_sequence[1] = 1;
    for (int i = 2; i < MAX_FIB_NUMBERS; i++) {
        fib_sequence[i] = fib_sequence[i - 1] + fib_sequence[i - 2];
    }

    // Visualize the Fibonacci sequence
    visualize_fibonacci(fib_sequence, MAX_FIB_NUMBERS);

    return 0;
}