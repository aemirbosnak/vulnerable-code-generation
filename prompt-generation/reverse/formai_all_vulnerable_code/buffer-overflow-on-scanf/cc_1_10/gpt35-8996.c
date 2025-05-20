//FormAI DATASET v1.0 Category: Sudoku solver ; Style: introspective
#include <stdio.h>

int board[9][9];

int is_possible(int num, int row, int col) {
    // Check if number already exists in row or col
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return 0;
        }
    }
    // Check if number already exists in its respective 3x3 sub-grid
    int sub_row = row - (row % 3);
    int sub_col = col - (col % 3);
    for (int i = sub_row; i < sub_row + 3; i++) {
        for (int j = sub_col; j < sub_col + 3; j++) {
            if (board[i][j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

int solve_sudoku() {
    // Find next empty cell
    int row = -1, col = -1;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 0) {
                row = i;
                col = j;
                break;
            }
        }
        if (row != -1) {
            break;
        }
    }
    // If board is already filled, return 1
    if (row == -1) {
        return 1;
    }
    // Try numbers from 1 to 9
    for (int num = 1; num <= 9; num++) {
        if (is_possible(num, row, col)) {
            board[row][col] = num;
            if (solve_sudoku()) {
                return 1;
            }
            board[row][col] = 0;
        }
    }
    return 0;
}

int main() {
    // Input Sudoku board
    printf("Enter the Sudoku board (0 for empty cells):\n");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &board[i][j]);
        }
    }
    // Solve Sudoku board
    if (solve_sudoku()) {
        // Print solved Sudoku board
        printf("Solved Sudoku board:\n");
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("No solution exists for the given Sudoku board.\n");
    }
    return 0;
}