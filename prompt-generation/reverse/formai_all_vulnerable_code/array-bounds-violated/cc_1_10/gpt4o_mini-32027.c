//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define GRID_SIZE 4
#define TOTAL_PAIRS (GRID_SIZE * GRID_SIZE) / 2
#define MAX_TRIES 30

char grid[GRID_SIZE][GRID_SIZE];
char display[GRID_SIZE][GRID_SIZE];
int pairs_found = 0;

// Function to initialize the memory game grid
void initialize_grid() {
    char letters[TOTAL_PAIRS];
    for (int i = 0; i < TOTAL_PAIRS; i++) {
        letters[i] = 'A' + i; // Fill with letters A, B, C, ...
    }

    // Shuffle the letters and place them on the grid
    int index = 0;
    for (int i = 0; i < TOTAL_PAIRS; i++) {
        grid[index / GRID_SIZE][index % GRID_SIZE] = letters[i];
        grid[index / GRID_SIZE + 1][index % GRID_SIZE] = letters[i];
        index += 2;
    }

    // Shuffle the grid
    for (int i = 0; i < GRID_SIZE; i++)
        for (int j = 0; j < GRID_SIZE; j++)
            display[i][j] = '*';

    // Randomizing positions of the letters
    srand(time(NULL));
    for (int i = 0; i < GRID_SIZE * GRID_SIZE; i++) {
        int r1 = rand() % (GRID_SIZE * GRID_SIZE);
        int r2 = rand() % (GRID_SIZE * GRID_SIZE);
        char temp = grid[r1 / GRID_SIZE][r1 % GRID_SIZE];
        grid[r1 / GRID_SIZE][r1 % GRID_SIZE] = grid[r2 / GRID_SIZE][r2 % GRID_SIZE];
        grid[r2 / GRID_SIZE][r2 % GRID_SIZE] = temp;
    }
}

// Function to display the current state of the game
void display_grid() {
    printf("\nCurrent Grid State:\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf(" %c ", display[i][j]);
        }
        printf("\n");
    }
}

// Function to reveal a cell in the grid
void reveal(int row, int col) {
    display[row][col] = grid[row][col];
}

// Function to hide a cell in the grid
void hide(int row, int col) {
    display[row][col] = '*';
}

// Function to check if two cells match
int check_match(int row1, int col1, int row2, int col2) {
    return grid[row1][col1] == grid[row2][col2];
}

// Function to play the memory game
void play_game() {
    int maximum_tries = MAX_TRIES;

    while (pairs_found < TOTAL_PAIRS && maximum_tries > 0) {
        display_grid();
        
        int row1, col1, row2, col2;
        printf("Enter coordinates for first card (row col): ");
        scanf("%d %d", &row1, &col1);
        reveal(row1, col1);
        display_grid();

        printf("Enter coordinates for second card (row col): ");
        scanf("%d %d", &row2, &col2);
        reveal(row2, col2);
        display_grid();
        
        if (check_match(row1, col1, row2, col2)) {
            printf("Match found: %c!\n", grid[row1][col1]);
            pairs_found++;
        } else {
            printf("No match! Try again.\n");
            hide(row1, col1);
            hide(row2, col2);
        }
        
        maximum_tries--;
        printf("Tries left: %d\n", maximum_tries);
    }

    if (pairs_found == TOTAL_PAIRS) {
        printf("Congratulations! You've found all pairs!\n");
    } else {
        printf("Game over! You failed to find all pairs in %d tries.\n", MAX_TRIES);
    }
}

int main() {
    initialize_grid();
    play_game();
    return 0;
}