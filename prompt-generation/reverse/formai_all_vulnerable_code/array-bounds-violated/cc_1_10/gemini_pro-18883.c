//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the maximum number of Fibonacci numbers to generate
#define MAX_FIB 100

// Define the width and height of the visualization
#define WIDTH 100
#define HEIGHT 100

// Define the colors used in the visualization
#define COLOR_BACKGROUND 0x000000
#define COLOR_FIBONACCI 0xFFFFFF

// Create a 2D array to store the Fibonacci numbers
int fib[MAX_FIB][2];

// Create a 2D array to store the colors of each pixel
int color[WIDTH][HEIGHT];

// Function to generate the Fibonacci sequence
void generate_fibonacci() {
    // Initialize the first two Fibonacci numbers
    fib[0][0] = 0;
    fib[0][1] = 1;

    // Generate the remaining Fibonacci numbers
    for (int i = 1; i < MAX_FIB; i++) {
        fib[i][0] = fib[i - 1][0] + fib[i - 2][0];
        fib[i][1] = fib[i - 1][1] + fib[i - 2][1];
    }
}

// Function to visualize the Fibonacci sequence
void visualize_fibonacci() {
    // Initialize the color array
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            color[i][j] = COLOR_BACKGROUND;
        }
    }

    // Iterate over the Fibonacci numbers
    for (int i = 0; i < MAX_FIB; i++) {
        // Calculate the coordinates of the pixel to color
        int x = (int)round((double)fib[i][0] / fib[MAX_FIB - 1][0] * (WIDTH - 1));
        int y = (int)round((double)fib[i][1] / fib[MAX_FIB - 1][1] * (HEIGHT - 1));

        // Color the pixel
        color[x][y] = COLOR_FIBONACCI;
    }
}

// Function to print the visualization to the console
void print_visualization() {
    // Iterate over the rows of the visualization
    for (int i = 0; i < HEIGHT; i++) {
        // Iterate over the columns of the visualization
        for (int j = 0; j < WIDTH; j++) {
            // Print the color of the pixel
            printf("%c", color[j][i] == COLOR_FIBONACCI ? '#' : ' ');
        }

        // Print a newline character
        printf("\n");
    }
}

// Main function
int main() {
    // Generate the Fibonacci sequence
    generate_fibonacci();

    // Visualize the Fibonacci sequence
    visualize_fibonacci();

    // Print the visualization to the console
    print_visualization();

    return 0;
}