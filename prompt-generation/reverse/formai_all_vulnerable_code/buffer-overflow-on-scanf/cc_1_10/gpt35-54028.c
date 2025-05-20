//FormAI DATASET v1.0 Category: Checkers Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define ROWS 8
#define COLS 8

void print_board(char board[][COLS]);
int is_valid_move(char board[][COLS], int from_row, int from_col, int to_row, int to_col);
void apply_move(char board[][COLS], int from_row, int from_col, int to_row, int to_col);

int main() {
    char board[ROWS][COLS] = {
        {'X', '.', 'X', '.', 'X', '.', 'X', '.'},
        {'.', 'X', '.', 'X', '.', 'X', '.', 'X'},
        {'X', '.', 'X', '.', 'X', '.', 'X', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', 'O', '.', 'O', '.', 'O', '.', 'O'},
        {'O', '.', 'O', '.', 'O', '.', 'O', '.'},
        {'.', 'O', '.', 'O', '.', 'O', '.', 'O'}
    };

    print_board(board);

    while (1) {
        int from_row, from_col, to_row, to_col;

        printf("Enter the move (from_row from_col to_row to_col): ");
        scanf("%d %d %d %d", &from_row, &from_col, &to_row, &to_col);

        if (is_valid_move(board, from_row, from_col, to_row, to_col)) {
            apply_move(board, from_row, from_col, to_row, to_col);
            print_board(board);
        } else {
            printf("Invalid move.\n");
        }
    }

    return 0;
}

void print_board(char board[][COLS]) {
    printf("   ");
    for (int i = 0; i < COLS; i++) {
        printf("%d ", i);
    }

    printf("\n");

    for (int i = 0; i < ROWS; i++) {
        printf("%d  ", i);

        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }

        printf("\n");
    }

    printf("\n");
}

int is_valid_move(char board[][COLS], int from_row, int from_col, int to_row, int to_col) {
    if (from_row < 0 || from_row >= ROWS || from_col < 0 || from_col >= COLS
        || to_row < 0 || to_row >= ROWS || to_col < 0 || to_col >= COLS) {
        return 0;
    }

    if (board[from_row][from_col] == '.') {
        return 0;
    }

    if (board[to_row][to_col] != '.') {
        return 0;
    }

    if (board[from_row][from_col] == 'X' && to_row >= from_row) {
        return 0;
    }

    if (board[from_row][from_col] == 'O' && to_row <= from_row) {
        return 0;
    }

    if ((abs(to_row - from_row) == 1 && abs(to_col - from_col) == 1) ||
        (abs(to_row - from_row) == 2 && abs(to_col - from_col) == 2)) {
        int enemy_row = (to_row + from_row) / 2;
        int enemy_col = (to_col + from_col) / 2;

        if (board[enemy_row][enemy_col] == '.') {
            return 0;
        } else if (board[enemy_row][enemy_col] == board[from_row][from_col]) {
            return 0;
        } else {
            return 1;
        }
    }

    return 0;
}

void apply_move(char board[][COLS], int from_row, int from_col, int to_row, int to_col) {
    board[to_row][to_col] = board[from_row][from_col];
    board[from_row][from_col] = '.';
    int enemy_row = (to_row + from_row) / 2;
    int enemy_col = (to_col + from_col) / 2;
    if (abs(to_row - from_row) == 2 && abs(to_col - from_col) == 2) {
        board[enemy_row][enemy_col] = '.';
    }
}