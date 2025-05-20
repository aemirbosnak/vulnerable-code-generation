//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8
#define WHITE 'W'
#define BLACK 'B'
#define EMPTY ' '

typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
    char currentPlayer;
} GameState;

void initializeBoard(GameState *game) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            game->board[i][j] = EMPTY;
        }
    }

    // Placing pieces for both players
    for (int j = 0; j < BOARD_SIZE; j++) {
        game->board[1][j] = WHITE;
        game->board[6][j] = BLACK;
    }

    game->board[0][0] = game->board[0][7] = WHITE; // Rooks
    game->board[0][1] = game->board[0][6] = WHITE; // Knights
    game->board[0][2] = game->board[0][5] = WHITE; // Bishops
    game->board[0][3] = WHITE; // Queen
    game->board[0][4] = WHITE; // King

    game->board[7][0] = game->board[7][7] = BLACK; // Rooks
    game->board[7][1] = game->board[7][6] = BLACK; // Knights
    game->board[7][2] = game->board[7][5] = BLACK; // Bishops
    game->board[7][3] = BLACK; // Queen
    game->board[7][4] = BLACK; // King

    game->currentPlayer = WHITE;
}

void printBoard(GameState *game) {
    printf("  A B C D E F G H\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", 8 - i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", game->board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int isValidMove(GameState *game, int fromX, int fromY, int toX, int toY) {
    if (toX < 0 || toX >= BOARD_SIZE || toY < 0 || toY >= BOARD_SIZE) {
        return 0; // Move is out of bounds
    }

    if (game->board[fromX][fromY] == EMPTY) {
        return 0; // No piece at the from position
    }

    if (game->board[toX][toY] != EMPTY &&
        game->board[toX][toY] == game->currentPlayer) {
        return 0; // Can't capture your own piece
    }

    return 1; // Valid move
}

void movePiece(GameState *game, int fromX, int fromY, int toX, int toY) {
    game->board[toX][toY] = game->board[fromX][fromY];
    game->board[fromX][fromY] = EMPTY;
}

void switchPlayer(GameState *game) {
    game->currentPlayer = (game->currentPlayer == WHITE) ? BLACK : WHITE;
}

void playGame() {
    GameState game;
    initializeBoard(&game);
    printBoard(&game);

    char from[3], to[3];
    while (1) {
        printf("Player %c, enter your move (e.g., A2 A3) or type 'exit' to quit: ", game.currentPlayer);
        scanf("%s", from);
        if (strcmp(from, "exit") == 0) {
            break;
        }
        scanf("%s", to);

        int fromX = 8 - (from[1] - '0');
        int fromY = from[0] - 'A';
        int toX = 8 - (to[1] - '0');
        int toY = to[0] - 'A';

        if (isValidMove(&game, fromX, fromY, toX, toY)) {
            movePiece(&game, fromX, fromY, toX, toY);
            printBoard(&game);
            switchPlayer(&game);
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
}

int main() {
    playGame();
    return 0;
}