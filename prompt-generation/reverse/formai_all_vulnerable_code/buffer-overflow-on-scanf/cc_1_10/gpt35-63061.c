//FormAI DATASET v1.0 Category: Sudoku solver ; Style: inquisitive
#include <stdio.h>

// function to print the sudoku grid
void printSudoku(int sudoku[9][9]) {
    printf("-------------------------\n");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (j % 3 == 0) {
                printf("| ");
            }
            printf("%d ", sudoku[i][j]);
        }
        if (i % 3 == 2) {
            printf("|\n-------------------------\n");
        } else {
            printf("|\n");
        }
    }
}

// function to check if a number is valid in a Sudoku grid
int isValid(int sudoku[9][9], int row, int col, int num) {
    // check if number is already present in the row or column
    for (int i = 0; i < 9; i++) {
        if (sudoku[row][i] == num || sudoku[i][col] == num) {
            return 0;
        }
    }
    
    // check if number is already present in the 3x3 grid
    int startRow = row - (row % 3);
    int startCol = col - (col % 3);
    for (int i = startRow; i < startRow + 3; i++) {
        for (int j = startCol; j < startCol + 3; j++) {
            if (sudoku[i][j] == num) {
                return 0;
            }
        }
    }
    
    // if number is valid, return 1
    return 1;
}

// function to solve the Sudoku grid using backtracking
int solveSudoku(int sudoku[9][9]) {
    int row, col;
    int num = 1;
    int foundUnassigned = 0;
    
    // find the next unassigned cell
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            if (sudoku[row][col] == 0) {
                foundUnassigned = 1;
                break;
            }
        }
        if (foundUnassigned) {
            break;
        }
    }
    
    // if all cells are assigned, return 1
    if (!foundUnassigned) {
        return 1;
    }
    
    // try to assign a number to the unassigned cell
    for (num = 1; num <= 9; num++) {
        if (isValid(sudoku, row, col, num)) {
            sudoku[row][col] = num;
            if (solveSudoku(sudoku)) {
                return 1;
            }
            sudoku[row][col] = 0;
        }
    }
    
    // if no number can be assigned, backtrack
    return 0;
}

int main() {
    int sudoku[9][9];
    
    // input Sudoku grid
    printf("Enter the initial Sudoku grid:\n");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &sudoku[i][j]);
        }
    }
    
    printf("\nInitial Sudoku grid:\n");
    printSudoku(sudoku);
    
    // solve the Sudoku grid using backtracking
    if (solveSudoku(sudoku) == 1) {
        printf("\nSolved Sudoku grid:\n");
        printSudoku(sudoku);
    } else {
        printf("\nNo solution exists for the given Sudoku grid.\n");
    }
    
    return 0;
}