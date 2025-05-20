//Falcon-180B DATASET v1.0 Category: Sudoku solver ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ROWS 9
#define MAX_COLS 9
#define MAX_VAL 9

typedef struct {
    int row;
    int col;
} Coord;

void printBoard(int board[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

bool isValid(int board[MAX_ROWS][MAX_COLS], int row, int col, int val) {
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int i = startRow; i < startRow + 3; i++) {
        for (int j = startCol; j < startCol + 3; j++) {
            if (board[i][j] == val) {
                return false;
            }
        }
    }
    return true;
}

bool solve(int board[MAX_ROWS][MAX_COLS], int row, int col) {
    if (row == MAX_ROWS) {
        return true;
    }
    if (col == MAX_COLS) {
        return solve(board, row + 1, 0);
    }
    if (board[row][col] == 0) {
        for (int i = 1; i <= MAX_VAL; i++) {
            if (isValid(board, row, col, i)) {
                board[row][col] = i;
                if (solve(board, row, col + 1)) {
                    return true;
                }
                board[row][col] = 0;
            }
        }
        return false;
    }
    return solve(board, row, col + 1);
}

int main() {
    int board[MAX_ROWS][MAX_COLS];
    int row, col;
    printf("Enter the starting board:\n");
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            scanf("%d", &board[i][j]);
        }
    }
    solve(board, 0, 0);
    printBoard(board);
    return 0;
}