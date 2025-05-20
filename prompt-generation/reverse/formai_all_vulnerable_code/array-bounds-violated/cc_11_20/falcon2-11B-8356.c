//Falcon2-11B DATASET v1.0 Category: Chess AI ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 8

int main() {
    int board[MAX_SIZE][MAX_SIZE];
    int player1, player2, move;
    int i, j;

    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            board[i][j] = 0;
        }
    }

    player1 = 1;
    player2 = 2;

    while (1) {
        printf("Player %d's turn\n", player1);
        move = scanf("%d", &move);
        if (move == EOF) {
            break;
        }
        board[move/MAX_SIZE][move%MAX_SIZE] = player1;
        player1 = (player1 + 1) % 2;
        printf("Player %d has played at (%d, %d)\n", player1, move/MAX_SIZE, move%MAX_SIZE);
    }

    player1 = 1;
    player2 = 2;

    while (1) {
        printf("Player %d's turn\n", player2);
        move = scanf("%d", &move);
        if (move == EOF) {
            break;
        }
        board[move/MAX_SIZE][move%MAX_SIZE] = player2;
        player2 = (player2 + 1) % 2;
        printf("Player %d has played at (%d, %d)\n", player2, move/MAX_SIZE, move%MAX_SIZE);
    }

    if (board[0][0] == board[0][1] || board[0][2] == board[0][3] || board[1][0] == board[1][1] || board[1][2] == board[1][3] || board[2][0] == board[2][1] || board[2][2] == board[2][3] || board[3][0] == board[3][1] || board[3][2] == board[3][3]) {
        printf("Player %d wins!\n", board[0][0]);
    } else {
        printf("Game draw\n");
    }

    return 0;
}