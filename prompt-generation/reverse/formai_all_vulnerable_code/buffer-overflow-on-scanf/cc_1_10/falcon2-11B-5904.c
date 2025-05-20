//Falcon2-11B DATASET v1.0 Category: Tic Tac Toe AI ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int isWinner(int board[3][3]) {
    int i, j;

    // Check rows
    for (i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0]!= 0)
            return board[i][0];

        // Check columns
        for (j = 0; j < 3; j++) {
            if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j]!= 0)
                return board[0][j];
        }

        // Check diagonals
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0]!= 0)
            return board[0][0];
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2]!= 0)
            return board[0][2];
    }

    // No winner
    return 0;
}

void makeMove(int board[3][3], int move) {
    board[move / 3][move % 3] = 1;
}

int main() {
    int board[3][3] = {0};
    int move, player;

    // Initialize board
    srand(time(NULL));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int r = rand() % 2;
            board[i][j] = r;
            if (board[i][j] == 0) {
                player = 1;
                break;
            }
        }
    }

    // Make moves
    while (1) {
        printf("Player %d's turn.\n", player);
        printf("Enter your move (0-8): ");
        scanf("%d", &move);
        makeMove(board, move);
        if (isWinner(board)) {
            printf("Player %d wins!\n", player);
            break;
        }
        player = 1 - player;
    }

    return 0;
}