//Falcon-180B DATASET v1.0 Category: Sudoku solver ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_SIZE 9

//Function to check if the value is valid
int is_valid(int **board, int row, int col, int val){
    int i,j;
    for(i=0;i<MAX_SIZE;i++){
        if(board[row][i]==val)
            return 0;
    }
    for(j=0;j<MAX_SIZE;j++){
        if(board[i][j]==val)
            return 0;
    }
    int box_row = row - row % 3;
    int box_col = col - col % 3;
    for(i=box_row;i<box_row+3;i++){
        for(j=box_col;j<box_col+3;j++){
            if(board[i][j]==val)
                return 0;
        }
    }
    return 1;
}

//Function to solve the sudoku
void solve_sudoku(int **board){
    int i,j,row,col;
    int count = 0;
    srand(time(NULL));
    while(count<MAX_SIZE*MAX_SIZE){
        row = rand() % MAX_SIZE;
        col = rand() % MAX_SIZE;
        if(board[row][col]==0){
            for(i=1;i<=MAX_SIZE;i++){
                if(is_valid(board,row,col,i)){
                    board[row][col] = i;
                    count++;
                    break;
                }
            }
        }
    }
    for(i=0;i<MAX_SIZE;i++){
        for(j=0;j<MAX_SIZE;j++){
            printf("%d ",board[i][j]);
        }
        printf("\n");
    }
}

//Function to print the sudoku
void print_sudoku(int **board){
    int i,j;
    for(i=0;i<MAX_SIZE;i++){
        for(j=0;j<MAX_SIZE;j++){
            printf("%d ",board[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int i,j;
    int **board = (int **)malloc(MAX_SIZE*sizeof(int *));
    for(i=0;i<MAX_SIZE;i++){
        board[i] = (int *)malloc(MAX_SIZE*sizeof(int));
        for(j=0;j<MAX_SIZE;j++){
            board[i][j] = 0;
        }
    }
    printf("Enter the sudoku:\n");
    for(i=0;i<MAX_SIZE;i++){
        for(j=0;j<MAX_SIZE;j++){
            scanf("%d",&board[i][j]);
        }
    }
    printf("Solved Sudoku:\n");
    solve_sudoku(board);
    print_sudoku(board);
    return 0;
}