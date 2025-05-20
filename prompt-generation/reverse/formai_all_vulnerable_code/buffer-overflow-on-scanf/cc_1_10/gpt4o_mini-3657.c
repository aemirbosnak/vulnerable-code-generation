//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define MAX_TERMS 30

void clear_screen() {
    // Clear the screen using an ANSI escape code
    printf("\033[H\033[J");
}

void set_cursor_position(int x, int y) {
    // Set the cursor position on the terminal
    printf("\033[%d;%dH", x, y);
}

void pause_for_a_while(int seconds) {
    // Pause the program for a specific number of seconds
    sleep(seconds);
}

void draw_fibonacci(int n) {
    // Variables to store Fibonacci sequence
    unsigned long long fib[MAX_TERMS];
    fib[0] = 0;
    fib[1] = 1;

    // Calculate Fibonacci terms
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    // Prepare visualization
    int max_length = 50; // Max length of visualization line
    for (int i = 0; i < n; i++) {
        // Calculate the number of stars proportional to the Fibonacci number
        int num_stars = (fib[i] % max_length);

        // Draw the line
        set_cursor_position(i+1, 1);
        printf("%3d: ", fib[i]);
        for (int j = 0; j < num_stars; j++) {
            printf("*");
        }
        fflush(stdout);
        pause_for_a_while(1); // Pause for a second between prints
    }
}

int main() {
    clear_screen(); // Clear the screen

    printf("       Fibonacci Sequence Visualizer       \n");
    printf("==============================================\n");
    printf("Each row represents a Fibonacci number, visualized with '*' based on its value.\n\n");

    int number_of_terms = MAX_TERMS;

    // Get user input for the number of Fibonacci terms to display
    printf("How many Fibonacci numbers do you want to visualize? (up to %d): ", MAX_TERMS);
    scanf("%d", &number_of_terms);

    if (number_of_terms > MAX_TERMS) {
        printf("Input exceeds maximum limit of %d, setting to max.\n", MAX_TERMS);
        number_of_terms = MAX_TERMS;
    } else if (number_of_terms < 1) {
        printf("Please enter a positive integer greater than 0. Setting to 1.\n");
        number_of_terms = 1;
    }

    draw_fibonacci(number_of_terms);

    printf("\nPress Enter to exit...\n");
    while (getchar() != '\n'); // Wait for the user to press Enter

    return 0;
}