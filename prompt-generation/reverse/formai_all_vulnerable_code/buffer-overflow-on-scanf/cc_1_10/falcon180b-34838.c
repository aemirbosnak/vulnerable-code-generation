//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void initBoard(char board[ROWS][COLS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            board[i][j] = '-';
        }
    }
}

void printBoard(char board[ROWS][COLS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void flipCard(char board[ROWS][COLS], int row, int col) {
    if(board[row][col] == '-') {
        board[row][col] = '*';
    } else {
        board[row][col] = '-';
    }
}

int checkMatch(char board[ROWS][COLS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(board[i][j] == '-') {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    srand(time(NULL));
    char board[ROWS][COLS];
    initBoard(board);
    int moves = 0;

    while(1) {
        printBoard(board);
        int row, col;
        scanf("%d %d", &row, &col);
        if(row < 0 || row >= ROWS || col < 0 || col >= COLS) {
            printf("Invalid move\n");
            continue;
        }
        if(board[row][col] == '-') {
            flipCard(board, row, col);
            moves++;
        } else {
            printf("Card already flipped\n");
        }
        if(checkMatch(board)) {
            printf("Congratulations! You won in %d moves\n", moves);
            break;
        }
    }

    return 0;
}