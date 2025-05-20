//FormAI DATASET v1.0 Category: Sudoku solver ; Style: brave
#include <stdio.h>
#include <stdbool.h>

#define ROWS 9
#define COLS 9

int grid[ROWS][COLS];

bool is_valid(int row, int col, int num){
    // Check if the number exists in the current row
    for(int i=0; i<COLS; i++){
        if(grid[row][i] == num){
            return false;
        }
    }
    
    // Check if the number exists in the current column
    for(int i=0; i<ROWS; i++){
        if(grid[i][col] == num){
            return false;
        }
    }
    
    // Check if the number exists in the current 3x3 box
    int box_row = row - row % 3;
    int box_col = col - col % 3;
    for(int i=box_row; i<box_row+3; i++){
        for(int j=box_col; j<box_col+3; j++){
            if(grid[i][j] == num){
                return false;
            }
        }
    }
    
    // If the number does not violate any rules, it is valid
    return true;
}

bool find_unassigned(int* row, int* col){
    for(*row=0; *row<ROWS; (*row)++){
        for(*col=0; *col<COLS; (*col)++){
            if(grid[*row][*col] == 0){
                return true;
            }
        }
    }
    return false;
}

bool solve_sudoku(){
    int row, col;
    
    // Find the first unassigned cell
    if(!find_unassigned(&row, &col)){
        return true; // Puzzle has been solved!
    }
    
    // Try all numbers from 1 to 9 in the unassigned cell
    for(int num=1; num<=9; num++){
        // Check if the number is valid
        if(is_valid(row, col, num)){
            grid[row][col] = num;
            // Recursive call to solve_sudoku on the updated grid
            if(solve_sudoku()){
                return true;
            }
            // Backtrack if puzzle could not be solved with current number
            grid[row][col] = 0;
        }
    }
    // Trigger backtracking
    return false;
}

void print_grid(){
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main(){
    printf("Enter the Sudoku puzzle (0 for empty cells):\n");
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            scanf("%d", &grid[i][j]);
        }
    }
    
    if(solve_sudoku()){
        printf("\nThe solution to the Sudoku puzzle is:\n");
        print_grid();
    }
    else{
        printf("\nCould not solve the Sudoku puzzle.\n");
    }
    
    return 0;
}