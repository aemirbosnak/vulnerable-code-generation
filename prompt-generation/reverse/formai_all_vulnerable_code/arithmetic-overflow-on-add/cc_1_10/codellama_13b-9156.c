//Code Llama-13B DATASET v1.0 Category: Checkers Game ; Style: lively
/*
 * Checkers Game in C
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BOARD_SIZE 8
#define MAX_PIECES 12

typedef enum { BLACK, WHITE } color_t;
typedef enum { EMPTY, BLACK_PIECE, WHITE_PIECE } piece_t;

typedef struct {
    piece_t board[MAX_BOARD_SIZE][MAX_BOARD_SIZE];
    int current_player;
    int num_moves;
} game_t;

void print_board(game_t *game) {
    int i, j;
    for (i = 0; i < MAX_BOARD_SIZE; i++) {
        for (j = 0; j < MAX_BOARD_SIZE; j++) {
            if (game->board[i][j] == EMPTY) {
                printf("   ");
            } else if (game->board[i][j] == BLACK_PIECE) {
                printf("B ");
            } else if (game->board[i][j] == WHITE_PIECE) {
                printf("W ");
            }
        }
        printf("\n");
    }
}

void initialize_game(game_t *game) {
    int i, j;
    for (i = 0; i < MAX_BOARD_SIZE; i++) {
        for (j = 0; j < MAX_BOARD_SIZE; j++) {
            game->board[i][j] = EMPTY;
        }
    }
    game->board[3][3] = game->board[3][4] = BLACK_PIECE;
    game->board[4][3] = game->board[4][4] = WHITE_PIECE;
    game->current_player = BLACK;
    game->num_moves = 0;
}

void make_move(game_t *game, int from_row, int from_col, int to_row, int to_col) {
    game->board[to_row][to_col] = game->board[from_row][from_col];
    game->board[from_row][from_col] = EMPTY;
    game->current_player = (game->current_player == BLACK) ? WHITE : BLACK;
    game->num_moves++;
}

void undo_move(game_t *game, int from_row, int from_col, int to_row, int to_col) {
    game->board[from_row][from_col] = game->board[to_row][to_col];
    game->board[to_row][to_col] = EMPTY;
    game->current_player = (game->current_player == BLACK) ? WHITE : BLACK;
    game->num_moves--;
}

int is_valid_move(game_t *game, int from_row, int from_col, int to_row, int to_col) {
    if (from_row < 0 || from_row >= MAX_BOARD_SIZE || from_col < 0 || from_col >= MAX_BOARD_SIZE) {
        return 0;
    }
    if (to_row < 0 || to_row >= MAX_BOARD_SIZE || to_col < 0 || to_col >= MAX_BOARD_SIZE) {
        return 0;
    }
    if (game->board[from_row][from_col] == EMPTY) {
        return 0;
    }
    if (game->board[from_row][from_col] != game->current_player) {
        return 0;
    }
    if (to_row == from_row && to_col == from_col) {
        return 0;
    }
    int diff_row = abs(from_row - to_row);
    int diff_col = abs(from_col - to_col);
    if (diff_row > 1 || diff_col > 1) {
        return 0;
    }
    if (diff_row == 1 || diff_col == 1) {
        if (game->board[to_row][to_col] != EMPTY) {
            return 0;
        }
    }
    return 1;
}

void main() {
    game_t game;
    initialize_game(&game);
    print_board(&game);
    while (1) {
        int from_row, from_col, to_row, to_col;
        printf("Enter move (from row, from col, to row, to col): ");
        scanf("%d %d %d %d", &from_row, &from_col, &to_row, &to_col);
        if (is_valid_move(&game, from_row, from_col, to_row, to_col)) {
            make_move(&game, from_row, from_col, to_row, to_col);
            print_board(&game);
        } else {
            undo_move(&game, from_row, from_col, to_row, to_col);
            printf("Invalid move. Try again.\n");
        }
    }
}