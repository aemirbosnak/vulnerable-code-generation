//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void initBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = '-';
        }
    }
}

void drawBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void placeCard(char board[SIZE][SIZE], int x, int y, char card) {
    board[x][y] = card;
}

int checkWin(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    for (int j = 0; j < SIZE; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return 1;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }

    return 0;
}

int main() {
    srand(time(NULL));
    char board[SIZE][SIZE];
    initBoard(board);

    int player = 1;
    while (1) {
        drawBoard(board);
        int x, y;
        printf("Player %d, enter your move (row, col): ", player);
        scanf("%d %d", &x, &y);
        x--; y--;

        if (board[x][y]!= '-') {
            printf("Invalid move, try again.\n");
            continue;
        }

        placeCard(board, x, y, player == 1? 'X' : 'O');

        if (checkWin(board)) {
            printf("Player %d wins!\n", player);
            break;
        }

        player =!player;
    }

    return 0;
}