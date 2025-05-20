//FormAI DATASET v1.0 Category: Sudoku solver ; Style: all-encompassing
#include <stdio.h>

void printGreeting() {
    printf("Welcome to the Sudoku solver!\n");
    printf("Please enter the starting configuration of the Sudoku board:\n");
}

void readInput(int board[9][9]) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            scanf("%d", &board[row][col]);
        }
    }
}

void printBoard(int board[9][9]) {
    printf("Current configuration:\n");
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            printf("%d ", board[row][col]);
        }
        printf("\n");
    }
}

void solve(int board[9][9], int row, int col, int *solved) {
    if (*solved) {
        return;
    }
    if (row == 9) {
        *solved = 1;
        printf("Solution found:\n");
        printBoard(board);
        return;
    }
    int nextRow = col == 8 ? row + 1: row;
    int nextCol = col == 8 ? 0 : col + 1;
    if (board[row][col] != 0) {
        solve(board, nextRow, nextCol, solved);
    } else {
        for (int n = 1; n <= 9; n++) {
            int valid = 1;
            for (int i = 0; i < 9; i++) {
                if (board[row][i] == n || board[i][col] == n || board[row-row%3+i/3][col-col%3+i%3] == n) {
                    valid = 0;
                    break;
                }
            }
            if (valid) {
                board[row][col] = n;
                solve(board, nextRow, nextCol, solved);
                board[row][col] = 0;
            }
        }
    }
}

int main() {
    int board[9][9];
    printGreeting();
    readInput(board);
    printBoard(board);
    int solved = 0;
    solve(board, 0, 0, &solved);
    if (!solved) {
        printf("No solution found!\n");
    }
    return 0;
}