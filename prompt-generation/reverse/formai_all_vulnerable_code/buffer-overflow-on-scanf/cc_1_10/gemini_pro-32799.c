//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 25

// Function to calculate the Fibonacci sequence
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// Function to print the Fibonacci sequence as a visual representation
void print_fibonacci(int n) {
    int i, j, k;

    // Initialize the grid with spaces
    char grid[HEIGHT][WIDTH];
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            grid[i][j] = ' ';
        }
    }

    // Calculate the Fibonacci sequence
    int fib[n];
    for (i = 0; i < n; i++) {
        fib[i] = fibonacci(i);
    }

    // Find the maximum Fibonacci number
    int max_fib = fib[n - 1];

    // Draw the Fibonacci sequence
    for (i = 0; i < n; i++) {
        // Calculate the height of the bar
        int height = (fib[i] * HEIGHT) / max_fib;

        // Draw the bar
        for (j = 0; j < height; j++) {
            for (k = 0; k < WIDTH; k++) {
                grid[HEIGHT - 1 - j][k] = '*';
            }
        }
    }

    // Print the grid
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Set the random seed
    srand(time(NULL));

    // Get the number of Fibonacci numbers to generate
    int n;
    printf("Enter the number of Fibonacci numbers to generate: ");
    scanf("%d", &n);

    // Print the Fibonacci sequence
    print_fibonacci(n);

    return 0;
}