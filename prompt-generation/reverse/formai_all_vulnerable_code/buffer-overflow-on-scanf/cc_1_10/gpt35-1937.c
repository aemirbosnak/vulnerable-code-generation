//FormAI DATASET v1.0 Category: Sudoku solver ; Style: Ada Lovelace
// Ada Lovelace style Sudoku solver in C

#include <stdio.h>

#define SIZE 9

int puzzle[SIZE][SIZE];  // the Sudoku puzzle
int row, col;            // coordinates for empty cells

// function to print the Sudoku puzzle
void printPuzzle() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", puzzle[i][j]);
        }
        printf("\n");
    }
}

// function to check if a number is already present in a row
int checkRow(int num) {
    for (int i = 0; i < SIZE; i++) {
        if (puzzle[row][i] == num) {
            return 0;
        }
    }
    return 1;
}

// function to check if a number is already present in a column
int checkCol(int num) {
    for (int i = 0; i < SIZE; i++) {
        if (puzzle[i][col] == num) {
            return 0;
        }
    }
    return 1;
}

// function to check if a number is already present in a box
int checkBox(int num) {
    int startRow = (row / 3) * 3;  // find the start row of the box
    int startCol = (col / 3) * 3;  // find the start column of the box
    
    for (int i = startRow; i < startRow + 3; i++) {
        for (int j = startCol; j < startCol + 3; j++) {
            if (puzzle[i][j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

// function to check if a number can be placed in a cell
int checkNum(int num) {
    // check if number is already present in row, column or box
    return checkRow(num) && checkCol(num) && checkBox(num);
}

// function to solve the puzzle recursively using backtracking
int solvePuzzle(int r, int c) {
    row = r;
    col = c;
    
    // if all cells are filled, the puzzle is solved
    if (row == SIZE) {
        return 1;
    }
    
    // if cell is not empty, move to next cell
    if (puzzle[row][col] != 0) {
        if (col == SIZE-1) {
            return solvePuzzle(row+1, 0);
        }
        else {
            return solvePuzzle(row, col+1);
        }
    }
    
    // try all possible numbers in the empty cell
    for (int i = 1; i <= SIZE; i++) {
        if (checkNum(i)) {
            puzzle[row][col] = i;
            if (col == SIZE-1) {
                if (solvePuzzle(row+1, 0)) {
                    return 1;
                }
            }
            else {
                if (solvePuzzle(row, col+1)) {
                    return 1;
                }
            }
        }
    }
    
    // if no number fits in the empty cell, backtrack
    puzzle[row][col] = 0;
    return 0;
}

// main function
int main() {
    printf("Enter Sudoku puzzle (use 0 for empty cells):\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &puzzle[i][j]);
        }
    }
    
    if (solvePuzzle(0, 0)) {
        printf("Solved Sudoku puzzle:\n");
        printPuzzle();
    }
    else {
        printf("Failed to solve Sudoku puzzle.\n");
    }
    
    return 0;
}