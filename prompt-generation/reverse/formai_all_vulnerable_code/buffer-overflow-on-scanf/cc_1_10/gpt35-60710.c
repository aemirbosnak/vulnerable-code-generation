//FormAI DATASET v1.0 Category: Sudoku solver ; Style: future-proof
#include<stdio.h>
#include<stdlib.h>

int grid[9][9];

void print_grid(){
    int i,j;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            printf("%d ",grid[i][j]);
        }
        printf("\n");
    }
}

int is_valid(int row, int col, int num){
    int i,j;
    for(i=0;i<9;i++){
        if(grid[i][col] == num)
            return 0;
        if(grid[row][i] == num)
            return 0;
    }
    int r = row - row%3;
    int c = col - col%3;
    for(i=r;i<r+3;i++){
        for(j=c;j<c+3;j++){
            if(grid[i][j] == num)
                return 0;
        }
    }
    return 1;
}

int solve(int row, int col){
    if(row == 9){
        return 1;
    }
    if(col == 9){
        return solve(row+1, 0);
    }

    if(grid[row][col] != 0){
        return solve(row, col+1);
    }

    int num;

    for(num=1;num<=9;num++){
        if(is_valid(row,col,num)){
            grid[row][col] = num;
            if(solve(row,col+1)){
                return 1;
            }
            grid[row][col] = 0;
        }
    }

    return 0;
}

int main(){
    printf("Enter Sudoku grid (0 for blank cells):\n");
    int i,j;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            scanf("%d",&grid[i][j]);
        }
    }

    if(solve(0,0)){
        printf("Solved Sudoku:\n");
        print_grid();
    }
    else{
        printf("Invalid Sudoku!\n");
    }

    return 0;
}