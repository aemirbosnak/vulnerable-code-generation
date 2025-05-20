//FormAI DATASET v1.0 Category: Sudoku solver ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

#define ROWS 9
#define COLS 9
#define EMPTY 0

/* Here, we traverse the board of reality and find the surreal numbers */
void read_board(int board[ROWS][COLS]) {
    int row, col;
    printf("Enter the sudoku board of your reality:\n");
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            scanf("%d", &board[row][col]);
        }
    }
}

/* We generate random numbers at every attempt to solve */
int is_possible(int board[ROWS][COLS], int row, int col, int num) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return 0;
        }
    }
    int box_row = row - row % 3;
    int box_col = col - col % 3;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[box_row + i][box_col + j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

/* We apply the art of automation and randomness in solving */
int solve_board(int board[ROWS][COLS], int row, int col) {
    if (row == ROWS) {
        row = 0;
        col++;
        if (col == COLS) {
            return 1;
        }
    }
    if (board[row][col] != EMPTY) {
        return solve_board(board, row + 1, col);
    }
    int num, ok;
    do {
        num = rand() % 9 + 1;
        ok = is_possible(board, row, col, num);
        board[row][col] = num;
    } while (!ok && num > 0);
    if (!ok) {
        board[row][col] = EMPTY;
        return 0;
    }
    return solve_board(board, row + 1, col) == 1;
}

/* A surreal print function that mystifies reality */
void print_board(int board[ROWS][COLS]) {
    int row, col;
    printf("\n");
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            printf("%d ", board[row][col]);
            if (col == 2 || col == 5) {
                printf("| ");
            }
        }
        if (row == 2 || row == 5) {
            printf("\n---------------------");
        }
        printf("\n");
    }
}

/* And now, the magic begins! */
int main() {
    int board[ROWS][COLS];
    read_board(board);
    print_board(board);
    srand(time(0));
    if (solve_board(board, 0, 0)) {
        printf("\n\n The surreal solution of your reality:\n");
        print_board(board);
    } else {
        printf("No solution found!\n");
    }
    return 0;
}