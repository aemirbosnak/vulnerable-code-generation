//Falcon-180B DATASET v1.0 Category: Sudoku solver ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define SIZE 9

// Function to print the Sudoku board
void printBoard(int board[SIZE][SIZE]) {
    int i, j;
    for(i=0; i<SIZE; i++) {
        for(j=0; j<SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a number is valid in a row
int isValidRow(int board[SIZE][SIZE], int row, int num) {
    int i;
    for(i=0; i<SIZE; i++) {
        if(board[row][i] == num) {
            return 0;
        }
    }
    return 1;
}

// Function to check if a number is valid in a column
int isValidCol(int board[SIZE][SIZE], int col, int num) {
    int i;
    for(i=0; i<SIZE; i++) {
        if(board[i][col] == num) {
            return 0;
        }
    }
    return 1;
}

// Function to check if a number is valid in a 3x3 box
int isValidBox(int board[SIZE][SIZE], int row, int col, int num) {
    int i, j;
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            if(board[(row/3)*3+i][(col/3)*3+j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to solve the Sudoku board
int solveBoard(int board[SIZE][SIZE]) {
    int i, j, k, found;
    for(i=0; i<SIZE; i++) {
        for(j=0; j<SIZE; j++) {
            if(board[i][j] == 0) {
                for(k=1; k<=SIZE; k++) {
                    if(isValidRow(board, i, k) && isValidCol(board, j, k) && isValidBox(board, i - i%3, j - j%3, k)) {
                        board[i][j] = k;
                        if(solveBoard(board)) {
                            return 1;
                        } else {
                            board[i][j] = 0;
                        }
                    }
                }
                return 0;
            }
        }
    }
    return 1;
}

// Main function
int main() {
    int board[SIZE][SIZE], i, j;
    printf("Enter the Sudoku board:\n");
    for(i=0; i<SIZE; i++) {
        for(j=0; j<SIZE; j++) {
            scanf("%d", &board[i][j]);
        }
    }
    if(solveBoard(board)) {
        printf("Solved Sudoku board:\n");
        printBoard(board);
    } else {
        printf("Could not solve Sudoku board.\n");
    }
    return 0;
}