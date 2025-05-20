//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8
#define BLACK 'B'
#define WHITE 'W'
#define EMPTY '.'

typedef struct {
    char board[SIZE][SIZE];
    char currentPlayer;
} CheckersGame;

void initializeBoard(CheckersGame *game) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i % 2 == 0 && j % 2 == 1 && i < 3) {
                game->board[i][j] = WHITE;
            } else if (i % 2 == 1 && j % 2 == 0 && i < 3) {
                game->board[i][j] = WHITE;
            } else if (i % 2 == 0 && j % 2 == 1 && i > 4) {
                game->board[i][j] = BLACK;
            } else if (i % 2 == 1 && j % 2 == 0 && i > 4) {
                game->board[i][j] = BLACK;
            } else {
                game->board[i][j] = EMPTY;
            }
        }
    }
    game->currentPlayer = BLACK;
}

void printBoard(CheckersGame *game) {
    printf("  A B C D E F G H\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", game->board[i][j]);
        }
        printf("\n");
    }
}

int isMoveValid(CheckersGame *game, int startX, int startY, int endX, int endY) {
    if (endX < 0 || endX >= SIZE || endY < 0 || endY >= SIZE) return 0;
    if (game->board[endX][endY] != EMPTY) return 0;

    int dx = endX - startX;
    int dy = endY - startY;

    if (game->currentPlayer == BLACK && dx == 1 && abs(dy) == 1) return 1;
    if (game->currentPlayer == WHITE && dx == -1 && abs(dy) == 1) return 1;
    return 0;
}

void makeMove(CheckersGame *game, int startX, int startY, int endX, int endY) {
    game->board[endX][endY] = game->board[startX][startY];
    game->board[startX][startY] = EMPTY;
}

void switchPlayer(CheckersGame *game) {
    game->currentPlayer = (game->currentPlayer == BLACK) ? WHITE : BLACK;
}

int main() {
    CheckersGame game;
    initializeBoard(&game);
    int startX, startY, endX, endY;
    char startCol, endCol;

    while (1) {
        printBoard(&game);
        printf("Current player: %c\n", game.currentPlayer);
        printf("Enter your move (e.g., A3 B4): ");
        
        if (scanf(" %c%d %c%d", &startCol, &startX, &endCol, &endX) != 4) {
            printf("Invalid input, please try again.\n");
            continue;
        }

        startX--; endX--; // Adjust for 0-based index
        startY = startCol - 'A';
        endY = endCol - 'A';

        if (isMoveValid(&game, startX, startY, endX, endY)) {
            makeMove(&game, startX, startY, endX, endY);
            switchPlayer(&game);
        } else {
            printf("Invalid move. Try again.\n");
        }
    }

    return 0;
}