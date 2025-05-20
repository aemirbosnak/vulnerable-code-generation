//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 8

typedef enum { EMPTY, PLAYER1, PLAYER2 } Piece;

typedef struct {
    Piece board[SIZE][SIZE];
} GameBoard;

void initializeBoard(GameBoard *game) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ((i + j) % 2 == 1) {
                if (i < 3) game->board[i][j] = PLAYER1;
                else if (i > 4) game->board[i][j] = PLAYER2;
                else game->board[i][j] = EMPTY;
            } else {
                game->board[i][j] = EMPTY;
            }
        }
    }
}

void printBoard(const GameBoard *game) {
    printf("\n   A B C D E F G H\n");
    printf("  +----------------\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d |", i + 1);
        for (int j = 0; j < SIZE; j++) {
            char pieceSymbol;
            switch (game->board[i][j]) {
                case EMPTY: pieceSymbol = '.'; break;
                case PLAYER1: pieceSymbol = 'X'; break;
                case PLAYER2: pieceSymbol = 'O'; break;
                default: pieceSymbol = '?'; break;
            }
            printf("%c ", pieceSymbol);
        }
        printf("\n");
    }
}

bool isMoveValid(const GameBoard *game, int startRow, int startCol, int endRow, int endCol, Piece player) {
    if (endRow < 0 || endRow >= SIZE || endCol < 0 || endCol >= SIZE || game->board[endRow][endCol] != EMPTY) {
        return false; 
    }
    int rowDiff = endRow - startRow;
    int colDiff = endCol - startCol;

    // Normal move
    if ((colDiff == 1 || colDiff == -1) && (rowDiff == 1 || rowDiff == -1) && game->board[startRow][startCol] == player) {
        return true;
    }

    // Jump move
    if ((colDiff == 2 || colDiff == -2) && (rowDiff == 2 || rowDiff == -2)) {
        int jumpedRow = (startRow + endRow) / 2;
        int jumpedCol = (startCol + endCol) / 2;
        if (game->board[jumpedRow][jumpedCol] != player && game->board[jumpedRow][jumpedCol] != EMPTY) {
            return true;
        }
    }
    return false;
}

void makeMove(GameBoard *game, int startRow, int startCol, int endRow, int endCol) {
    game->board[endRow][endCol] = game->board[startRow][startCol];
    game->board[startRow][startCol] = EMPTY;

    // Check for jump and remove jumped piece
    if (abs(endRow - startRow) == 2) {
        int jumpedRow = (startRow + endRow) / 2;
        int jumpedCol = (startCol + endCol) / 2;
        game->board[jumpedRow][jumpedCol] = EMPTY;
    }
}

bool isGameOver(const GameBoard *game) {
    bool hasPlayer1 = false;
    bool hasPlayer2 = false;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (game->board[i][j] == PLAYER1) hasPlayer1 = true;
            if (game->board[i][j] == PLAYER2) hasPlayer2 = true;
        }
    }
    return !hasPlayer1 || !hasPlayer2;
}

void swapPlayers(Piece *currentPlayer) {
    *currentPlayer = (*currentPlayer == PLAYER1) ? PLAYER2 : PLAYER1;
}

int main() {
    GameBoard game;
    initializeBoard(&game);
    Piece currentPlayer = PLAYER1;
    
    while (!isGameOver(&game)) {
        printBoard(&game);
        char col, temp;
        int row;
        
        printf("Player %d's turn! Enter move (e.g., A3 B4): ", (currentPlayer == PLAYER1) ? 1 : 2);
        scanf(" %c%d %c%d", &col, &row, &temp, &col);
        
        int startRow = row - 1;
        int startCol = col - 'A';
        int endRow = temp - '0' - 1;
        int endCol = col - 'A';

        if (isMoveValid(&game, startRow, startCol, endRow, endCol, currentPlayer)) {
            makeMove(&game, startRow, startCol, endRow, endCol);
            swapPlayers(&currentPlayer);
        } else {
            printf("Invalid Move! Try again.\n");
        }
    }
    
    printBoard(&game);
    printf("Game Over! Player %d wins!\n", (currentPlayer == PLAYER1) ? 2 : 1);
    return 0;
}