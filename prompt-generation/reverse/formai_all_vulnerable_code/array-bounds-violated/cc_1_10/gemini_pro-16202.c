//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the nth Fibonacci number using recursion
int fib_recursive(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fib_recursive(n - 1) + fib_recursive(n - 2);
    }
}

// Function to calculate the nth Fibonacci number using dynamic programming
int fib_dp(int n) {
    // Create an array to store the Fibonacci numbers
    int fib[n + 1];

    // Initialize the first two Fibonacci numbers
    fib[0] = 0;
    fib[1] = 1;

    // Calculate the remaining Fibonacci numbers
    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return fib[n];
}

// Function to print the Fibonacci sequence up to the nth term
void print_fibonacci(int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", fib_dp(i));
    }
    printf("\n");
}

// Function to generate a visual representation of the Fibonacci sequence
// using ASCII characters
void visualize_fibonacci(int n) {
    // Create a 2D array to store the ASCII representation of the Fibonacci sequence
    char grid[n][n];

    // Initialize the grid with empty spaces
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grid[i][j] = ' ';
        }
    }

    // Draw the Fibonacci spiral
    int x = n / 2;
    int y = n / 2;
    int direction = 0;  // 0: right, 1: down, 2: left, 3: up
    int steps = 1;  // Number of steps in the current direction
    int fib_index = 0;  // Index of the current Fibonacci number

    while (fib_index < n) {
        // Draw the current Fibonacci number in the grid
        grid[x][y] = fib_dp(fib_index) + '0';

        // Move in the current direction
        switch (direction) {
            case 0:  // Right
                x++;
                break;
            case 1:  // Down
                y++;
                break;
            case 2:  // Left
                x--;
                break;
            case 3:  // Up
                y--;
                break;
        }

        // Decrement the number of steps in the current direction
        steps--;

        // If we have finished all the steps in the current direction,
        // change the direction and reset the number of steps
        if (steps == 0) {
            direction = (direction + 1) % 4;
            steps = fib_dp(fib_index++);
        }
    }

    // Print the ASCII representation of the Fibonacci sequence
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Get the number of terms from the user
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    // Print the Fibonacci sequence
    printf("Fibonacci sequence: ");
    print_fibonacci(n);

    // Visualize the Fibonacci sequence
    printf("\nASCII representation of the Fibonacci sequence:\n");
    visualize_fibonacci(n);

    return 0;
}