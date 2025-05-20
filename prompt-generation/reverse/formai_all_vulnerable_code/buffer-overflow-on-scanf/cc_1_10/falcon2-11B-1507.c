//Falcon2-11B DATASET v1.0 Category: Sudoku solver ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int board[9][9];
    int size;
} Sudoku;

void display_board(Sudoku* sudoku) {
    printf("   1   2   3\n");
    printf("  %2d  %2d  %2d\n", sudoku->board[0][0], sudoku->board[0][1], sudoku->board[0][2]);
    printf("  %2d  %2d  %2d\n", sudoku->board[1][0], sudoku->board[1][1], sudoku->board[1][2]);
    printf("  %2d  %2d  %2d\n", sudoku->board[2][0], sudoku->board[2][1], sudoku->board[2][2]);
    printf("   4   5   6\n");
    printf("  %2d  %2d  %2d\n", sudoku->board[3][0], sudoku->board[3][1], sudoku->board[3][2]);
    printf("  %2d  %2d  %2d\n", sudoku->board[4][0], sudoku->board[4][1], sudoku->board[4][2]);
    printf("  %2d  %2d  %2d\n", sudoku->board[5][0], sudoku->board[5][1], sudoku->board[5][2]);
    printf("   7   8   9\n");
    printf("  %2d  %2d  %2d\n", sudoku->board[6][0], sudoku->board[6][1], sudoku->board[6][2]);
    printf("  %2d  %2d  %2d\n", sudoku->board[7][0], sudoku->board[7][1], sudoku->board[7][2]);
    printf("  %2d  %2d  %2d\n", sudoku->board[8][0], sudoku->board[8][1], sudoku->board[8][2]);
}

void read_sudoku(Sudoku* sudoku) {
    int row, col;
    printf("Enter the values of the Sudoku board:\n");
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            printf("%2d", row);
            printf("%2d", col);
            scanf("%d", &sudoku->board[row][col]);
            printf(" ");
        }
        printf("\n");
    }
}

void solve_sudoku(Sudoku* sudoku) {
    int row, col, value;
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            if (sudoku->board[row][col] == 0) {
                for (value = 1; value <= 9; value++) {
                    if (is_valid(sudoku, row, col, value)) {
                        sudoku->board[row][col] = value;
                        solve_sudoku(sudoku);
                        if (is_solved(sudoku)) {
                            break;
                        }
                        sudoku->board[row][col] = 0;
                    }
                }
            }
        }
    }
}

int is_valid(Sudoku* sudoku, int row, int col, int value) {
    int i, j;
    for (i = 0; i < 9; i++) {
        if (sudoku->board[i][col] == value) {
            return 0;
        }
        if (sudoku->board[row][i] == value) {
            return 0;
        }
        if (sudoku->board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == value) {
            return 0;
        }
    }
    for (j = 0; j < 9; j++) {
        if (sudoku->board[j][col] == value) {
            return 0;
        }
        if (sudoku->board[row][j] == value) {
            return 0;
        }
        if (sudoku->board[3 * (j / 3) + i / 3][3 * (col / 3) + i % 3] == value) {
            return 0;
        }
    }
    return 1;
}

int is_solved(Sudoku* sudoku) {
    int i, j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (sudoku->board[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    Sudoku sudoku;
    read_sudoku(&sudoku);
    solve_sudoku(&sudoku);
    display_board(&sudoku);
    return 0;
}