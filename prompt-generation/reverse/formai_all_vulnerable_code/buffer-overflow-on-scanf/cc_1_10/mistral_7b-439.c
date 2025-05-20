//MISTRAL-7B DATASET v1.0 Category: Sudoku solver ; Style: standalone
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 9
#define BLOCK_SIZE 3
#define BLOCKS_PER_ROW 3

typedef struct {
    int value;
    bool is_used;
} cell;

void print_board(cell board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j].value);
        }
        printf("\n");
    }
    printf("\n");
}

bool is_valid(cell board[BOARD_SIZE][BOARD_SIZE], int row, int col, int value) {
    int box_row = row - row % BLOCK_SIZE;
    int box_col = col - col % BLOCK_SIZE;

    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][col].value == value) return false;
        if (board[row][i].value == value) return false;
    }

    for (int i = box_row; i < box_row + BLOCK_SIZE; i++) {
        for (int j = box_col; j < box_col + BLOCK_SIZE; j++) {
            if (i == row && j == col) continue;
            if (board[i][j].value == value) return false;
        }
    }

    return true;
}

bool solve_sudoku(cell board[BOARD_SIZE][BOARD_SIZE], int row, int col) {
    if (col >= BOARD_SIZE) {
        col = 0;
        row++;
    }

    if (row >= BOARD_SIZE) {
        return true;
    }

    if (board[row][col].value != 0) {
        return solve_sudoku(board, row, col + 1);
    }

    for (int value = 1; value <= BOARD_SIZE; value++) {
        if (is_valid(board, row, col, value)) {
            board[row][col].value = value;
            if (solve_sudoku(board, row, col + 1)) {
                return true;
            }
            board[row][col].value = 0;
        }
    }

    return false;
}

int main() {
    cell board[BOARD_SIZE][BOARD_SIZE];
    memset(board, 0, sizeof(board));

    int r, c;
    for (r = 0; r < BOARD_SIZE; r++) {
        for (c = 0; c < BOARD_SIZE; c++) {
            if (r > 0 && (c == 0 || c == BOARD_SIZE - 1)) {
                printf("+-----+");
            }
            if (c > 0) printf("|");
            scanf("%d", &board[r][c].value);
            if (board[r][c].value == 0) {
                board[r][c].is_used = true;
            }
        }
        if (r < BOARD_SIZE - 1) printf("|");
        printf("\n");
    }

    if (!solve_sudoku(board, 0, 0)) {
        printf("No solution exists.\n");
        return 1;
    }

    print_board(board);

    return 0;
}