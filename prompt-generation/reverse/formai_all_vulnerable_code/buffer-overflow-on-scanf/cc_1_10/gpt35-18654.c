//FormAI DATASET v1.0 Category: Sudoku solver ; Style: Ada Lovelace
#include <stdio.h>

#define UNASSIGNED 0
#define N 9

int grid[N][N];

// function to print the Sudoku grid
void printGrid() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// function to check if the current number can be placed in the given row and column
int check(int row, int col, int num) {
    // check row
    for(int i=0; i<N; i++) {
        if(grid[row][i] == num) return 0;
    }
    // check column
    for(int i=0; i<N; i++) {
        if(grid[i][col] == num) return 0;
    }
    // check subgrid
    int rowStart = row - row % 3;
    int colStart = col - col % 3;
    for(int i=rowStart; i<rowStart+3; i++) {
        for(int j=colStart; j<colStart+3; j++) {
            if(grid[i][j] == num) return 0;
        }
    }
    return 1;
}

// function to find the next unassigned cell
int findUnassigned(int *row, int *col) {
    for(*row=0; *row<N; (*row)++) {
        for(*col=0; *col<N; (*col)++) {
            if(grid[*row][*col] == 0) {
                return 1;
            }
        }
    }
    return 0;
}

// function to solve the Sudoku puzzle
int sudokuSolver() {
    int row, col;
    if(!findUnassigned(&row, &col)) return 1; // all cells are assigned

    // try values from 1 to 9
    for(int num=1; num<=9; num++) {
        if(check(row, col, num)) {
            grid[row][col] = num; // assign the value 
            if(sudokuSolver()) return 1; // solve the next cell recursively
            grid[row][col] = UNASSIGNED; // backtrack if assignment was incorrect
        }
    }
    return 0; // puzzle cannot be solved
}

int main() {
    // input the Sudoku puzzle
    printf("Enter the Sudoku puzzle (0 for empty cells):\n");
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    // solve the Sudoku puzzle
    if(sudokuSolver()) {
        printf("Solution:\n");
        printGrid();
    }
    else {
        printf("No solution exists.\n");
    }
    return 0;
}