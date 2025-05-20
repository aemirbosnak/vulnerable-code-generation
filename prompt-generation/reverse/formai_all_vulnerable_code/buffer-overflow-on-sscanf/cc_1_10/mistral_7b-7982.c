//MISTRAL-7B DATASET v1.0 Category: Sudoku solver ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 9

void print_board(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
            if (j < SIZE - 1)
                printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) {
            for (int j = 0; j < SIZE; j++) {
                if (j == 0)
                    printf("-");
                else
                    printf("---");
            }
            printf("\n");
        }
    }
}

bool is_valid(int board[SIZE][SIZE], int row, int col, int num) {
    for (int i = 0; i < SIZE; i++) {
        if (board[row][i] == num || board[i][col] == num)
            return false;
    }

    int box_row = row - row % 3;
    int box_col = col - col % 3;

    for (int i = box_row; i < box_row + 3; i++) {
        for (int j = box_col; j < box_col + 3; j++) {
            if (board[i][j] == num)
                return false;
        }
    }

    return true;
}

bool solve_sudoku(int board[SIZE][SIZE], int row, int col) {
    if (row == SIZE)
        return true;

    if (col == SIZE) {
        row++;
        col = 0;
    }

    if (board[row][col] != 0) {
        if (solve_sudoku(board, row, col + 1))
            return true;
    } else {
        for (int num = 1; num <= SIZE; num++) {
            if (is_valid(board, row, col, num)) {
                board[row][col] = num;
                if (solve_sudoku(board, row, col + 1))
                    return true;
                board[row][col] = 0;
            }
        }
    }

    return false;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <sudoku_puzzle>\n", argv[0]);
        return 1;
    }

    int board[SIZE][SIZE];

    bool success = true;

    int row = 0, col = 0;

    for (int i = 0; i < SIZE * SIZE && success; i++) {
        success = sscanf(argv[1] + i, "%d%n", &board[row][col], &i) == 1;
        if (!success) {
            printf("Invalid input: %s\n", argv[1]);
            return 1;
        }
        if (row == SIZE) {
            row = 0;
            col++;
        }
    }

    if (col != SIZE) {
        printf("Invalid input: %s\n", argv[1]);
        return 1;
    }

    printf("Input:\n");
    print_board(board);

    if (solve_sudoku(board, 0, 0)) {
        printf("\nSolution:\n");
        print_board(board);
    } else {
        printf("\nNo solution found.\n");
    }

    return 0;
}