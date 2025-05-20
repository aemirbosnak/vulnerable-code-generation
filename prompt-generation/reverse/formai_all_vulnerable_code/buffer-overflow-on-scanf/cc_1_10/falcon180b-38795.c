//Falcon-180B DATASET v1.0 Category: Table Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define NUM_PLAYERS 2

void printBoard(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int checkForWin(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
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
    int board[SIZE][SIZE] = {{0}};
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = rand() % NUM_PLAYERS + 1;
        }
    }
    int turn = 1;
    int winner = 0;
    while (!winner) {
        printf("Player %d's turn\n", turn);
        int x, y;
        scanf("%d %d", &x, &y);
        if (board[x-1][y-1] == 0) {
            board[x-1][y-1] = turn;
            winner = checkForWin(board);
        }
        else {
            printf("Invalid move\n");
        }
        turn++;
        if (turn > NUM_PLAYERS) {
            turn = 1;
        }
    }
    printf("Player %d wins!\n", winner);
    return 0;
}