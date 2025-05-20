//Falcon2-11B DATASET v1.0 Category: Chess AI ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int board[8][8] = {
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0 }
    };

    int player1 = 1;
    int player2 = 2;
    int turn = 1;
    int numMoves = 0;

    printf("Welcome to the C Chess AI!\n\n");

    while (1) {
        int piece, row, col;
        printf("Player %d, it's your turn. Please select a piece: ", turn);
        scanf("%d %d %d", &piece, &row, &col);

        if (piece == -1) {
            break;
        }

        if (board[row][col]!= 0) {
            printf("Invalid move. Please select a different piece.\n");
            continue;
        }

        board[row][col] = turn;
        numMoves++;

        if (numMoves % 2 == 0) {
            turn = 3 - turn;
        }

        printf("Player %d made a move.\n", turn);
    }

    if (numMoves % 2 == 0) {
        printf("Game ended in a draw.\n");
    }
    else if (turn == player2) {
        printf("Player 2 wins!\n");
    }
    else {
        printf("Player 1 wins!\n");
    }

    return 0;
}