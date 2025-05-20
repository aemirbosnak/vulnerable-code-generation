//FormAI DATASET v1.0 Category: Sudoku solver ; Style: surprised
#include <stdio.h>

int board[9][9];

// function to print the sudoku board
void print_board() {
    int i, j;
    printf("-------------------\n");
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            printf("%d ", board[i][j]);
            if ((j + 1) % 3 == 0)
                printf("| ");
        }
        printf("\n");
        if ((i + 1) % 3 == 0)
            printf("-------------------\n");
    }
}

// function to check if a number is already in row
int row_check(int row, int num) {
    int j;
    for (j = 0; j < 9; j++) {
        if (board[row][j] == num)
            return 1;
    }
    return 0;
}

// function to check if a number is already in column
int col_check(int col, int num) {
    int i;
    for (i = 0; i < 9; i++) {
        if (board[i][col] == num)
            return 1;
    }
    return 0;
}

// function to check if a number is already in box
int box_check(int row, int col, int num) {
    int i, j;
    for (i = row; i < row + 3; i++) {
        for (j = col; j < col + 3; j++) {
            if (board[i][j] == num)
                return 1;
        }
    }
    return 0;
}

// function to check if it's safe to place a number
int is_safe(int row, int col, int num) {
    if (!row_check(row, num) && !col_check(col, num) && !box_check(row - row % 3, col - col % 3, num))
        return 1;
    return 0;
}

// function to solve the sudoku
int solve() {
    int row, col, num;
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            if (board[row][col] == 0) {
                for (num = 1; num <= 9; num++) {
                    if (is_safe(row, col, num)) {
                        board[row][col] = num;
                        if (solve())
                            return 1;
                        board[row][col] = 0;
                    }
                }
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    // enter the sudoku board
    printf("Enter the Sudoku board:\n");
    int i, j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            scanf("%d", &board[i][j]);
        }
    }
    // solve the sudoku
    printf("Solving the Sudoku...\n");
    if (solve()) {
        printf("Sudoku solved successfully!\n");
        print_board();
    }
    else {
        printf("Cannot solve the Sudoku :(\n");
    }
    return 0;
}