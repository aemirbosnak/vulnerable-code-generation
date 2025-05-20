//FormAI DATASET v1.0 Category: Sudoku solver ; Style: irregular
#include <stdio.h>
#include <stdbool.h>

int grid[9][9];

bool row_check(int row, int num){
    for(int col=0; col<9; col++){
        if(grid[row][col] == num){
            return true;
        }
    }
    return false;
}

bool col_check(int col, int num){
    for(int row=0; row<9; row++){
        if(grid[row][col] == num){
            return true;
        }
    }
    return false;
}

bool box_check(int row, int col, int num){
    int row_start = row - row%3;
    int col_start = col - col%3;
    
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(grid[row_start+i][col_start+j] == num){
                return true;
            }
        }
    }
    return false;
}

bool is_valid(int row, int col, int num){
    return !row_check(row, num) && !col_check(col, num) && !box_check(row, col, num);
}

bool find_unassigned(int *row, int *col){
    for(*row=0; *row<9; (*row)++){
        for(*col=0; *col<9; (*col)++){
            if(grid[*row][*col] == 0){
                return true;
            }
        }
    }
    return false;
}

bool solve_sudoku(){
    int row, col;

    if(!find_unassigned(&row, &col)){
        return true;
    }

    for(int num=1; num<=9; num++){
        if(is_valid(row, col, num)){
            grid[row][col] = num;

            if(solve_sudoku()){
                return true;
            }

            grid[row][col] = 0;
        }
    }
    return false;
}

int main(){
    printf("Enter the sudoku grid (Use 0 for empty cells): ");
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            scanf("%d", &grid[i][j]);
        }
    }

    printf("\nEntered sudoku grid:\n");
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    if(solve_sudoku()){
        printf("\nSolution:\n");
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
    }
    else{
        printf("No solution found.");
    }

    return 0;
}