//GEMINI-pro DATASET v1.0 Category: Checkers Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    char type;
    Position position;
} Piece;

typedef struct {
    Piece board[BOARD_SIZE][BOARD_SIZE];
    int turn;
} Game;

void print_board(Game *game) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            Piece piece = game->board[i][j];
            if (piece.type == ' ') {
                printf("  ");
            } else if (piece.type == 'b') {
                printf("b ");
            } else if (piece.type == 'w') {
                printf("w ");
            } else if (piece.type == 'B') {
                printf("B ");
            } else if (piece.type == 'W') {
                printf("W ");
            }
        }
        printf("\n");
    }
}

int main() {
    Game game;
    memset(&game, 0, sizeof(Game));

    // Initialize the board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0) {
                if (i < 3) {
                    game.board[i][j].type = 'b';
                } else if (i > 4) {
                    game.board[i][j].type = 'w';
                }
            }
        }
    }

    // Print the board
    print_board(&game);

    // Get the user's input
    while (1) {
        char input[100];
        printf("Enter your move: ");
        scanf("%s", input);

        // Parse the input
        Position from;
        Position to;
        sscanf(input, "%d%d %d%d", &from.x, &from.y, &to.x, &to.y);

        // Make the move
        Piece piece = game.board[from.x][from.y];
        game.board[from.x][from.y] = game.board[to.x][to.y];
        game.board[to.x][to.y] = piece;

        // Check if the game is over
        int game_over = 0;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                Piece piece = game.board[i][j];
                if (piece.type == 'b' || piece.type == 'w') {
                    game_over = 1;
                }
            }
        }

        if (game_over) {
            printf("Game over!\n");
            break;
        }

        // Print the board
        print_board(&game);
    }

    return 0;
}