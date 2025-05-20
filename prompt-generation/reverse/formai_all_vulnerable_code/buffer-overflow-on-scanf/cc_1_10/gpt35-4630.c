//FormAI DATASET v1.0 Category: Sudoku solver ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define SIZE 9

int rows[SIZE][SIZE];
int cols[SIZE][SIZE];
int boxes[SIZE][SIZE];
int board[SIZE][SIZE];

/* Convert (i,j) onto an index */
int box(int i, int j) {
    return (i / 3) * 3 + (j / 3);
}

/* Backtracking algorithm to solve the puzzle */
int solve(int i, int j) {
    /* If the current cell is empty, try all possible values */
    if(board[i][j] == 0) {
        int boxIndex = box(i, j);
        for(int k = 1; k <= SIZE; ++k) {
            if(!rows[i][k-1] && !cols[j][k-1] && !boxes[boxIndex][k-1]) {
                rows[i][k-1] = cols[j][k-1] = boxes[boxIndex][k-1] = 1;
                board[i][j] = k;

                /* Move to the next cell */
                if(j == SIZE -1) {
                    if(i == SIZE - 1) return 1;
                    else if(solve(i+1, 0)) return 1;
                } else {
                    if(solve(i, j+1)) return 1;
                }
                
                /* Backtrack */
                rows[i][k-1] = cols[j][k-1] = boxes[boxIndex][k-1] = 0;
                board[i][j] = 0;
            }
        }
    } else {
        /* Move to the next cell */
        if(j == SIZE -1) {
            if(i == SIZE - 1) return 1;
            else return solve(i+1, 0);
        } else {
            return solve(i, j+1);
        }
    }

    return 0; 
}

/* Function to print the board */
void printBoard() {
    for(int i = 0; i < SIZE; ++i) {
        for(int j = 0; j < SIZE; ++j) {
            printf("%d ", board[i][j]);
            if((j+1) % 3 == 0) printf(" ");
        }
        printf("\n");
        if((i+1) % 3 == 0) printf("\n");
    }
}

int main() {
    /* Read the board */
    printf("Enter the board:\n");
    for(int i = 0; i < SIZE; ++i) {
        for(int j = 0; j < SIZE; ++j) {
            scanf("%d", &board[i][j]);
            rows[i][board[i][j]-1] = 1;
            cols[j][board[i][j]-1] = 1;
            boxes[box(i,j)][board[i][j]-1] = 1;
        }
    }

    /* Solve the puzzle */
    if(solve(0,0)) {
        printf("Solution:\n");
        printBoard();
    } else {
        printf("The board is unsolvable.\n");
    }

    return 0;
}