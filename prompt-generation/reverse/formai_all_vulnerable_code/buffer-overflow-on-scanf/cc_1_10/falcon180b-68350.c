//Falcon-180B DATASET v1.0 Category: Sudoku solver ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define N 9
#define M 9
#define MAX_VALUE 9

typedef struct {
    int row;
    int col;
} SudokuCell;

typedef struct {
    int row;
    int col;
    int value;
} SudokuValue;

int checkRow(int board[N][M], int row, int value) {
    for(int i=0; i<M; i++) {
        if(board[row][i] == value) {
            return 0;
        }
    }
    return 1;
}

int checkCol(int board[N][M], int col, int value) {
    for(int i=0; i<N; i++) {
        if(board[i][col] == value) {
            return 0;
        }
    }
    return 1;
}

int checkBox(int board[N][M], int row, int col, int value) {
    int boxRow = row - row%3;
    int boxCol = col - col%3;
    for(int i=boxRow; i<boxRow+3; i++) {
        for(int j=boxCol; j<boxCol+3; j++) {
            if(board[i][j] == value) {
                return 0;
            }
        }
    }
    return 1;
}

int checkBoard(int board[N][M]) {
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(board[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

int backtrack(int board[N][M], int row, int col) {
    if(row == N) {
        return 1;
    }
    if(col == M) {
        return backtrack(board, row+1, 0);
    }
    if(board[row][col]!= 0) {
        return backtrack(board, row, col+1);
    }
    for(int i=1; i<=MAX_VALUE; i++) {
        if(checkRow(board, row, i) && checkCol(board, col, i) && checkBox(board, row, col, i)) {
            board[row][col] = i;
            if(backtrack(board, row, col+1)) {
                return 1;
            }
            board[row][col] = 0;
        }
    }
    return 0;
}

void printBoard(int board[N][M]) {
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int board[N][M];
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            scanf("%d", &board[i][j]);
        }
    }
    if(checkBoard(board)) {
        printf("The board is valid.\n");
    } else {
        printf("The board is invalid.\n");
        return 0;
    }
    backtrack(board, 0, 0);
    printf("The solution is:\n");
    printBoard(board);
    return 0;
}