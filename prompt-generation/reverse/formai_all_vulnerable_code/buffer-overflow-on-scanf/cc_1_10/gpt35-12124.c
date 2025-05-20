//FormAI DATASET v1.0 Category: Sudoku solver ; Style: safe
#include<stdio.h>
#include<stdlib.h>

#define N 9

int puzzle[N][N];

void inputSudoku() {
    printf("Enter the puzzle:\n");
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&puzzle[i][j]);
        }
    }
    printf("\n\n\nThe Entered Sudoku Puzzle:\n");
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%d ",puzzle[i][j]);
        }
        printf("\n");
    }
}

int valid_row_col_box(int r, int c, int num) {
    for(int i=0;i<N;i++){
        if (puzzle[r][i] == num) return 0; // Check Row
        if (puzzle[i][c] == num) return 0; // Check Column
    }
    int boxRowStart = r - r%3, boxColStart = c - c%3;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if (puzzle[i+boxRowStart][j+boxColStart] == num) return 0; // Check Box
        }
    }
    return 1;
}

int solvedSudoku(int row, int col) {
    if(row==N-1 && col==N) return 1;
    if(col==N) {
        row++;
        col=0;
    }
    if(puzzle[row][col]>0) return solvedSudoku(row, col+1);
    for(int i=1;i<=N;i++) {
        if(valid_row_col_box(row, col, i)==1){
            puzzle[row][col] = i;
            if(solvedSudoku(row, col+1)==1) return 1;
        }
        puzzle[row][col]=0; // backtracking
    }
    return 0;
}

int main() {
    inputSudoku();
    if(solvedSudoku(0,0)==1){
        printf("\n\n\nSolved Sudoku Puzzle\n");
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                printf("%d ",puzzle[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}