//GEMINI-pro DATASET v1.0 Category: Checkers Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

typedef enum {
    EMPTY,
    WHITE,
    BLACK
} piece_t;

typedef struct {
    piece_t board[BOARD_SIZE][BOARD_SIZE];
    int white_pieces;
    int black_pieces;
} game_t;

void init_game(game_t *game) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0) {
                game->board[i][j] = EMPTY;
            } else if (i < 3) {
                game->board[i][j] = BLACK;
                game->black_pieces++;
            } else if (i > 4) {
                game->board[i][j] = WHITE;
                game->white_pieces++;
            } else {
                game->board[i][j] = EMPTY;
            }
        }
    }
}

void print_board(game_t *game) {
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            switch (game->board[i][j]) {
                case EMPTY:
                    printf("O ");
                    break;
                case WHITE:
                    printf("W ");
                    break;
                case BLACK:
                    printf("B ");
                    break;
            }
        }
        printf("\n");
    }
}

int main() {
    game_t game;

    init_game(&game);
    print_board(&game);

    return 0;
}