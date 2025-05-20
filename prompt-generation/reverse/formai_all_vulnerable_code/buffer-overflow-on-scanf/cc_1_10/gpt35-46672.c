//FormAI DATASET v1.0 Category: Sudoku solver ; Style: realistic
#include<stdio.h>
#define N 9

int sudoku[N][N];

int is_safe(int row, int col, int num) {
    int i, j;
    
    // check row
    for(i = 0; i < N; i++) {
        if(sudoku[row][i] == num)
            return 0;
    }
    
    // check column
    for(i = 0; i < N; i++) {
        if(sudoku[i][col] == num)
            return 0;
    }
    
    // check subgrid
    int row_start = row - row%3;
    int col_start = col - col%3;
    for(i = row_start; i < row_start+3; i++) {
        for(j = col_start; j < col_start+3; j++) {
            if(sudoku[i][j] == num)
                return 0;
        }
    }
    
    // if none of the cases are met, return 1
    return 1;
}

int solve_sudoku(int row, int col) {
    int num, i;
    
    if(row == N-1 && col == N)
        return 1;
    
    if(col == N) {
        row++;
        col = 0;
    }
    
    if(sudoku[row][col] > 0)
        return solve_sudoku(row, col+1);
    
    for(num = 1; num <= N; num++) {
        if(is_safe(row, col, num)) {
            sudoku[row][col] = num;
            if(solve_sudoku(row, col+1))
                return 1;
            sudoku[row][col] = 0;
        }
    }
    
    return 0;
}

void display() {
    int i, j;
    printf("\nSUDOKU: \n\n");
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++)
            printf("%d ", sudoku[i][j]);
        printf("\n");
    }
}

int main() {
    int i, j;
    
    // input sudoku
    printf("Enter the sudoku puzzle (use 0 for empty cells):\n");
    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            scanf("%d", &sudoku[i][j]);
    
    // solve sudoku
    if(solve_sudoku(0,0))
        display();
    else
        printf("Invalid Sudoku");
    
    return 0;
}