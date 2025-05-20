//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3

typedef struct {
    char board[SIZE][SIZE];
    char currentPlayer;
} Game;

void initializeBoard(Game *game) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            game->board[i][j] = ' ';
        }
    }
    game->currentPlayer = 'X';
}

void printBoard(Game *game) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", game->board[i][j]);
            if (j < SIZE - 1)
                printf("|");
        }
        printf("\n");
        if (i < SIZE - 1)
            printf("---|---|---\n");
    }
    printf("\n");
}

int isMoveValid(Game *game, int row, int col) {
    return row >= 0 && row < SIZE && col >= 0 && col < SIZE && 
           game->board[row][col] == ' ';
}

void makeMove(Game *game, int row, int col) {
    if (isMoveValid(game, row, col)) {
        game->board[row][col] = game->currentPlayer;
    }
}

int checkWinner(Game *game) {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if ((game->board[i][0] == game->currentPlayer && 
             game->board[i][1] == game->currentPlayer && 
             game->board[i][2] == game->currentPlayer) ||
            (game->board[0][i] == game->currentPlayer && 
             game->board[1][i] == game->currentPlayer && 
             game->board[2][i] == game->currentPlayer)) {
            return 1;
        }
    }

    // Check diagonals
    if ((game->board[0][0] == game->currentPlayer && 
         game->board[1][1] == game->currentPlayer && 
         game->board[2][2] == game->currentPlayer) ||
        (game->board[0][2] == game->currentPlayer && 
         game->board[1][1] == game->currentPlayer && 
         game->board[2][0] == game->currentPlayer)) {
        return 1;
    }

    // No winner
    return 0;
}

int isBoardFull(Game *game) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (game->board[i][j] == ' ')
                return 0;
        }
    }
    return 1;
}

void switchPlayer(Game *game) {
    game->currentPlayer = (game->currentPlayer == 'X') ? 'O' : 'X';
}

int main() {
    Game game;
    initializeBoard(&game);
    int row, col;
    int winner = 0;

    printf("Welcome to Tic-Tac-Toe!\n");
    printf("Player 1 (X) vs Player 2 (O)\n");

    while (!winner && !isBoardFull(&game)) {
        printBoard(&game);
        printf("Player %c, enter your move (row and column): ", game.currentPlayer);
        scanf("%d %d", &row, &col);

        if (isMoveValid(&game, row, col)) {
            makeMove(&game, row, col);
            winner = checkWinner(&game);
            if (!winner) {
                switchPlayer(&game);
            }
        } else {
            printf("Invalid move! Try again.\n");
        }
    }

    printBoard(&game);
    if (winner) {
        switchPlayer(&game);
        printf("Player %c wins!\n", game.currentPlayer);
    } else {
        printf("It's a draw!\n");
    }

    return 0;
}