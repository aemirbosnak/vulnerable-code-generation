//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Function to calculate the n-th Fibonacci number
int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Function to display the Fibonacci sequence in a spiral pattern
void visualizer(int count) {
    int fib[count];
    // Calculate Fibonacci numbers
    for (int i = 0; i < count; i++) {
        fib[i] = fibonacci(i);
    }

    // Variables for spiral dimensions and directions
    int spiral_size = 10 + count; // Effectively large enough for visualization
    char grid[spiral_size][spiral_size];
    int x = spiral_size / 2, y = spiral_size / 2; // Start from the center
    int dx = 0, dy = -1; // Start by moving up

    // Initialize the grid
    for (int i = 0; i < spiral_size; i++)
        for (int j = 0; j < spiral_size; j++)
            grid[i][j] = ' ';

    // Create a spiral visualization
    for (int i = 0; i < count; i++) {
        int num = fib[i];
        // Place the current Fibonacci number in the spiral
        for (int j = 0; j < num; j++) {
            grid[y][x] = '*'; // Plot a star for visualization
            // Move in the current direction
            y += dy;
            x += dx;
        }

        // Change direction for the next Fibonacci number
        int temp = dx;
        dx = -dy;     // Counter-clockwise rotation
        dy = temp;    // Carry forward previous direction
        // Ensure we don't turn 90 degrees every iteration, but rather once per segment.
        if (i % 2 == 1) {
            // Add a little turn so it spirals correctly
            dx *= -1; 
            dy *= -1;
        }
    }

    // Display the spiral
    for (int i = 0; i < spiral_size; i++) {
        for (int j = 0; j < spiral_size; j++) {
            if (grid[i][j] == '*')
                printf("%c", grid[i][j]);
            else
                printf(" ");
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter how many Fibonacci numbers to visualize: ");
    scanf("%d", &n);
    
    // Validate input
    if (n <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    visualizer(n);
    return 0;
}