//FormAI DATASET v1.0 Category: Sudoku solver ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 9

void print_board(int board[N][N]) {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

bool is_safe(int board[N][N], int row, int col, int val) {
    // Check row
    for(int i=0; i<N; i++) {
        if(board[row][i] == val) {
            return false;
        }
    }
    // Check col
    for(int i=0; i<N; i++) {
        if(board[i][col] == val) {
            return false;
        }
    }
    // Check subgrid
    int subgrid_row = row - row%3;
    int subgrid_col = col - col%3;
    for(int i=subgrid_row; i<subgrid_row+3; i++) {
        for(int j=subgrid_col; j<subgrid_col+3; j++) {
            if(board[i][j] == val) {
                return false;
            }
        }
    }
    return true;
}

bool solve_sudoku(int board[N][N]) {
    int row, col;
    bool found_empty = false;
    for(int i=0; i<N && !found_empty; i++) {
        for(int j=0; j<N && !found_empty; j++) {
            if(board[i][j] == 0) {
                row = i;
                col = j;
                found_empty = true;
            }
        }
    }
    if(!found_empty) {
        return true;
    }
    for(int val=1; val<=9; val++) {
        if(is_safe(board, row, col, val)) {
            board[row][col] = val;
            if(solve_sudoku(board)) {
                return true;
            }
            board[row][col] = 0;
        }
    }
    return false;
}

int main() {
    int board[N][N] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    printf("Enter the sudoku puzzle (zero for empty cell):\n");
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            scanf("%d", &board[i][j]);
        }
    }
    if(solve_sudoku(board)) {
        printf("\nSolution:\n");
        print_board(board);
    }
    else {
        printf("\nNo solution found.\n");
    }
    return 0;
}