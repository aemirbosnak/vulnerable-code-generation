//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Maximum number of Fibonacci numbers to generate
#define MAX_FIB 100

// Array to store the Fibonacci numbers
long long fib[MAX_FIB];

// Function to generate the Fibonacci numbers
void generate_fib() {
    // Initialize the first two Fibonacci numbers
    fib[0] = 0;
    fib[1] = 1;

    // Calculate the remaining Fibonacci numbers
    for (int i = 2; i < MAX_FIB; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

// Function to print the Fibonacci sequence
void print_fib() {
    printf("The Fibonacci sequence is:\n");
    for (int i = 0; i < MAX_FIB; i++) {
        printf("%lld ", fib[i]);
    }
    printf("\n");
}

// Function to draw the Fibonacci spiral
void draw_spiral() {
    // Initialize the starting coordinates of the spiral
    int x = 0;
    int y = 0;

    // Initialize the current Fibonacci number
    long long current_fib = 0;

    // Initialize the length of the current side of the spiral
    int side_length = 1;

    // Draw the spiral
    while (current_fib < fib[MAX_FIB - 1]) {
        // Draw the current side of the spiral
        for (int i = 0; i < side_length; i++) {
            // Move to the next coordinate
            if (x % 2 == 0) {
                x++;
            } else {
                y++;
            }

            // Print the current Fibonacci number
            printf("%lld ", current_fib);

            // Calculate the next Fibonacci number
            current_fib = fib[x + y];
        }

        // Turn the spiral
        side_length++;
    }

    printf("\n");
}

int main() {
    // Generate the Fibonacci numbers
    generate_fib();

    // Print the Fibonacci sequence
    print_fib();

    // Draw the Fibonacci spiral
    draw_spiral();

    return 0;
}