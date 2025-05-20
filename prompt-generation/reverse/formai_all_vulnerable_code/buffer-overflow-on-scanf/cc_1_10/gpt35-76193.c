//FormAI DATASET v1.0 Category: Sudoku solver ; Style: Linus Torvalds
#include <stdio.h>

int board[9][9]; // the Sudoku board, initialized with zeros (empty cells)

/* Function to check if a given number is valid in a cell */
int isValid(int x, int y, int num) {
    // check row for duplicates
    for (int i = 0; i < 9; i++) {
        if (board[x][i] == num) {
            return 0;
        }
    }
    // check column for duplicates
    for (int i = 0; i < 9; i++) {
        if (board[i][y] == num) {
            return 0;
        }
    }
    // check 3x3 subgrid for duplicates
    int startRow = (x / 3) * 3;
    int startCol = (y / 3) * 3;
    for (int i = startRow; i < startRow + 3; i++) {
        for (int j = startCol; j < startCol + 3; j++) {
            if (board[i][j] == num) {
                return 0;
            }
        }
    }
    return 1; // if we get here, the number is valid
}

/* Function to solve the Sudoku board using backtracking */
int solve(int x, int y) {
    if (x == 9) {
        return 1; // the board is already solved
    }
    if (board[x][y] != 0) { // this cell is already filled, move to the next one
        if (y == 8) {
            if (solve(x+1, 0)) {
                return 1; // done
            }
        } else {
            if (solve(x, y+1)) {
                return 1; // done
            }
        }
        return 0; // failed, backtrack
    }
    // try all numbers from 1 to 9 for this cell
    for (int i = 1; i <= 9; i++) {
        if (isValid(x, y, i)) {
            board[x][y] = i;
            if (y == 8) {
                if (solve(x+1, 0)) {
                    return 1; // done
                }
            } else {
                if (solve(x, y+1)) {
                    return 1; // done
                }
            }
            // if we get here, the number didn't work, undo and try another number
            board[x][y] = 0;
        }
    }
    return 0; // all numbers failed, backtrack
}

int main() {
    // read the Sudoku board from stdin
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &board[i][j]);
        }
    }
    if (solve(0, 0)) { // try to solve the Sudoku board
        // print the solution to stdout
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
    } else {
        // no solution found
        printf("No solution found.\n");
    }
    return 0;
}