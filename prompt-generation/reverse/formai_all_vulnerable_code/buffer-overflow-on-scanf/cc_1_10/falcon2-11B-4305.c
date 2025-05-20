//Falcon2-11B DATASET v1.0 Category: Table Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printBoard(int board[3][3]);
void playGame(int board[3][3]);

int main() {
    int board[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    printBoard(board);
    playGame(board);

    return 0;
}

void printBoard(int board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

void playGame(int board[3][3]) {
    int player1, player2;
    int move, turn = 1;

    srand(time(NULL));

    printf("Player 1, enter your move (row, column): ");
    scanf("%d", &move);
    while (move < 1 || move > 9 || board[move - 1][move - 1] == 1 || board[move - 1][move - 1] == 2) {
        printf("Invalid move, try again: ");
        scanf("%d", &move);
    }

    board[move - 1][move - 1] = 1;

    printf("Player 2, enter your move (row, column): ");
    scanf("%d", &move);
    while (move < 1 || move > 9 || board[move - 1][move - 1] == 1 || board[move - 1][move - 1] == 2) {
        printf("Invalid move, try again: ");
        scanf("%d", &move);
    }

    board[move - 1][move - 1] = 2;

    if (turn % 2 == 1) {
        player1 = 1;
        player2 = 2;
    } else {
        player1 = 2;
        player2 = 1;
    }

    printf("Player %d wins!\n", player1);
}