//FormAI DATASET v1.0 Category: Memory Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4      // Number of rows in the grid
#define COLS 4      // Number of columns in the grid
#define MIN_VALUE 1 // Minimum value that can be generated in the grid
#define MAX_VALUE 9 // Maximum value that can be generated in the grid

// Function to print the grid
void printGrid(int grid[][COLS], int rows, int cols) {
    printf("  ");
    for (int i = 0; i < cols; i++) {
        printf("%d ", i+1);
    }
    printf("\n");
    for (int i = 0; i < rows; i++) {
        printf("%d ", i+1);
        for (int j = 0; j < cols; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int grid[ROWS][COLS]; // Grid to store randomly generated numbers
    int selected[ROWS][COLS] = {0}; // Grid to track selected cells
    int numSelected = 0; // Counter to track number of selected cells
    int numMatches = 0; // Counter to track number of matches found
    int row1, col1, row2, col2; // Variables to track selected cells
    
    srand(time(NULL)); // Seed the random number generator
    
    // Fill the grid with random values
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
        }
    }
    
    while (numMatches < ((ROWS * COLS) / 2)) { // Loop until all matches found
        
        printGrid(grid, ROWS, COLS); // Print the current state of the grid
        
        // Get the first cell selection from the user
        do {
            printf("Enter row and column of first selection: ");
            scanf("%d %d", &row1, &col1);
            if (selected[row1 - 1][col1 - 1] == 1) {
                printf("Sorry, that cell has already been selected. Please try again.\n");
            }
        } while (selected[row1 - 1][col1 - 1] == 1);
        
        selected[row1 - 1][col1 - 1] = 1; // Mark the cell as selected
        numSelected++; // Increment the selection counter
        
        // Get the second cell selection from the user
        do {
            printf("Enter row and column of second selection: ");
            scanf("%d %d", &row2, &col2);
            if (selected[row2 - 1][col2 - 1] == 1) {
                printf("Sorry, that cell has already been selected. Please try again.\n");
            }
        } while (selected[row2 - 1][col2 - 1] == 1);
        
        selected[row2 - 1][col2 - 1] = 1; // Mark the cell as selected
        numSelected++; // Increment the selection counter
        
        // Check if the selected cells match
        if (grid[row1 - 1][col1 - 1] == grid[row2 - 1][col2 - 1]) {
            printf("Match found!\n");
            numMatches++; // Increment the match counter
        } else {
            printf("Sorry, no match found. Try again.\n");
            selected[row1 - 1][col1 - 1] = 0; // Unmark the first cell
            selected[row2 - 1][col2 - 1] = 0; // Unmark the second cell
            numSelected -= 2; // Decrement the selection counter
        }
    }
    
    printf("Congratulations, you found all matches!\n");
    
    return 0;
}