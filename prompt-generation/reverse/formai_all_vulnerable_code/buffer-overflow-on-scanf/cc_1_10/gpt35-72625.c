//FormAI DATASET v1.0 Category: Sudoku solver ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int grid[9][9];

// Print grid
void printGrid()
{
    printf("\n");
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Check if the current number can be placed in the position
int checkValidity(int row, int col, int num)
{
    // Checking if number is in row
    for(int i=0; i<9; i++){
        if(grid[row][i] == num){
            return 0;
        }
    }
    
    // Checking if number is in column
    for(int i=0; i<9; i++){
        if(grid[i][col] == num){
            return 0;
        }
    }
    
    // Checking if number is in the box
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for(int i=startRow; i<startRow+3; i++){
        for(int j=startCol; j<startCol+3; j++){
            if(grid[i][j] == num){
                return 0;
            }
        }
    }
    
    return 1;
}

// Solve Sudoku
int solveSudoku(int row, int col)
{
    if(row == 9){
        return 1;
    }
    
    if(col == 9){
        return solveSudoku(row+1, 0);
    }
    
    if(grid[row][col] != 0){
        return solveSudoku(row, col+1);
    }
    
    for(int i=1; i<=9; i++){
        if(checkValidity(row, col, i)){
            grid[row][col] = i;
            if(solveSudoku(row, col+1)){
                return 1;
            }
        }
        grid[row][col] = 0;
    }
    
    return 0;
}

// Main function
int main()
{
    printf("Welcome to the Surrealist Sudoku Solver!\n");
    printf("Please enter your Sudoku Grid.\n");
    printf("Enter 0 for empty cells.\n");    
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            scanf("%d", &grid[i][j]);
        }
    }
    
    printf("\nYou entered the following Sudoku Grid:\n");
    printGrid();
    
    if(solveSudoku(0, 0)){
        printf("\nThe Surrealist Sudoku Solver has solved the grid!\n");
        printf("\nResult:\n");
        printGrid();
    } else {
        printf("\nThe Surrealist Sudoku Solver could not solve the grid.\n");
    }
    
    return 0;
}