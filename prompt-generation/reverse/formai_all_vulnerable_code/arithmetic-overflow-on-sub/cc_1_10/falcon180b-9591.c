//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3
#define PLAYERS 2
#define EMPTY '-'
#define PLAYER1 'X'
#define PLAYER2 'O'

char board[SIZE][SIZE];

void initBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }
}

void printBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin() {
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i])) {
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

int checkDraw() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == EMPTY) {
                return 0;
            }
        }
    }
    return 1;
}

void aiMove(char player) {
    int x, y;
    do {
        x = rand() % SIZE;
        y = rand() % SIZE;
    } while (board[x][y]!= EMPTY);

    board[x][y] = player;
}

int main() {
    srand(time(NULL));
    initBoard();

    int turn = 0;
    while (1) {
        printBoard();
        int player = turn % PLAYERS;
        printf("Player %d's turn.\n", player + 1);
        int x, y;
        scanf("%d%d", &x, &y);

        if (board[x - 1][y - 1] == EMPTY) {
            board[x - 1][y - 1] = (player == 0)? PLAYER1 : PLAYER2;
            turn++;
        } else {
            printf("Invalid move.\n");
        }

        if (checkWin()) {
            printf("Player %d wins!\n", player + 1);
            break;
        } else if (checkDraw()) {
            printf("It's a draw.\n");
            break;
        }

        if (turn % PLAYERS == 0) {
            aiMove(PLAYER2);
            turn++;
        }
    }

    return 0;
}