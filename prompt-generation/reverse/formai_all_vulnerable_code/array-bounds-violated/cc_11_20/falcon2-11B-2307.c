//Falcon2-11B DATASET v1.0 Category: Tic Tac Toe AI ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define PLAYER1 1
#define PLAYER2 2
#define EMPTY 0

int main() {
    int board[3][3] = {0, 0, 0,
                        0, 0, 0,
                        0, 0, 0};
    int player;
    int move;
    int winner = 0;

    printf("Welcome to Tic Tac Toe!\n");

    while (winner == 0) {
        printf("Player %d, make your move:\n", (player == PLAYER1)? 1 : 2);
        printf("Enter your move (1-9): ");
        scanf("%d", &move);
        if (move > 9 || move < 1) {
            printf("Invalid move.\n");
            continue;
        }

        if (board[move - 1][0]!= EMPTY && board[move - 1][0]!= (player == PLAYER1)? PLAYER2 : PLAYER1) {
            printf("Invalid move. Try again.\n");
            continue;
        }

        board[move - 1][0] = (player == PLAYER1)? PLAYER1 : PLAYER2;
        player = (player == PLAYER1)? PLAYER2 : PLAYER1;

        if (checkWinner(board, player)) {
            winner = player;
        }
    }

    if (winner == PLAYER1) {
        printf("Player 1 wins!\n");
    } else if (winner == PLAYER2) {
        printf("Player 2 wins!\n");
    } else {
        printf("It's a tie!\n");
    }

    return 0;
}

int checkWinner(int board[3][3], int player) {
    int i, j;
    int row, col;

    row = col = 0;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == player) {
                row++;
                if (j == 2) {
                    col++;
                    if (col == 3) {
                        return 1;
                    }
                }
            }
        }
        row = col = 0;
    }

    for (i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }

    for (i = 0; i < 3; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }

    for (i = 0; i < 3; i++) {
        if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
            return 1;
        }
    }

    return 0;
}