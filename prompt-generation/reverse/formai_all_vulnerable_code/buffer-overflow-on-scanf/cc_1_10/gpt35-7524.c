//FormAI DATASET v1.0 Category: Sudoku solver ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int findNextEmpty(int board[9][9], int* row, int* col) {
    for(*row = 0; *row < 9; (*row)++) {
        for(*col = 0; *col < 9; (*col)++) {
            if(board[*row][*col] == 0) {
                return 1;
            }
        }
    }
    return 0;
}

int isSafe(int board[9][9], int row, int col, int num) {
    int i, j;

    for(i = 0; i < 9; i++) {
        if(board[row][i] == num)
            return 0;

        if(board[i][col] == num)
            return 0;
    }

    int boxRow = row - row % 3;
    int boxCol = col - col % 3;

    for(i = boxRow; i < boxRow + 3; i++) {
        for(j = boxCol; j < boxCol + 3; j++) {
            if(board[i][j] == num)
                return 0;
        }
    }

    return 1;
}

int solve(int board[9][9]) {
    int row, col;

    if(!findNextEmpty(board, &row, &col)) {
        return 1;
    }

    int num;
    for(num = 1; num <= 9; num++) {
        if(isSafe(board, row, col, num)) {
            board[row][col] = num;

            if(solve(board)) {
                return 1;
            }

            board[row][col] = 0;
        }
    }

    return 0;
}

void printBoard(int board[9][9]) {
    int row, col;

    for(row = 0; row < 9; row++, printf("\n")) {
        for(col = 0; col < 9; col++) {
            printf("%d ", board[row][col]);
        }
    }
}

int main() {
    int board[9][9];
    int i, j;

    printf("Enter the Sudoku puzzle (enter 0 for blank cells):\n");
    for(i = 0; i < 9; i++) {
        printf("Enter row %d: ", i+1);
        for(j = 0; j < 9; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    printf("\nSolving the Sudoku puzzle...\n");

    if(!solve(board)) {
        printf("Unable to solve the Sudoku puzzle.");
    }
    else {
        printf("\nSolved Sudoku puzzle:\n");
        printBoard(board);
    }

    return 0;
}