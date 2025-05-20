//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
    char player1;
    char player2;
    char currentPlayer;
} CheckersGame;

void initializeBoard(CheckersGame* game) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 1) {
                if (i < 3) {
                    game->board[i][j] = game->player1;  // Player 1 pieces
                } else if (i > 4) {
                    game->board[i][j] = game->player2;  // Player 2 pieces
                } else {
                    game->board[i][j] = ' ';  // Empty spaces
                }
            } else {
                game->board[i][j] = ' ';  // Empty spaces
            }
        }
    }
}

void printBoard(CheckersGame* game) {
    printf("  A B C D E F G H\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", game->board[i][j]);
        }
        printf("\n");
    }
}

int isValidMove(CheckersGame* game, int startX, int startY, int endX, int endY) {
    if (endX < 0 || endX >= BOARD_SIZE || endY < 0 || endY >= BOARD_SIZE) {
        return 0; // Out of bounds
    }
    if (game->board[endX][endY] != ' ') {
        return 0; // Destination is not empty
    }
    if (game->board[startX][startY] != game->currentPlayer) {
        return 0; // No piece of the current player
    }
    // Simple move validation (no jumping)
    if (abs(endX - startX) == 1 && abs(endY - startY) == 1) {
        return 1; // Valid simple move
    }
    return 0; // Invalid move
}

void makeMove(CheckersGame* game, int startX, int startY, int endX, int endY) {
    game->board[endX][endY] = game->board[startX][startY];
    game->board[startX][startY] = ' ';
}

int main() {
    CheckersGame game;
    game.player1 = 'X';
    game.player2 = 'O';
    game.currentPlayer = game.player1;

    initializeBoard(&game);
    printBoard(&game);

    char column;
    int row, startX, startY, endX, endY;

    while (1) {
        printf("Player %c's turn. Enter your move (e.g., A1 B2): ", game.currentPlayer);
        scanf(" %c%d %c%d", &column, &row, &column, &row);

        startX = row - 1;
        startY = column - 'A';
        endX = row - 1;
        endY = column - 'A';

        // Adjust for end position
        endX = row - 1;
        endY = column - 'A';

        if (isValidMove(&game, startX, startY, endX, endY)) {
            makeMove(&game, startX, startY, endX, endY);
            printBoard(&game);
            // Switch players
            game.currentPlayer = (game.currentPlayer == game.player1) ? game.player2 : game.player1;
        } else {
            printf("Invalid move. Try again.\n");
        }
    }

    return 0;
}