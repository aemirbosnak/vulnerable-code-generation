//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// ANSI color codes
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

// Function to calculate the nth Fibonacci number
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// Function to visualize the Fibonacci sequence
void visualize_fibonacci(int n) {
    // Clear the screen
    system("clear");

    // Print the Fibonacci numbers
    for (int i = 0; i <= n; i++) {
        // Calculate the ith Fibonacci number
        int fib = fibonacci(i);

        // Choose a color based on the Fibonacci number
        char *color;
        if (fib % 2 == 0) {
            color = ANSI_COLOR_RED;
        } else {
            color = ANSI_COLOR_GREEN;
        }

        // Print the Fibonacci number in color
        printf("%s%d ", color, fib);
    }

    // Reset the color
    printf("%s", ANSI_COLOR_RESET);
}

// Main function
int main() {
    // Get the number of Fibonacci numbers to visualize
    int n;
    printf("Enter the number of Fibonacci numbers to visualize: ");
    scanf("%d", &n);

    // Visualize the Fibonacci sequence
    visualize_fibonacci(n);

    return 0;
}