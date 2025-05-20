//FormAI DATASET v1.0 Category: Sudoku solver ; Style: surprised
#include <stdio.h>

int puzzle[9][9];

int row_check(int row, int num) {
    for (int i = 0; i < 9; i++) {
        if (puzzle[row][i] == num) {
            return 0;
        }
    }
    return 1;
}

int col_check(int col, int num) {
    for (int i = 0; i < 9; i++) {
        if (puzzle[i][col] == num) {
            return 0;
        }
    }
    return 1;
}

int box_check(int row, int col, int num) {
    row = row - (row % 3);
    col = col - (col % 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (puzzle[row + i][col + j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

int solve_sudoku(int row, int col) {
    if (col == 9) {
        row++;
        col = 0;
    }
    if (row == 9) {
        return 1;
    }
    if (puzzle[row][col] != 0) {
        return solve_sudoku(row, col + 1);
    }
    for (int num = 1; num <= 9; num++) {
        if (row_check(row, num) && col_check(col, num) && box_check(row, col, num)) {
            puzzle[row][col] = num;
            if (solve_sudoku(row, col + 1)) {
                return 1;
            }
            puzzle[row][col] = 0;
        }
    }
    return 0;
}

void print_puzzle() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", puzzle[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Welcome to the Sudoku Solver!\n");
    printf("Please enter the numbers in the puzzle, with 0 representing empty spaces:\n");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &puzzle[i][j]);
            if (puzzle[i][j] < 0 || puzzle[i][j] > 9) {
                printf("Invalid input!\n");
                return 0;
            }
        }
    }
    printf("The puzzle you entered is:\n");
    print_puzzle();
    if (solve_sudoku(0, 0)) {
        printf("The solved puzzle is:\n");
        print_puzzle();
    } else {
        printf("There is no solution for this puzzle.\n");
    }
    return 0;
}