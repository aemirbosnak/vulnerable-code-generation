//Falcon-180B DATASET v1.0 Category: Sudoku solver ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define SIZE 9

void print_grid(int grid[SIZE][SIZE]) {
    for(int i=0;i<SIZE;i++) {
        for(int j=0;j<SIZE;j++) {
            printf("%d ",grid[i][j]);
        }
        printf("\n");
    }
}

bool is_valid(int grid[SIZE][SIZE],int row,int col,int num) {
    for(int i=0;i<SIZE;i++) {
        if(grid[row][i]==num || grid[i][col]==num) {
            return false;
        }
    }
    int sub_row=row-(row%3);
    int sub_col=col-(col%3);
    for(int i=sub_row;i<sub_row+3;i++) {
        for(int j=sub_col;j<sub_col+3;j++) {
            if(grid[i][j]==num) {
                return false;
            }
        }
    }
    return true;
}

bool solve_sudoku(int grid[SIZE][SIZE]) {
    int row,col;
    for(row=0;row<SIZE;row++) {
        for(col=0;col<SIZE;col++) {
            if(grid[row][col]==0) {
                for(int num=1;num<=SIZE;num++) {
                    if(is_valid(grid,row,col,num)) {
                        grid[row][col]=num;
                        if(solve_sudoku(grid)) {
                            return true;
                        } else {
                            grid[row][col]=0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() {
    int grid[SIZE][SIZE];
    int row,col;
    for(row=0;row<SIZE;row++) {
        for(col=0;col<SIZE;col++) {
            scanf("%d",&grid[row][col]);
        }
    }
    if(solve_sudoku(grid)) {
        print_grid(grid);
    } else {
        printf("No solution exists\n");
    }
    return 0;
}