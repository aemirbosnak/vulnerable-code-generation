//FormAI DATASET v1.0 Category: Memory Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

// Function to print the grid
void printGrid(int grid[ROWS][COLS]) {
    printf("  1 2 3 4\n");
    printf(" ---------\n");

    for (int i = 0; i < ROWS; i++) {
        printf("%d|", i + 1);
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] < 0) {  // No need to display negative values
                printf("  ");
            } else {
                printf("%2d", grid[i][j]);  // print with leading 0 if less than 10
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Function to initialize the grid with random numbers
void initGrid(int grid[ROWS][COLS]) {
    srand(time(NULL));  // Seed for generating random numbers
    int values[ROWS*COLS/2];  // Array to store the random values
    int count = 0;

    // Generate random values, each appearing twice in the grid
    for (int i = 1; i <= ROWS*COLS/2; i++) {
        values[count++] = i;
        values[count++] = i;
    }

    // Shuffle the values
    for (int i = 0; i < ROWS*COLS; i++) {
        int j = rand() % (ROWS*COLS);
        int temp = values[i];
        values[i] = values[j];
        values[j] = temp;
    }

    // Initialize the grid values with the shuffled values
    count = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = values[count++];
        }
    }
}

// Function to reveal a cell
void revealCell(int grid[ROWS][COLS], int row, int col) {
    grid[row][col] = abs(grid[row][col]);  // Change the sign to positive
}

// Function to check if all cells are revealed
int checkWin(int grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] < 0) {  // If there is an unrevealed cell
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int grid[ROWS][COLS];
    initGrid(grid);

    printf("Welcome to the Memory Game!\n");
    printf("Try to reveal all pairs by entering the row and column numbers.\n");
    printf("Enter 0 for both row and column to quit.\n");
    printf("\n");

    int row1, col1, row2, col2;

    while (1) {
        printGrid(grid);

        // Get the first cell coordinates from the user
        printf("Enter the row and column of the first cell: ");
        scanf("%d %d", &row1, &col1);
        if (row1 == 0 && col1 == 0) {  // Check for quitting
            break;
        }
        row1--;
        col1--;

        // Check if the first cell is valid
        if (row1 < 0 || row1 >= ROWS || col1 < 0 || col1 >= COLS || grid[row1][col1] >= 0) {
            printf("Invalid cell, please try again.\n");
            printf("\n");
            continue;
        }

        revealCell(grid, row1, col1);
        printGrid(grid);

        // Get the second cell coordinates from the user
        printf("Enter the row and column of the second cell: ");
        scanf("%d %d", &row2, &col2);
        if (row2 == 0 && col2 == 0) {  // Check for quitting
            break;
        }
        row2--;
        col2--;

        // Check if the second cell is valid
        if (row2 < 0 || row2 >= ROWS || col2 < 0 || col2 >= COLS || grid[row2][col2] >= 0 ||
            (row1 == row2 && col1 == col2)) {
            printf("Invalid cell, please try again.\n");
            printf("\n");
            continue;
        }

        revealCell(grid, row2, col2);
        printGrid(grid);

        // Check if both cells have the same value
        if (grid[row1][col1] == grid[row2][col2]) {
            printf("Voila! You found a pair!\n");
            if (checkWin(grid)) {
                printf("Congratulations! You have won the game!\n");
                break;
            }
        } else {
            printf("Sorry, no match. Try again.\n");
            grid[row1][col1] = -grid[row1][col1];  // Change back to negative sign
            grid[row2][col2] = -grid[row2][col2];
        }

        printf("\n");
    }

    return 0;
}