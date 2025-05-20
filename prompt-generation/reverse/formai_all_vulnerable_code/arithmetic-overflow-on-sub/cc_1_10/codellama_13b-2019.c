//Code Llama-13B DATASET v1.0 Category: Tic Tac Toe AI ; Style: modular
/*
 * Tic Tac Toe AI
 *
 * A modular implementation of a Tic Tac Toe AI in C.
 *
 * Author: [Your Name]
 * Date: [Today's Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Constants
#define MAX_BOARD_SIZE 9
#define NUM_ROWS 3
#define NUM_COLS 3

// Types
typedef enum {
    EMPTY,
    PLAYER_X,
    PLAYER_O
} CellState;

typedef struct {
    CellState board[MAX_BOARD_SIZE];
    int turn;
    int game_over;
} GameState;

// Function prototypes
void init_game(GameState *game);
void print_game(GameState *game);
int make_move(GameState *game, int row, int col);
int check_win(GameState *game);

// Function definitions
void init_game(GameState *game) {
    memset(game->board, EMPTY, MAX_BOARD_SIZE * sizeof(CellState));
    game->turn = 0;
    game->game_over = 0;
}

void print_game(GameState *game) {
    printf(" 1 | 2 | 3 \n");
    printf(" ---------\n");
    printf(" 4 | 5 | 6 \n");
    printf(" ---------\n");
    printf(" 7 | 8 | 9 \n");
    printf("\n");
}

int make_move(GameState *game, int row, int col) {
    if (game->board[row * NUM_COLS + col] == EMPTY) {
        if (game->turn == 0) {
            game->board[row * NUM_COLS + col] = PLAYER_X;
        } else {
            game->board[row * NUM_COLS + col] = PLAYER_O;
        }
        game->turn = 1 - game->turn;
        return 1;
    }
    return 0;
}

int check_win(GameState *game) {
    // Check rows
    for (int row = 0; row < NUM_ROWS; row++) {
        if (game->board[row * NUM_COLS] == game->board[row * NUM_COLS + 1] &&
            game->board[row * NUM_COLS + 1] == game->board[row * NUM_COLS + 2]) {
            return game->board[row * NUM_COLS];
        }
    }

    // Check cols
    for (int col = 0; col < NUM_COLS; col++) {
        if (game->board[col] == game->board[col + NUM_COLS] &&
            game->board[col + NUM_COLS] == game->board[col + 2 * NUM_COLS]) {
            return game->board[col];
        }
    }

    // Check diagonals
    if (game->board[0] == game->board[4] && game->board[4] == game->board[8]) {
        return game->board[0];
    }
    if (game->board[2] == game->board[4] && game->board[4] == game->board[6]) {
        return game->board[2];
    }

    // Check if game is over
    for (int i = 0; i < MAX_BOARD_SIZE; i++) {
        if (game->board[i] == EMPTY) {
            return 0;
        }
    }
    return -1;
}

int main() {
    GameState game;
    init_game(&game);

    while (1) {
        print_game(&game);

        if (game.game_over) {
            if (game.board[4] == PLAYER_X) {
                printf("Player X wins!\n");
            } else if (game.board[4] == PLAYER_O) {
                printf("Player O wins!\n");
            } else {
                printf("It's a tie!\n");
            }
            break;
        }

        int row, col;
        printf("Enter a row (1-3) and a col (1-3): ");
        scanf("%d %d", &row, &col);

        if (make_move(&game, row - 1, col - 1)) {
            game.game_over = check_win(&game);
        } else {
            printf("Invalid move!\n");
        }
    }

    return 0;
}