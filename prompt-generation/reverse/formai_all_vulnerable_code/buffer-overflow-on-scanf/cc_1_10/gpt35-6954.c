//FormAI DATASET v1.0 Category: Sudoku solver ; Style: lively
#include <stdio.h>
#define N 9

int grid[N][N];

// A function to print the complete grid
void printBoard() {
    int i,j;
    printf("\n\n\n\n\n");
    for (i=0;i<N;i++) {
        for (j=0;j<N;j++)
            printf("%2d",grid[i][j]);
        printf("\n");
    }
}

int findEmpty(int *row, int *col) {
    int i,j;
    for (i=0;i<N;i++)
        for (j=0;j<N;j++)
            if (grid[i][j] == 0) {
                *row = i;
                *col = j;
                return 1;
            }
    return 0;
}

// Check if the current number is valid for the given cell
int isValid(int row, int col, int num) {
    int i,j;
    for (i=0;i<N;i++)
        if (grid[row][i] == num || grid[i][col] == num)
            return 0;

    int startRow = row - row%3, startCol = col - col%3;
    for (i=startRow;i<startRow+3;i++)
        for (j=startCol;j<startCol+3;j++)
            if (grid[i][j] == num)
                return 0;
    
    return 1;
}

int solveSudoku() {
    int row, col;
    if (!findEmpty(&row,&col))
        return 1;

    int num;
    for (num=1;num<=N;num++) {
        if (isValid(row,col,num)) {
            grid[row][col] = num;

            if (solveSudoku())
                return 1;

            grid[row][col] = 0;
        }
    }
    return 0;
}

int main() {
    printf("Welcome to the Sudoku Solver!\n");
    printf("Please enter the initial board:\n");

    int i,j;
    for (i=0;i<N;i++)
        for (j=0;j<N;j++)
            scanf("%d",&grid[i][j]);

    if (solveSudoku()) {
        printf("\n\nSolution:\n");
        printBoard();
    } else {
        printf("\n\nNo solution found.\n");
    }

    return 0;
}