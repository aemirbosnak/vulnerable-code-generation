//Falcon-180B DATASET v1.0 Category: Sudoku solver ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 9

typedef struct {
    int row;
    int col;
} Cell;

void print_board(int board[SIZE][SIZE]) {
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int is_valid(int board[SIZE][SIZE], int row, int col, int num) {
    for(int i=0; i<SIZE; i++) {
        if(board[row][i] == num || board[i][col] == num)
            return false;
    }
    int start_row = (row - row % 3) / 3 * 3;
    int start_col = (col - col % 3) / 3 * 3;
    for(int i=start_row; i<start_row+3; i++) {
        for(int j=start_col; j<start_col+3; j++) {
            if(board[i][j] == num)
                return false;
        }
    }
    return true;
}

bool solve_sudoku(int board[SIZE][SIZE]) {
    int empty_row, empty_col;
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            if(board[i][j] == 0) {
                empty_row = i;
                empty_col = j;
                break;
            }
        }
        if(empty_row!= -1 && empty_col!= -1)
            break;
    }
    if(empty_row == -1 || empty_col == -1)
        return true;
    for(int num=1; num<=9; num++) {
        if(is_valid(board, empty_row, empty_col, num)) {
            board[empty_row][empty_col] = num;
            if(solve_sudoku(board))
                return true;
            board[empty_row][empty_col] = 0;
        }
    }
    return false;
}

int main() {
    int board[SIZE][SIZE];
    int i, j;
    for(i=0; i<SIZE; i++) {
        for(j=0; j<SIZE; j++) {
            scanf("%d", &board[i][j]);
        }
    }
    if(solve_sudoku(board)) {
        printf("Solution:\n");
        print_board(board);
    } else {
        printf("No solution found.\n");
    }
    return 0;
}