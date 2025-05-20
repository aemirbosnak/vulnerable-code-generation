//FormAI DATASET v1.0 Category: Sudoku solver ; Style: dynamic
#include<stdio.h>

int sudoku[9][9]; // global variable to store soduku

// function to check if the number can be placed in the cell or not
int canPlace(int x, int y, int num) {
    // check row and column
    for(int i=0; i<9; i++) {
        if(sudoku[x][i] == num || sudoku[i][y] == num) {
            return 0; // num cannot be placed
        }
    }
    // check cell
    int cellX = (x/3) * 3; // first column of the current cell
    int cellY = (y/3) * 3; // first row of the current cell
    for(int i=cellX; i<cellX+3; i++) {
        for(int j=cellY; j<cellY+3; j++) {
            if(sudoku[i][j] == num) {
                return 0; // num cannot be placed
            }
        }
    }
    return 1; // num can be placed
}

// function to solve sudoku using backtracking
int solveSudoku(int x, int y) {
    if(x == 9) {
        x = 0;
        y++;
        if(y == 9)
            return 1; // solved
    }
    if(sudoku[x][y] != 0)
        return solveSudoku(x+1, y);
    for(int i=1; i<=9; i++) {
        if(canPlace(x, y, i)) {
            sudoku[x][y] = i;
            if(solveSudoku(x+1, y))
                return 1; // solved
            sudoku[x][y] = 0; // backtrack
        }
    }
    return 0; // could not solve
}

int main() {
    printf("Enter the sudoku puzzle (0 for empty cells):\n");
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            scanf("%d", &sudoku[i][j]);
        }
    }
    if(solveSudoku(0, 0)) {
        printf("\nSolution:\n");
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                printf("%d ", sudoku[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("\nCould not solve.\n");
    }
    return 0;
}