//GPT-4o-mini DATASET v1.0 Category: Chess AI ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BOARD_SIZE 8
#define EMPTY 0
#define WHITE 1
#define BLACK 2

typedef struct {
    int board[BOARD_SIZE][BOARD_SIZE];
    int currentPlayer;
} GameState;

void initializeGame(GameState* game) {
    memset(game->board, 0, sizeof(game->board));
    game->currentPlayer = WHITE;

    // Set up pieces
    game->board[0][0] = game->board[0][7] = BLACK; // Rooks
    game->board[0][1] = game->board[0][6] = BLACK; // Knights
    game->board[0][2] = game->board[0][5] = BLACK; // Bishops
    game->board[0][3] = BLACK; // Queen
    game->board[0][4] = BLACK; // King

    for (int i = 0; i < BOARD_SIZE; i++) {
        game->board[1][i] = BLACK; // Black Pawns
    }

    game->board[7][0] = game->board[7][7] = WHITE; // Rooks
    game->board[7][1] = game->board[7][6] = WHITE; // Knights
    game->board[7][2] = game->board[7][5] = WHITE; // Bishops
    game->board[7][3] = WHITE; // Queen
    game->board[7][4] = WHITE; // King

    for (int i = 0; i < BOARD_SIZE; i++) {
        game->board[6][i] = WHITE; // White Pawns
    }
}

void printBoard(const GameState* game) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            switch (game->board[i][j]) {
                case WHITE: printf("W "); break;
                case BLACK: printf("B "); break;
                case EMPTY: printf(". "); break;
            }
        }
        printf("\n");
    }
    printf("\n");
}

int isValidMove(GameState* game, int startX, int startY, int endX, int endY) {
    // Check bounds
    if (startX < 0 || startX >= BOARD_SIZE || startY < 0 || startY >= BOARD_SIZE || 
        endX < 0 || endX >= BOARD_SIZE || endY < 0 || endY >= BOARD_SIZE) {
        return 0;
    }

    // Check if there's a piece to move
    if (game->board[startX][startY] != game->currentPlayer) {
        return 0;
    }

    // For simplicity, we're allowing moving to any empty square or capturing an opponent's piece
    if (game->board[endX][endY] != EMPTY && game->board[endX][endY] == game->currentPlayer) {
        return 0;
    }

    return 1;
}

void makeMove(GameState* game, int startX, int startY, int endX, int endY) {
    game->board[endX][endY] = game->board[startX][startY];
    game->board[startX][startY] = EMPTY;
}

void switchPlayer(GameState* game) {
    game->currentPlayer = (game->currentPlayer == WHITE) ? BLACK : WHITE;
}

int main() {
    GameState game;
    initializeGame(&game);
    
    int startX, startY, endX, endY;

    while (1) {
        printBoard(&game);
        printf("Player %s turn. Enter your move (startX startY endX endY): ", 
               game.currentPlayer == WHITE ? "WHITE" : "BLACK");
        scanf("%d %d %d %d", &startX, &startY, &endX, &endY);

        if (isValidMove(&game, startX, startY, endX, endY)) {
            makeMove(&game, startX, startY, endX, endY);
            switchPlayer(&game);
        } else {
            printf("Invalid move! Try again.\n");
        }
    }
    
    return 0;
}