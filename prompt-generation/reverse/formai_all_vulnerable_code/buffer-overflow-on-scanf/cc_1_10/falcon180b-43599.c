//Falcon-180B DATASET v1.0 Category: Table Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

void initBoard(char board[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            board[i][j] = '-';
        }
    }
}

void drawBoard(char board[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(char board[SIZE][SIZE], char mark) {
    int i;

    // Check horizontal lines
    for (i = 0; i < SIZE; i++) {
        if (board[i][0] == mark && board[i][1] == mark && board[i][2] == mark) {
            return 1;
        }
    }

    // Check vertical lines
    for (i = 0; i < SIZE; i++) {
        if (board[0][i] == mark && board[1][i] == mark && board[2][i] == mark) {
            return 1;
        }
    }

    // Check diagonal lines
    if (board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) {
        return 1;
    }
    if (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark) {
        return 1;
    }

    return 0;
}

int main() {
    char board[SIZE][SIZE];
    int player = 1;
    initBoard(board);
    while (1) {
        drawBoard(board);
        int x, y;
        printf("Player %d's turn. Enter your move (row and column): ", player);
        scanf("%d %d", &x, &y);
        if (x < 0 || x > 2 || y < 0 || y > 2) {
            printf("Invalid move.\n");
            continue;
        }
        if (board[x][y]!= '-') {
            printf("Spot already taken.\n");
            continue;
        }
        board[x][y] = (player % 2 == 0)? 'X' : 'O';
        if (checkWin(board, board[x][y])) {
            drawBoard(board);
            printf("Player %d wins!\n", player);
            break;
        }
        player++;
    }
    return 0;
}