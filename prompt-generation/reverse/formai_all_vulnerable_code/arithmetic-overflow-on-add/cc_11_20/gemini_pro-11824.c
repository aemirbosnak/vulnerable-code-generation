//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define WIDTH 80
#define HEIGHT 25

int main() {
    int fib[WIDTH][HEIGHT];
    int i, j, x, y, t;

    // Initialize the Fibonacci sequence.
    fib[0][0] = 0;
    fib[1][0] = 1;

    // Calculate the Fibonacci sequence.
    for (i = 2; i < WIDTH; i++) {
        fib[i][0] = fib[i - 1][0] + fib[i - 2][0];
    }

    // Print the Fibonacci sequence.
    for (j = 1; j < HEIGHT; j++) {
        for (i = 0; i < WIDTH; i++) {
            fib[i][j] = fib[i][j - 1] + fib[i + 1][j - 1];
        }
    }

    // Visualize the Fibonacci sequence.
    for (j = 0; j < HEIGHT; j++) {
        for (i = 0; i < WIDTH; i++) {
            if (fib[i][j] > 0) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Pause the program.
    sleep(5);

    // Clear the screen.
    system("clear");

    // Move the cursor to the top of the screen.
    printf("\033[1;1H");

    // Print the Fibonacci sequence again.
    for (j = 0; j < HEIGHT; j++) {
        for (i = 0; i < WIDTH; i++) {
            if (fib[i][j] > 0) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Pause the program again.
    sleep(5);

    // Clear the screen again.
    system("clear");

    // Move the cursor to the top of the screen again.
    printf("\033[1;1H");

    // Print the Fibonacci sequence a third time.
    for (j = 0; j < HEIGHT; j++) {
        for (i = 0; i < WIDTH; i++) {
            if (fib[i][j] > 0) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Pause the program a third time.
    sleep(5);

    // Clear the screen a third time.
    system("clear");

    // Move the cursor to the top of the screen a third time.
    printf("\033[1;1H");

    // Print the Fibonacci sequence a fourth time.
    for (j = 0; j < HEIGHT; j++) {
        for (i = 0; i < WIDTH; i++) {
            if (fib[i][j] > 0) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Pause the program a fourth time.
    sleep(5);

    // Clear the screen a fourth time.
    system("clear");

    // Move the cursor to the top of the screen a fourth time.
    printf("\033[1;1H");

    // Print the Fibonacci sequence a fifth time.
    for (j = 0; j < HEIGHT; j++) {
        for (i = 0; i < WIDTH; i++) {
            if (fib[i][j] > 0) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Exit the program.
    return 0;
}