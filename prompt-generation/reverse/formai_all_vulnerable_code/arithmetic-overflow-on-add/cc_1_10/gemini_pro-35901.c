//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of Fibonacci numbers to generate
#define MAX_FIB_NUMBERS 100

// Define the height and width of the visualizer window
#define WINDOW_HEIGHT 25
#define WINDOW_WIDTH 80

// Define the colors for the visualizer
#define COLOR_BG "\033[40m"
#define COLOR_FIB "\033[42m"
#define COLOR_RESET "\033[0m"

// Define the main function
int main(void) {
    // Initialize the Fibonacci numbers
    int fib_numbers[MAX_FIB_NUMBERS];
    fib_numbers[0] = 0;
    fib_numbers[1] = 1;

    // Calculate the Fibonacci numbers
    for (int i = 2; i < MAX_FIB_NUMBERS; i++) {
        fib_numbers[i] = fib_numbers[i - 1] + fib_numbers[i - 2];
    }

    // Create the visualizer window
    system("clear");
    printf(COLOR_BG);
    for (int i = 0; i < WINDOW_HEIGHT; i++) {
        for (int j = 0; j < WINDOW_WIDTH; j++) {
            printf(" ");
        }
        printf("\n");
    }
    printf(COLOR_RESET);

    // Draw the Fibonacci numbers
    for (int i = 0; i < MAX_FIB_NUMBERS; i++) {
        int height = WINDOW_HEIGHT - (fib_numbers[i] * WINDOW_HEIGHT / fib_numbers[MAX_FIB_NUMBERS - 1]);
        for (int j = 0; j < height; j++) {
            for (int k = 0; k < WINDOW_WIDTH; k++) {
                printf(" ");
            }
            printf("\n");
        }
        for (int j = height; j < WINDOW_HEIGHT; j++) {
            for (int k = 0; k < WINDOW_WIDTH; k++) {
                if (k < i) {
                    printf(" ");
                } else {
                    printf(COLOR_FIB);
                    printf(" ");
                    printf(COLOR_RESET);
                }
            }
            printf("\n");
        }
    }

    // Wait for user input
    getchar();

    return 0;
}