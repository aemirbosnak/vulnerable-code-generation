//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define BOARD_SIZE 8
#define WHITE_PAWN 'P'
#define BLACK_PAWN 'p'
#define EMPTY '.'

typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
    bool whiteTurn;
} GameState;

void initializeBoard(GameState *game) {
    memset(game->board, EMPTY, sizeof(game->board));
    
    // Initialize pawns
    for (int i = 0; i < BOARD_SIZE; i++) {
        game->board[1][i] = WHITE_PAWN; // White pawns
        game->board[6][i] = BLACK_PAWN; // Black pawns
    }
    
    game->whiteTurn = true;
}

void printBoard(const GameState *game) {
    for (int i = BOARD_SIZE - 1; i >= 0; i--) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", game->board[i][j]);
        }
        printf("\n");
    }
    printf("Turn: %s\n", game->whiteTurn ? "White" : "Black");
}

bool isMoveValid(GameState *game, int startRow, int startCol, int endRow, int endCol) {
    char piece = game->board[startRow][startCol];
    if (piece == EMPTY || (game->whiteTurn && piece != WHITE_PAWN) || (!game->whiteTurn && piece != BLACK_PAWN)) {
        return false; // Invalid piece
    }
    
    if (game->whiteTurn) {
        // White pawn moves
        if (startCol == endCol && endRow == startRow + 1 && game->board[endRow][endCol] == EMPTY) {
            return true; // Move forward
        }
        if (startCol == endCol && startRow == 1 && endRow == 3 && game->board[2][endCol] == EMPTY && game->board[endRow][endCol] == EMPTY) {
            return true; // Double move
        }
        if (abs(startCol - endCol) == 1 && endRow == startRow + 1 && game->board[endRow][endCol] == BLACK_PAWN) {
            return true; // Capture
        }
    } else {
        // Black pawn moves
        if (startCol == endCol && endRow == startRow - 1 && game->board[endRow][endCol] == EMPTY) {
            return true; // Move forward
        }
        if (startCol == endCol && startRow == 6 && endRow == 4 && game->board[5][endCol] == EMPTY && game->board[endRow][endCol] == EMPTY) {
            return true; // Double move
        }
        if (abs(startCol - endCol) == 1 && endRow == startRow - 1 && game->board[endRow][endCol] == WHITE_PAWN) {
            return true; // Capture
        }
    }
    
    return false;
}

void makeMove(GameState *game, int startRow, int startCol, int endRow, int endCol) {
    game->board[endRow][endCol] = game->board[startRow][startCol]; // Move piece
    game->board[startRow][startCol] = EMPTY; // Empty previous spot
    game->whiteTurn = !game->whiteTurn; // Change turn
}

int main() {
    GameState game;
    initializeBoard(&game);
    
    int startRow, startCol, endRow, endCol;
    while (1) {
        printBoard(&game);
        
        printf("Enter move (startRow startCol endRow endCol): ");
        scanf("%d %d %d %d", &startRow, &startCol, &endRow, &endCol);
        
        if (isMoveValid(&game, startRow, startCol, endRow, endCol)) {
            makeMove(&game, startRow, startCol, endRow, endCol);
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
    
    return 0;
}