//FormAI DATASET v1.0 Category: Sudoku solver ; Style: sophisticated
#include <stdio.h>

#define N 9

int puzzle[N][N];

void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int isSafe(int board[N][N], int row, int col, int num) {
    // Check row
    for (int i = 0; i < N; i++) {
        if (board[row][i] == num) {
            return 0;
        }
    }

    // Check column
    for (int i = 0; i < N; i++) {
        if (board[i][col] == num) {
            return 0;
        }
    }

    // Check box
    int boxStartRow = row - row % 3;
    int boxStartCol = col - col % 3;
    for (int i = boxStartRow; i < boxStartRow + 3; i++) {
        for (int j = boxStartCol; j < boxStartCol + 3; j++) {
            if (board[i][j] == num) {
                return 0;
            }
        }
    }

    return 1;
}

int solveSudoku(int board[N][N], int row, int col) {
    // Check if all cells are filled
    if (row == N - 1 && col == N) {
        return 1;
    }

    // If current column is filled, move to next column
    if (col == N) {
        row++;
        col = 0;
    }

    // Check if current cell is prefilled
    if (board[row][col] != 0) {
        return solveSudoku(board, row, col + 1);
    }

    for (int num = 1; num <= N; num++) {
        if (isSafe(board, row, col, num)) {
            board[row][col] = num;
            if (solveSudoku(board, row, col + 1)) {
                return 1;
            }
            board[row][col] = 0;
        }
    }

    return 0;
}

int main() {
    printf("Enter the Sudoku puzzle:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &puzzle[i][j]);
        }
    }

    printf("Sudoku Puzzle before solving:\n");
    printBoard(puzzle);

    if (solveSudoku(puzzle, 0, 0) == 1) {
        printf("\nSudoku Puzzle after solving:\n");
        printBoard(puzzle);
    }
    else {
        printf("No solution exists!");
    }

    return 0;
}