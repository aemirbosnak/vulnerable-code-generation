//FormAI DATASET v1.0 Category: Sudoku solver ; Style: accurate
#include <stdio.h>

#define N 9

void print_board(int board[N][N]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%2d", board[i][j]);
        }
        printf("\n");
    }
}

int find_empty(int board[N][N], int *row, int *col) {
    for (*row = 0; *row < N; (*row)++) {
        for (*col = 0; *col < N; (*col)++) {
            if (board[*row][*col] == 0) {
                return 1;
            }
        }
    }
    return 0;
}

int check_row(int board[N][N], int row, int num) {
    int col;
    for (col = 0; col < N; col++) {
        if (board[row][col] == num) {
            return 1;
        }
    }
    return 0;
}

int check_col(int board[N][N], int col, int num) {
    int row;
    for (row = 0; row < N; row++) {
        if (board[row][col] == num) {
            return 1;
        }
    }
    return 0;
}

int check_box(int board[N][N], int box_start_row, int box_start_col, int num) {
    int row, col;
    for (row = 0; row < 3; row++) {
        for (col = 0; col < 3; col++) {
            if (board[row+box_start_row][col+box_start_col] == num) {
                return 1;
            }
        }
    }
    return 0;
}

int is_safe(int board[N][N], int row, int col, int num) {
    return !check_row(board, row, num) &&
           !check_col(board, col, num) &&
           !check_box(board, row - row%3, col - col%3, num);
}

int solve_board(int board[N][N]) {
    int row, col, num;
    if (!find_empty(board, &row, &col)) {
        return 1; // board is already filled
    }
    for (num = 1; num <= 9; num++) {
        if (is_safe(board, row, col, num)) {
            board[row][col] = num;
            if (solve_board(board)) {
                return 1; // solved the board!
            }
            board[row][col] = 0; // backtrack
        }
    }
    return 0; // board could not be solved
}

int main() {
    int board[N][N] = {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0}};
    printf("Enter the Sudoku board (use '0' for empty cells):\n");
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &board[i][j]);
        }
    }
    printf("\nSudoku board entered:\n");
    print_board(board);
    if (solve_board(board)) {
        printf("\nSolution:\n");
        print_board(board);
    } else {
        printf("\nBoard could not be solved!\n");
    }
    return 0;
}