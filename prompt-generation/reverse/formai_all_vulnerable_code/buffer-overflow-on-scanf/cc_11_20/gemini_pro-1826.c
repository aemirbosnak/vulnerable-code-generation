//GEMINI-pro DATASET v1.0 Category: Checkers Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

typedef struct {
    int x, y;
} Position;

typedef struct {
    int player;
    Position position;
} Piece;

typedef struct {
    Piece board[BOARD_SIZE][BOARD_SIZE];
    int turn;
} Game;

void print_board(Game *game) {
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            Piece piece = game->board[i][j];
            if (piece.player == 0) {
                printf("  ");
            } else if (piece.player == 1) {
                printf("░░");
            } else if (piece.player == 2) {
                printf("▒▒");
            }
        }
        printf("\n");
    }
}

int main() {
    Game game;

    // Initialize the game board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            game.board[i][j].player = 0;
            game.board[i][j].position.x = i;
            game.board[i][j].position.y = j;
        }
    }

    // Set the initial positions of the pieces
    for (int i = 0; i < BOARD_SIZE; i++) {
        game.board[i][0].player = 1;
        game.board[i][BOARD_SIZE - 1].player = 2;
    }

    // Set the initial turn
    game.turn = 1;

    // Main game loop
    while (1) {
        // Print the game board
        print_board(&game);

        // Get the player's move
        Position move;
        printf("Player %d's move: ", game.turn);
        scanf("%d %d", &move.x, &move.y);

        // Check if the move is valid
        if (move.x < 0 || move.x >= BOARD_SIZE || move.y < 0 || move.y >= BOARD_SIZE) {
            printf("Invalid move. Try again.\n");
            continue;
        }

        Piece piece = game.board[move.x][move.y];
        if (piece.player != game.turn) {
            printf("Invalid move. Try again.\n");
            continue;
        }

        // Make the move
        game.board[move.x][move.y].position.x += (game.turn == 1) ? 1 : -1;
        game.board[move.x][move.y].position.y += (game.turn == 1) ? 1 : -1;

        // Check if the game is over
        if (piece.position.x == 0 || piece.position.x == BOARD_SIZE - 1) {
            printf("Player %d wins!\n", game.turn);
            break;
        }

        // Switch the turn
        game.turn = (game.turn == 1) ? 2 : 1;
    }

    return 0;
}