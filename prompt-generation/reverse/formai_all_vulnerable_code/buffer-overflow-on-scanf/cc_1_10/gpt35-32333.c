//FormAI DATASET v1.0 Category: Sudoku solver ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int board[9][9]; // 9x9 sudoku board

/*
 * checkRow - is the number placed valid within the row?
 */
bool checkRow(int row, int num) {
    for (int col = 0; col < 9; col++) {
        if (board[row][col] == num) {
            return false;
        }
    }
    return true;
}

/*
 * checkCol - is the number placed valid within the column?
 */
bool checkCol(int col, int num) {
    for (int row = 0; row < 9; row++) {
        if (board[row][col] == num) {
            return false;
        }
    }
    return true;
}

/*
 * checkSquare - is the number placed valid within the 3x3 square?
 */
bool checkSquare(int row, int col, int num) {
    int x = row - row % 3;
    int y = col - col % 3;
    for (int i = x; i < x + 3; i++) {
        for (int j = y; j < y + 3; j++) {
            if (board[i][j] == num) {
                return false;
            }
        }
    }
    return true;
}

/*
 * solve - recursive function to solve the sudoku
 */
bool solve() {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (checkRow(row, num) && checkCol(col, num) && checkSquare(row, col, num)) {
                        board[row][col] = num;
                        if (solve()) {
                            return true;
                        }
                        board[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

/*
 * printBoard - print the solved sudoku board
 */
void printBoard() {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            printf("%d ", board[row][col]);
        }
        printf("\n");
    }
}

/*
 * main - program entry point
 */
int main() {
    // surreal intro
    printf("Welcome to the surreal world of Sudoku!\n");
    printf("In this world, numbers don't just exist, they dance and morph into strange shapes.\n");
    printf("But fear not, for we have a magical solver that can make sense of it all.\n");

    // initialize board
    printf("\nNow, let's start with a blank board. Enter the numbers one by one, with 0 for empty cells:\n");
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            scanf("%d", &board[row][col]);
        }
    }

    // solve board
    if (solve()) {
        printf("\nBehold, the power of the magical solver has revealed the answer:\n");
        printBoard();
    } else {
        printf("\nThe magical solver has failed. Perhaps the surreal world of Sudoku is too powerful for it...\n");
    }

    return 0;
}