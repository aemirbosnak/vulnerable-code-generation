//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
    char player;
} CheckersGame;

void initializeBoard(CheckersGame *game) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 != 0 && i < 3) {
                game->board[i][j] = 'b'; // black pieces
            } else if ((i + j) % 2 != 0 && i > 4) {
                game->board[i][j] = 'r'; // red pieces
            } else {
                game->board[i][j] = ' '; // empty square
            }
        }
    }
    game->player = 'r'; // Red starts the game
}

void printBoard(CheckersGame *game) {
    printf("  A B C D E F G H\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf(" %c", game->board[i][j]);
        }
        printf("\n");
    }
}

int isValidMove(CheckersGame *game, int fromRow, int fromCol, int toRow, int toCol) {
    char piece = game->board[fromRow][fromCol];
    if (piece == ' ' || (piece != game->player && piece != toRow)) {
        return 0; // invalid if piece is empty or not player's piece
    }
    if ((fromRow + 1 == toRow || fromRow - 1 == toRow) &&
        (fromCol + 1 == toCol || fromCol - 1 == toCol)) {
        return 1; // valid single square move
    }
    return 0; // any other case is invalid
}

void switchPlayer(CheckersGame *game) {
    game->player = (game->player == 'r') ? 'b' : 'r'; // switch between players
}

void makeMove(CheckersGame *game, int fromRow, int fromCol, int toRow, int toCol) {
    game->board[toRow][toCol] = game->board[fromRow][fromCol];
    game->board[fromRow][fromCol] = ' '; // empty the old square
}

int main() {
    CheckersGame game;
    initializeBoard(&game);
    int fromRow, fromCol, toRow, toCol;
    char *columnNames = "ABCDEFGH";
    printf("Welcome to the Checkers Game in the realm of Sherlock Holmes!\n");
    
    while (1) {
        printBoard(&game);
        printf("Player %c's turn. Enter your move (e.g., E4 D5): ", game.player);
        char fromColChar, toColChar;
        scanf(" %c%d %c%d", &fromColChar, &fromRow, &toColChar, &toRow);

        fromCol = fromColChar - 'A';
        toCol = toColChar - 'A';
        fromRow -= 1; // Align with 0 indexing
        toRow -= 1; // Align with 0 indexing

        if (isValidMove(&game, fromRow, fromCol, toRow, toCol)) {
            makeMove(&game, fromRow, fromCol, toRow, toCol);
            switchPlayer(&game);
        } else {
            printf("Alas! That is not a valid move, it appears.\n");
        }
    }
    return 0;
}