//Code Llama-13B DATASET v1.0 Category: Bingo Simulator ; Style: careful
/*
* C Bingo Simulator
*
* Generates a random sequence of numbers from 1 to 90 and prompts the user to mark off the numbers
* as they are called. The game ends when all numbers are called or when the user correctly guesses
* a 5-number sequence.
*
* Usage: bingo [<number of rows> [<number of columns>]]
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 90
#define MAX_ROWS 10
#define MAX_COLUMNS 10

// Function to generate a random number between 1 and 90
int generate_random_number(void) {
    return rand() % 90 + 1;
}

// Function to display a 2D array of numbers
void display_grid(int grid[MAX_ROWS][MAX_COLUMNS]) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLUMNS; j++) {
            printf("%3d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the user has won
int check_win(int grid[MAX_ROWS][MAX_COLUMNS]) {
    // Check rows
    for (int i = 0; i < MAX_ROWS; i++) {
        int row_win = 1;
        for (int j = 0; j < MAX_COLUMNS; j++) {
            if (grid[i][j] == 0) {
                row_win = 0;
                break;
            }
        }
        if (row_win) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < MAX_COLUMNS; j++) {
        int col_win = 1;
        for (int i = 0; i < MAX_ROWS; i++) {
            if (grid[i][j] == 0) {
                col_win = 0;
                break;
            }
        }
        if (col_win) {
            return 1;
        }
    }

    // Check diagonals
    int diag_win = 1;
    for (int i = 0; i < MAX_ROWS; i++) {
        if (grid[i][i] == 0) {
            diag_win = 0;
            break;
        }
    }
    if (diag_win) {
        return 1;
    }

    diag_win = 1;
    for (int i = 0; i < MAX_ROWS; i++) {
        if (grid[i][MAX_COLUMNS - i - 1] == 0) {
            diag_win = 0;
            break;
        }
    }
    if (diag_win) {
        return 1;
    }

    return 0;
}

int main(int argc, char *argv[]) {
    // Initialize random number generator
    srand(time(NULL));

    // Set number of rows and columns
    int rows = MAX_ROWS;
    int columns = MAX_COLUMNS;
    if (argc > 1) {
        rows = atoi(argv[1]);
    }
    if (argc > 2) {
        columns = atoi(argv[2]);
    }

    // Initialize grid
    int grid[MAX_ROWS][MAX_COLUMNS];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            grid[i][j] = generate_random_number();
        }
    }

    // Display grid
    display_grid(grid);

    // Game loop
    while (1) {
        // Generate random number
        int number = generate_random_number();

        // Mark number on grid
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (grid[i][j] == number) {
                    grid[i][j] = 0;
                    break;
                }
            }
        }

        // Check for win
        if (check_win(grid)) {
            printf("You win!\n");
            break;
        }

        // Display grid
        display_grid(grid);
    }

    return 0;
}