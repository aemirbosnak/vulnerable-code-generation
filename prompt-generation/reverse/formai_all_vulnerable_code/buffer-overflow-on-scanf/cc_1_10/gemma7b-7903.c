//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define PLAYER_X 'X'
#define PLAYER_O 'O'
#define EMPTY_SPOT '-'

char board[BOARD_SIZE][BOARD_SIZE] = {{EMPTY_SPOT, EMPTY_SPOT, EMPTY_SPOT},
    {EMPTY_SPOT, EMPTY_SPOT, EMPTY_SPOT},
    {EMPTY_SPOT, EMPTY_SPOT, EMPTY_SPOT}};

int availableMoves() {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col] == EMPTY_SPOT) {
                return 1;
            }
        }
    }
    return 0;
}

int selectMove() {
    int move = -1;
    printf("Enter your move (1-9): ");
    scanf("%d", &move);

    while (move < 1 || move > 9 || board[move / 3][(move - 1) / 3] != EMPTY_SPOT) {
        printf("Invalid move. Please try again: ");
        scanf("%d", &move);
    }

    return move;
}

void placeMove(int move) {
    board[move / 3][(move - 1) / 3] = PLAYER_X;
}

int checkWin(char player) {
    for (int row = 0; row < BOARD_SIZE; row++) {
        if (board[row][0] == player && board[row][1] == player && board[row][2] == player) {
            return 1;
        }
    }

    for (int col = 0; col < BOARD_SIZE; col++) {
        if (board[0][col] == player && board[1][col] == player && board[2][col] == player) {
            return 1;
        }
    }

    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }

    return 0;
}

int main() {
    char currentPlayer = PLAYER_X;
    int gameWon = 0;

    while (!gameWon && availableMoves()) {
        int move = selectMove();
        placeMove(move);

        if (checkWin(currentPlayer) == 1) {
            gameWon = 1;
            printf("You won!");
        } else {
            currentPlayer = PLAYER_O;
        }
    }

    if (!gameWon) {
        printf("It's a draw!");
    }

    return 0;
}