//FormAI DATASET v1.0 Category: Sudoku solver ; Style: unmistakable
#include <stdio.h>

int grid[9][9];

// Function to check if a value exists in row
int checkRow(int row, int num){
    for(int col = 0; col < 9; col++){
        if(grid[row][col] == num){
            return 1;
        }
    }
    return 0;
}

// Function to check if a value exists in column
int checkCol(int col, int num){
    for(int row = 0; row < 9; row++){
        if(grid[row][col] == num){
            return 1;
        }
    }
    return 0;
}

// Function to check if a value exists in 3x3 box
int checkBox(int boxStartRow, int boxStartCol, int num){
    for(int row = 0; row < 3; row++){
        for(int col = 0; col < 3; col++){
            if(grid[row+boxStartRow][col+boxStartCol] == num){
                return 1;
            }
        }
    }
    return 0;
}

// Function to check if a value is safe to place in a cell
int isSafe(int row, int col, int num){
    if(!checkRow(row, num) && !checkCol(col, num) && !checkBox(row-row%3, col-col%3, num)){
        return 1;
    }
    return 0;
}

// Function to print the grid on console
void printGrid(){
    printf("\n\t\tSudoku Solver\n\n");
    for(int row = 0; row < 9; row++){
        if(row%3 == 0){
            printf("\t\t|-------|-------|-------|\n");
        }
        for(int col = 0; col < 9; col++){
            if(col%3 == 0){
                printf("\t\t| ");
            }
            printf("%d ", grid[row][col]);
            if(col == 8){
                printf("|");
            }
        }
        printf("\n");
        if(row == 8){
            printf("\t\t|-------|-------|-------|\n");
        }
    }
}

// Function to find an empty cell
int findEmptyCell(int *row, int *col){
    for(*row = 0; *row < 9; (*row)++){
        for(*col = 0; *col < 9; (*col)++){
            if(grid[*row][*col] == 0){
                return 1;
            }
        }
    }
    return 0;
}

// Function to solve the grid using backtracking algorithm
int solveSudoku(){
    int row, col;
    if(!findEmptyCell(&row, &col)){
        return 1; // Solved
    }
    for(int num = 1; num <= 9; num++){
        if(isSafe(row, col, num)){
            grid[row][col] = num;
            if(solveSudoku()){
                return 1; // Solved
            }
            grid[row][col] = 0;
        }
    }
    return 0; // Not solved
}

int main(){
    // Taking input the grid values to solve
    printf("Enter 9x9 Sudoku puzzle (0 for empty cells):\n");
    for(int row = 0; row < 9; row++){
        for(int col = 0; col < 9; col++){
            scanf("%d", &grid[row][col]);
        }
    }
    if(solveSudoku()){
        printGrid();
    } else{
        printf("\n\t\tPlease check the input values!\n");
    }
    return 0;
}