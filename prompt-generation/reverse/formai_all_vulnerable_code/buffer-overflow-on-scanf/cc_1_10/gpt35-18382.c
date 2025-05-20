//FormAI DATASET v1.0 Category: Memory Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4 // Number of rows in the grid
#define COLS 4 // Number of columns in the grid

// Function to print the grid
void printGrid(int grid[][COLS], int revealed[][COLS]) {
    printf("\n------------------\n");
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(revealed[i][j] == 1) {
                printf("%3d ", grid[i][j]);
            }
            else {
                printf("%3c ", '*');
            }
        }
        printf("\n");
    }
    printf("------------------\n");
}

// Function to initialize the grid with random numbers
void initializeGrid(int grid[][COLS]) {
    int num = 1;
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            grid[i][j] = num++;
        }
    }

    // Shuffle the grid
    srand(time(NULL));
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            int randRow = rand() % ROWS;
            int randCol = rand() % COLS;
            int temp = grid[i][j];
            grid[i][j] = grid[randRow][randCol];
            grid[randRow][randCol] = temp;
        }
    }
}

// Function to play the game
void play(int grid[][COLS]) {
    int revealed[ROWS][COLS] = {0}; // 0 is for unrevealed, 1 is for revealed
    int numPairsRevealed = 0;

    while(numPairsRevealed < ROWS * COLS / 2) {
        printGrid(grid, revealed);

        int row1, col1, row2, col2;

        // Get first position
        printf("\nEnter the row and column of the first number: ");
        scanf("%d %d", &row1, &col1);

        // Check if position is valid
        if(row1 < 0 || row1 >= ROWS || col1 < 0 || col1 >= COLS) {
            printf("Invalid position. Try again.\n");
            continue;
        }

        // Check if number is already revealed
        if(revealed[row1][col1] == 1) {
            printf("Number already revealed. Try again.\n");
            continue;
        }

        revealed[row1][col1] = 1; // Mark number as revealed

        // Get second position
        printf("\nEnter the row and column of the second number: ");
        scanf("%d %d", &row2, &col2);

        // Check if position is valid
        if(row2 < 0 || row2 >= ROWS || col2 < 0 || col2 >= COLS) {
            printf("Invalid position. Try again.\n");
            revealed[row1][col1] = 0; // Unmark first number as revealed
            continue;
        }

        // Check if number is already revealed
        if(revealed[row2][col2] == 1) {
            printf("Number already revealed. Try again.\n");
            revealed[row1][col1] = 0; // Unmark first number as revealed
            continue;
        }

        revealed[row2][col2] = 1; // Mark number as revealed

        // Check if numbers match
        if(grid[row1][col1] == grid[row2][col2]) {
            printf("Match found!\n");
            numPairsRevealed++;
        }
        else {
            printf("No match.\n");
            revealed[row1][col1] = 0; // Unmark first number as revealed
            revealed[row2][col2] = 0; // Unmark second number as revealed
        }
    }

    printf("Congratulations! You won!\n");
}

int main() {
    int grid[ROWS][COLS];
    initializeGrid(grid);
    play(grid);
    return 0;
}