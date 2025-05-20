//FormAI DATASET v1.0 Category: Sudoku solver ; Style: Claude Shannon
// Sudoku Solver Program

// import required libraries
#include <stdio.h>
#include <stdlib.h>

// define the board size
#define SIZE 9

// define the empty cell value
#define EMPTY 0

// define boolean type
typedef enum {false, true} bool;

// initialize the board
int board[SIZE][SIZE];

// function to print the board
void printBoard() {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// function to check if a number can be placed in a given cell
bool canPlace(int x, int y, int n) {
    int i, j;
    // check for same number in same row or column
    for (i = 0; i < SIZE; i++) {
        if (board[x][i] == n) return false;
        if (board[i][y] == n) return false;
    }
    // check for same number in same box
    int startRow = x - x % 3;
    int startCol = y - y % 3;
    for (i = startRow; i < startRow + 3; i++) {
        for (j = startCol; j < startCol + 3; j++) {
            if (board[i][j] == n) return false;
        }
    }
    return true;
}

// function to solve the board
bool solveBoard() {
    int i, j;
    // find next empty cell
    int x = -1, y = -1;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] == EMPTY) {
                x = i;
                y = j;
                break;
            }
        }
        if (x != -1) break;
    }
    // if no empty cell is found then the board is solved
    if (x == -1) return true;
    // try each number from 1 to 9 in the empty cell
    int n;
    for (n = 1; n <= 9; n++) {
        if (canPlace(x, y, n)) {
            board[x][y] = n;
            if (solveBoard()) return true;
            board[x][y] = EMPTY;
        }
    }
    return false;
}

// main function to initialize and solve the board
int main() {
    // initialize the board
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            scanf("%d", &board[i][j]);
        }
    }
    // solve the board
    if (solveBoard()) {
        printf("Solved Sudoku:\n");
        printBoard();
    } else {
        printf("The given Sudoku cannot be solved.\n");
    }
    return 0;
}