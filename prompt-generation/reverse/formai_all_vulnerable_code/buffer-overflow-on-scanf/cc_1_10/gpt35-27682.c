//FormAI DATASET v1.0 Category: Sudoku solver ; Style: peaceful
#include <stdio.h>
#define N 9 // size of grid

void printGrid(int grid[N][N]) { // helper function
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%d ", grid[i][j]); // print the grid
        }
        printf("\n");
    }
}

int findEmpty(int grid[N][N], int *row, int *col) { // helper function
    for(*row = 0; *row < N; (*row)++){
        for(*col = 0; *col < N; (*col)++){
            if(grid[*row][*col] == 0){ //if cell is empty
                return 1; //empty cell found
            }
        }
    }
    return 0; //no empty cell
}

int noConflict(int grid[N][N], int row, int col, int num) { //helper function
    //check row for the number
    for(int i = 0; i < N; i++) {
        if(grid[row][i] == num) {
            return 0;
        }
    }
    //check column for the number
    for(int i = 0; i < N; i++) {
        if(grid[i][col] == num) {
            return 0;
        }
    }
    //check 3x3 grid for the number
    int startRow = row - row%3;
    int startCol = col - col%3;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(grid[startRow+i][startCol+j] == num) {
                return 0;
            }
        }
    }
    //no conflict found
    return 1;
}

int solveSudoku(int grid[N][N]) {
    int row, col;
    if(!findEmpty(grid, &row, &col)) {
        return 1; //no empty cell left
    }
    for(int num = 1; num <= N; num++) {
        if(noConflict(grid, row, col, num)) {
            grid[row][col] = num; //try a number in empty cell
            if(solveSudoku(grid)) {
                return 1; //succeed if the number works
            }
            grid[row][col] = 0; //backtrack
        }
    }
    return 0; //no solution found
}

int main() {
    int grid[N][N] = {{0, 0, 0, 0, 0, 0, 0, 0, 0}, //initialize empty grid
                     {0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0}};
    printf("Enter the unsolved Sudoku puzzle (Enter 0 for empty cells):\n"); 
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", &grid[i][j]); //input the puzzle
        }
    }
    if(solveSudoku(grid)) {
        printf("\nThe solution grid is:\n"); 
        printGrid(grid); //if solution exists, output the solved grid
    } else {
        printf("\nNo solution exists.\n"); //solution does not exist
    }
    return 0;
}