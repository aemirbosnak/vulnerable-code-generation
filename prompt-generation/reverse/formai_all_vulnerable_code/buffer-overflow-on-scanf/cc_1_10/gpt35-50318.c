//FormAI DATASET v1.0 Category: Sudoku solver ; Style: energetic
#include <stdio.h>
#include <stdbool.h>

#define N 9

void initialize_board(int board[N][N]) {
    printf("\nEnter the initial board state (0 for blank cells):\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &board[i][j]);
        }
    }
}

void print_board(int board[N][N]) {
    printf("\nThe solved board is:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

bool is_valid(int board[N][N], int row, int col, int num) {
    // Check if number is already present in row or column
    for (int i = 0; i < N; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return false;
        }
    }
    
    // Check if number is already present in the 3x3 sub-grid
    int sub_row = (row / 3) * 3;
    int sub_col = (col / 3) * 3;
    for (int i = sub_row; i < sub_row + 3; i++) {
        for (int j = sub_col; j < sub_col + 3; j++) {
            if (board[i][j] == num) {
                return false;
            }
        }
    }
    return true;
}

bool solve_board(int board[N][N], int row, int col) {
    // If all cells of the board have been filled
    if (row == N) {
        return true;
    }
    
    // If current cell is already filled, move to next cell
    if (board[row][col] != 0) {
        if (col == N - 1) {
            return solve_board(board, row + 1, 0);
        } else {
            return solve_board(board, row, col + 1);
        }
    }
    
    // Try different numbers for current cell
    for (int num = 1; num <= 9; num++) {
        if (is_valid(board, row, col, num)) {
            board[row][col] = num;
            if (col == N - 1) {
                if (solve_board(board, row + 1, 0)) {
                    return true;
                }
            } else {
                if (solve_board(board, row, col + 1)) {
                    return true;
                }
            }
            board[row][col] = 0;
        }
    }
    
    return false;   // No number can be placed in current cell
}

int main() {
    printf("\n*** Welcome to Sudoku Solver! ***\n");
    int board[N][N];
    initialize_board(board);
    if (solve_board(board, 0, 0)) {
        print_board(board);
    } else {
        printf("\nNo solution exists.\n");
    }
    printf("\n*** Thank you for using Sudoku Solver! ***\n");
    return 0;
}