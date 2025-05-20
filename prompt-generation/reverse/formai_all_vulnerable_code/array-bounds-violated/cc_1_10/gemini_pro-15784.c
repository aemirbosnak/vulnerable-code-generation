//GEMINI-pro DATASET v1.0 Category: Pattern printing ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the dimensions of the grid
#define WIDTH 80
#define HEIGHT 25

// Define the character set
char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

// Define the number of characters to print per line
#define NUM_CHARS_PER_LINE 80

// Define the maximum number of iterations
#define MAX_ITERATIONS 1000

// Define the probability of a character being printed
#define PROBABILITY 0.5

// Random number generator
int random_number() {
    return rand() % 100;
}

// Get a random character
char random_character() {
    int index = random_number();
    return charset[index];
}

// Print a line of characters
void print_line() {
    for (int i = 0; i < NUM_CHARS_PER_LINE; i++) {
        // Prints a random character with a certain probability
        if (random_number() < PROBABILITY * 100) {
            printf("%c", random_character());
        }
        else {
            printf(" ");
        }
    }
    printf("\n");
}

// Print a grid of characters
void print_grid() {
    for (int i = 0; i < HEIGHT; i++) {
        print_line();
    }
}

int main() {
    // Seed the random number generator with a fancy seed
    srand(time(NULL) * 1000000007);

    // Start the loop
    for (int i = 0; i < MAX_ITERATIONS; i++) {
        // Print the grid
        print_grid();

        // Sleep for a short time
        sleep(1);
    }

    return 0;
}