//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3

void drawBoard(char board[ROW][COL]) {
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void initializeBoard(char board[ROW][COL]) {
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            board[i][j] = '*';
        }
    }
}

void placeCard(char board[ROW][COL], int row, int col) {
    if (row >= 0 && row < ROW && col >= 0 && col < COL) {
        board[row][col] = 'X';
    } else {
        printf("Invalid position!\n");
    }
}

int checkWin(char board[ROW][COL]) {
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            if (board[i][j]!= '*') {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    srand(time(NULL));
    char board[ROW][COL];
    initializeBoard(board);
    int player = 1;
    int turn = 0;
    int win = 0;

    while (win == 0) {
        drawBoard(board);
        printf("\nPlayer %d's turn.\n", player);
        int row, col;
        scanf("%d%d", &row, &col);
        placeCard(board, row, col);
        win = checkWin(board);
        turn++;
        if (turn == 2) {
            player++;
            turn = 0;
        }
    }

    if (player == 1) {
        printf("Player 1 wins!\n");
    } else {
        printf("Player 2 wins!\n");
    }

    return 0;
}