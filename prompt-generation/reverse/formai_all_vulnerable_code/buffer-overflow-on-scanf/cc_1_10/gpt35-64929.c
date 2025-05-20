//FormAI DATASET v1.0 Category: Sudoku solver ; Style: authentic
#include <stdio.h>

#define N 9
#define UNASSIGNED 0

int grid[N][N];

//function to check if the number is already present in the row
int used_in_row(int row, int num) {
    for(int col=0;col<N;col++){
        if(grid[row][col]==num) return 1;
    }
    return 0;
}

//function to check if the number is already present in the column
int used_in_column(int col, int num) {
    for(int row=0;row<N;row++){
        if(grid[row][col]==num) return 1;
    }
    return 0;
}

//function to check if the number is already present in the 3x3 box
int used_in_box(int row_start, int col_start, int num) {
    for(int row=0;row<3;row++){
        for(int col=0;col<3;col++){
            if(grid[row+row_start][col+col_start]==num) return 1;
        }
    }
    return 0;
}

//function to check if it is a safe move
int is_safe(int row, int col, int num) {
    return !used_in_row(row,num) && !used_in_column(col,num) && !used_in_box(row-row%3,col-col%3,num);
}

//function to find the unassigned cell
int find_unassigned(int *row, int *col) {
    for(*row=0;*row<N;(*row)++){
        for(*col=0;*col<N;(*col)++){
            if(grid[*row][*col]==UNASSIGNED) return 1;
        }
    }
    return 0;
}

//function to solve the Sudoku
int solve_sudoku() {
    int row,col;

    if(!find_unassigned(&row,&col)) return 1; //if all cells are assigned
    for(int num=1;num<=9;num++){ //try numbers 1 to 9
        if(is_safe(row,col,num)){ //check if the number can be placed in the cell
            grid[row][col]=num; //place the number in the cell
            if(solve_sudoku()) return 1; //solve the rest of the grid recursively
            grid[row][col]=UNASSIGNED; //undo the move
        }
    }
    return 0;
}

//function to print the grid
void print_grid() {
    for(int row=0;row<N;row++){
        for(int col=0;col<N;col++){
            printf("%d ",grid[row][col]);
        }
        printf("\n");
    }
}

int main() {
    //input the Sudoku grid
    printf("Enter the Sudoku grid(Enter 0 for unassigned cells):\n");
    for(int row=0;row<N;row++){
        for(int col=0;col<N;col++){
            scanf("%d",&grid[row][col]);
        }
    }
    //solve the Sudoku
    if(solve_sudoku()){
        printf("Solution:\n");
        print_grid();
    }
    else{
        printf("No solution exists.\n");
    }
    return 0;
}