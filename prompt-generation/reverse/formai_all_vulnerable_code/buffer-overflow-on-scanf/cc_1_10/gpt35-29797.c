//FormAI DATASET v1.0 Category: Sudoku solver ; Style: accurate
#include <stdio.h>

#define SIZE 9

int board[SIZE][SIZE];

// function to print the board
void print_board() {
    printf("------------------------------\n");
    for (int i = 0; i < SIZE; i++) {
        printf("|");
        for (int j = 0; j < SIZE; j++) {
            printf(" %d ", board[i][j]);
            if ((j + 1) % 3 == 0) {
                printf("|");
            }
        }
        printf("\n");
        if ((i + 1) % 3 == 0) {
            printf("------------------------------\n");
        }
    }
}

// function to check if a number can be placed in a given position
int is_valid(int num, int row, int col) {
    // check row and column
    for (int i = 0; i < SIZE; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return 0;
        }
    }
    // check 3x3 box
    int box_row = row - (row % 3);
    int box_col = col - (col % 3);
    for (int i = box_row; i < box_row + 3; i++) {
        for (int j = box_col; j < box_col + 3; j++) {
            if (board[i][j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

// function to solve the puzzle recursively
int solve(int row, int col) {
    // check if we have reached the end of the board
    if (row == SIZE) {
        return 1;
    }
    // check if we need to move to the next row
    if (col == SIZE) {
        return solve(row + 1, 0);
    }
    // check if the current position is already filled
    if (board[row][col] != 0) {
        return solve(row, col + 1);
    }
    // try all possible numbers
    for (int num = 1; num <= SIZE; num++) {
        if (is_valid(num, row, col)) {
            board[row][col] = num;
            if (solve(row, col + 1)) {
                return 1;
            }
            board[row][col] = 0; // backtrack if solution not found
        }
    }
    // return 0 if no solution was found
    return 0;
}

int main() {
    // initialize board
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &board[i][j]);
        }
    }
    // solve puzzle
    if (solve(0, 0)) {
        print_board();
    } else {
        printf("No solution found.\n");
    }
    return 0;
}