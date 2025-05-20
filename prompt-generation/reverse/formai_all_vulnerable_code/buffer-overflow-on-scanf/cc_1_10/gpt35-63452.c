//FormAI DATASET v1.0 Category: Sudoku solver ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define GRID_SIZE 9

int grid[GRID_SIZE][GRID_SIZE];

// Function to print the Sudoku grid
void printGrid() {
    for(int i=0; i<GRID_SIZE; i++) {
        for(int j=0; j<GRID_SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the given number is already present
// in the given row
int checkRow(int row, int num) {
    for(int i=0; i<GRID_SIZE; i++) {
        if(grid[row][i] == num) {
            return 1;
        }
    }
    return 0;
}

// Function to check if the given number is already present
// in the given column
int checkCol(int col, int num) {
    for(int i=0; i<GRID_SIZE; i++) {
        if(grid[i][col] == num) {
            return 1;
        }
    }
    return 0;
}

// Function to check if the given number is already present
// in the given 3x3 box
int checkBox(int row, int col, int num) {
    row = row - row % 3;
    col = col - col % 3;
    
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(grid[row+i][col+j] == num) {
                return 1;
            }
        }
    }
    return 0;
}

// Function to check if the given number can be placed in
// the given cell
int canPlace(int row, int col, int num) {
    if(checkRow(row, num) || checkCol(col, num) || checkBox(row, col, num)) {
        return 0;
    }
    return 1;
}

// Function to solve the Sudoku
int solve() {
    int row, col;
    int found = 0;
    
    // Look for an empty cell
    for(row=0; row<GRID_SIZE; row++) {
        for(col=0; col<GRID_SIZE; col++) {
            if(grid[row][col] == 0) {
                found = 1;
                break;
            }
        }
        if(found) {
            break;
        }
    }
    
    // If no empty cell is found, the Sudoku is solved
    if(!found) {
        return 1;
    }
    
    // Try placing numbers from 1 to 9 in the empty cell
    for(int num=1; num<=9; num++) {
        if(canPlace(row, col, num)) {
            grid[row][col] = num;
            if(solve()) {
                return 1;
            }
            grid[row][col] = 0;
        }
    }
    
    // If no number can be placed in the empty cell, backtrack
    return 0;
}

int main() {
    // Input the Sudoku grid from the user
    printf("Enter the Sudoku grid:\n");
    for(int i=0; i<GRID_SIZE; i++) {
        for(int j=0; j<GRID_SIZE; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    
    // Solve the Sudoku
    if(solve()) {
        printf("Solution:\n");
        printGrid();
    } else {
        printf("No solution exists.\n");
    }
    
    return 0;
}