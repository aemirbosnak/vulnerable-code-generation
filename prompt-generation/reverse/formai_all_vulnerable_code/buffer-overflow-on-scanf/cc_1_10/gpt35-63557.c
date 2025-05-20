//FormAI DATASET v1.0 Category: Sudoku solver ; Style: standalone
#include <stdio.h>

// Function to print the Sudoku array
void printSudoku(int sudoku[9][9]) {
    for(int i=0;i<9;i++) {
        for(int j=0;j<9;j++) {
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a number is safe to be placed
int isSafe(int sudoku[9][9], int row, int col, int num) {
    for(int i=0;i<9;i++) {
        if(sudoku[row][i] == num || sudoku[i][col] == num)
            return 0;
    }
    int start_row = (row/3)*3, start_col = (col/3)*3;
    for(int i=start_row;i<start_row+3;i++) {
        for(int j=start_col;j<start_col+3;j++) {
            if(sudoku[i][j] == num)
                return 0;
        }
    }
    return 1;
}

// Function to solve the Sudoku puzzle using Backtracking
int solveSudoku(int sudoku[9][9], int row, int col) {
    if(row==8 && col==9) return 1; // If we have reached the end
    if(col==9) {
        col=0;
        row++;
    }
    if(sudoku[row][col] != 0) return solveSudoku(sudoku, row, col+1); // If the cell is already filled
        
    for(int i=1;i<=9;i++) { // Try out the possible values
        if(isSafe(sudoku, row, col, i)) {
            sudoku[row][col] = i;
            if(solveSudoku(sudoku, row, col+1))
                return 1;
        }
        sudoku[row][col] = 0; // Backtracking step
    }
    return 0;
}

int main() {
    int sudoku[9][9];
    printf("Enter the initial Sudoku board (use 0 for empty cells):\n");
    for(int i=0;i<9;i++) {
        for(int j=0;j<9;j++) {
            scanf("%d", &sudoku[i][j]);
        }
    }
    if(solveSudoku(sudoku, 0, 0)) {
        printf("Solution:\n");
        printSudoku(sudoku);
    }
    else {
        printf("No solution exists!\n");
    }
    return 0;
}