//Falcon-180B DATASET v1.0 Category: Sudoku solver ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 9
#define EMPTY 0

int **create_board() {
    int **board = (int **) malloc(SIZE * sizeof(int *));
    for (int i = 0; i < SIZE; i++) {
        board[i] = (int *) malloc(SIZE * sizeof(int));
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }
    return board;
}

void print_board(int **board) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int is_valid(int **board, int row, int col, int num) {
    for (int i = 0; i < SIZE; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return 0;
        }
    }
    int box_row = row - row % 3;
    int box_col = col - col % 3;
    for (int i = box_row; i < box_row + 3; i++) {
        for (int j = box_col; j < box_col + 3; j++) {
            if (board[i][j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

int find_empty(int **board) {
    int row, col;
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (board[row][col] == EMPTY) {
                return 1;
            }
        }
    }
    return 0;
}

int **solve_sudoku(int **board) {
    int row, col;
    while (find_empty(board)) {
        row = rand() % SIZE;
        col = rand() % SIZE;
        while (!is_valid(board, row, col, 1)) {
            row = rand() % SIZE;
            col = rand() % SIZE;
        }
        board[row][col] = 1;
    }
    return board;
}

int main() {
    srand(time(NULL));
    int **board = create_board();
    int **solution = solve_sudoku(board);
    print_board(solution);
    free(solution);
    free(board);
    return 0;
}