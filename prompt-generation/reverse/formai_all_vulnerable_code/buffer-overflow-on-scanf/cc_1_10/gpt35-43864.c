//FormAI DATASET v1.0 Category: Sudoku solver ; Style: real-life
#include <stdio.h>

int board[9][9];

int is_row_valid(int row, int num) {
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num)
            return 0;
    }
    return 1;
}

int is_col_valid(int col, int num) {
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == num)
            return 0;
    }
    return 1;
}

int is_box_valid(int start_row, int start_col, int num) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[start_row + i][start_col + j] == num)
                return 0;
        }
    }
    return 1;
}

void print_board() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int solve_sudoku(int row, int col) {
    if (row == 8 && col == 9) {
        return 1;
    }
    if (col == 9) {
        row += 1;
        col = 0;
    }
    if (board[row][col] > 0) {
        return solve_sudoku(row, col + 1);
    }
    for (int num = 1; num <= 9; num++) {
        if (is_row_valid(row, num) && is_col_valid(col, num) && is_box_valid(row - row % 3, col - col % 3, num)) {
            board[row][col] = num;
            if (solve_sudoku(row, col + 1))
                return 1;
        }
        board[row][col] = 0;
    }
    return 0;
}

int main() {
    printf("Enter the board:\n");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &board[i][j]);
        }
    }
    printf("Input board:\n");
    print_board();
    if (solve_sudoku(0, 0)) {
        printf("\n\nSolved board:\n");
        print_board();
    } else {
        printf("This sudoku cannot be solved.\n");
    }
    return 0;
}