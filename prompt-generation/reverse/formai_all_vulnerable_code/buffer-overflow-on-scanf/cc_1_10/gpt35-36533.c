//FormAI DATASET v1.0 Category: Sudoku solver ; Style: funny
#include <stdio.h>
#include <stdbool.h>

int board[9][9];

void print_board() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

bool check_row(int num, int row) {
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num) {
            return false;
        }
    }
    return true;
}

bool check_col(int num, int col) {
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == num) {
            return false;
        }
    }
    return true;
}

bool check_box(int num, int row, int col) {
    int start_row = row - (row % 3);
    int start_col = col - (col % 3);
    for (int i = start_row; i < start_row + 3; i++) {
        for (int j = start_col; j < start_col + 3; j++) {
            if (board[i][j] == num) {
                return false;
            }
        }
    }
    return true;
}

bool can_place(int num, int row, int col) {
    if (check_row(num, row) && check_col(num, col) && check_box(num, row, col)) {
        return true;
    }
    return false;
}

bool solve() {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (can_place(num, row, col)) {
                        board[row][col] = num;
                        if (solve()) {
                            return true;
                        }
                        board[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() {
    printf("Welcome to the most hilarious Sudoku solver in the galaxy!\n");
    printf("Prepare for some serious mind-bending puzzles!\n");

    printf("First, let's populate the board with some numbers:\n");
    printf("Enter a number for each cell, followed by a space: \n");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    printf("\nGreat! Here's your board:\n");
    print_board();

    printf("\nSolving...\n");
    solve();

    printf("\nTa-da! Here's your solved board:\n");
    print_board();

    printf("\nThank you for using this incredible program.\n");
    printf("Please note: this solver is not responsible for any brain damage caused by excessive Sudoku.\n");
    return 0;
}