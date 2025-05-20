//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8
#define EMPTY ' '
#define PLAYER1_PIECE 'X'
#define PLAYER2_PIECE 'O'

typedef struct {
    char board[SIZE][SIZE];
    int turn; // 1 for Player 1, 2 for Player 2
} Game;

void initializeBoard(Game *game) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ((i % 2) != (j % 2) && i < 3)
                game->board[i][j] = PLAYER1_PIECE;
            else if ((i % 2) != (j % 2) && i > 4)
                game->board[i][j] = PLAYER2_PIECE;
            else
                game->board[i][j] = EMPTY;
        }
    }
    game->turn = 1; // Start with Player 1
}

void printBoard(Game *game) {
    printf("  A B C D E F G H\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", game->board[i][j]);
        }
        printf("\n");
    }
}

int isValidMove(Game *game, int srcRow, int srcCol, int destRow, int destCol) {
    if (destRow < 0 || destRow >= SIZE || destCol < 0 || destCol >= SIZE)
        return 0; // Out of bounds
    if (game->board[destRow][destCol] != EMPTY)
        return 0; // Destination not empty

    int dir = (game->turn == 1) ? 1 : -1; // Determine direction for player
    if (destRow - srcRow == dir && abs(destCol - srcCol) == 1)
        return 1; // Normal move
    if (destRow - srcRow == dir * 2 && abs(destCol - srcCol) == 2) {
        int midRow = (srcRow + destRow) / 2;
        int midCol = (srcCol + destCol) / 2;
        char opponentPiece = (game->turn == 1) ? PLAYER2_PIECE : PLAYER1_PIECE;
        if (game->board[midRow][midCol] == opponentPiece)
            return 1; // Capture move
    }
    return 0; // Invalid move
}

void makeMove(Game *game, int srcRow, int srcCol, int destRow, int destCol) {
    char movingPiece = game->board[srcRow][srcCol];
    game->board[destRow][destCol] = movingPiece;
    game->board[srcRow][srcCol] = EMPTY;

    // Check for capture
    if (abs(destRow - srcRow) == 2) {
        int midRow = (srcRow + destRow) / 2;
        int midCol = (srcCol + destCol) / 2;
        game->board[midRow][midCol] = EMPTY; // Remove captured piece
    }
}

void switchTurn(Game *game) {
    game->turn = (game->turn == 1) ? 2 : 1; // Toggle between players
}

int main() {
    Game game;
    initializeBoard(&game);
    int srcRow, srcCol, destRow, destCol;
    char srcColChar, destColChar;

    while (1) {
        printBoard(&game);
        printf("Player %d's turn. Enter move (e.g., A3 B4): ", game.turn);
        scanf(" %c%d %c%d", &srcColChar, &srcRow, &destColChar, &destRow);
        srcCol = srcColChar - 'A';
        srcRow -= 1;
        destCol = destColChar - 'A';
        destRow -= 1;

        if (isValidMove(&game, srcRow, srcCol, destRow, destCol)) {
            makeMove(&game, srcRow, srcCol, destRow, destCol);
            switchTurn(&game);
        } else {
            printf("Invalid move! Try again.\n");
        }
    }

    return 0;
}