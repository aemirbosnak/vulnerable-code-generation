//Falcon-180B DATASET v1.0 Category: Sudoku solver ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 9

typedef struct {
    int row;
    int col;
} Cell;

void print_board(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

bool is_valid(int board[SIZE][SIZE], int row, int col, int num) {
    int start_row = row - row % SIZE;
    int start_col = col - col % SIZE;

    for (int i = start_row; i < start_row + SIZE; i++) {
        for (int j = start_col; j < start_col + SIZE; j++) {
            if (board[i][j] == num)
                return false;
        }
    }

    return true;
}

void find_empty_cell(int board[SIZE][SIZE], Cell *cell) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                cell->row = i;
                cell->col = j;
                return;
            }
        }
    }
}

bool solve_sudoku(int board[SIZE][SIZE]) {
    Cell cell;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                find_empty_cell(board, &cell);
                for (int num = 1; num <= SIZE; num++) {
                    if (is_valid(board, cell.row, cell.col, num)) {
                        board[cell.row][cell.col] = num;
                        if (solve_sudoku(board))
                            return true;
                        board[cell.row][cell.col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() {
    int board[SIZE][SIZE];
    int i, j;

    printf("Enter the initial board:\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    if (solve_sudoku(board)) {
        printf("Solved board:\n");
        print_board(board);
    } else {
        printf("No solution found.\n");
    }

    return 0;
}