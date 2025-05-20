//GEMINI-pro DATASET v1.0 Category: Checkers Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    EMPTY,
    BLACK,
    RED
} piece_t;

typedef struct {
    piece_t board[8][8];
    piece_t turn;
    int black_pieces;
    int red_pieces;
} game_t;

void init_game(game_t *game) {
    memset(game->board, EMPTY, sizeof(game->board));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0) {
                game->board[i][j] = BLACK;
                game->black_pieces++;
            }
        }
    }
    for (int i = 5; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0) {
                game->board[i][j] = RED;
                game->red_pieces++;
            }
        }
    }
    game->turn = BLACK;
}

void print_board(game_t *game) {
    printf("   A B C D E F G H\n");
    printf(" +-----------------+\n");
    for (int i = 0; i < 8; i++) {
        printf("%d|", i + 1);
        for (int j = 0; j < 8; j++) {
            switch (game->board[i][j]) {
                case EMPTY:
                    printf("  ");
                    break;
                case BLACK:
                    printf("B ");
                    break;
                case RED:
                    printf("R ");
                    break;
            }
        }
        printf("|\n");
    }
    printf(" +-----------------+\n");
}

int is_valid_move(game_t *game, int from_row, int from_col, int to_row, int to_col) {
    piece_t piece = game->board[from_row][from_col];
    piece_t opponent = piece == BLACK ? RED : BLACK;
    int drow = to_row - from_row;
    int dcol = to_col - from_col;
    if (piece == EMPTY || game->turn != piece || abs(drow) != 1 || abs(dcol) != 1) {
        return 0;
    }
    if (game->board[to_row][to_col] != EMPTY) {
        return 0;
    }
    if (piece == BLACK && to_row == 0) {
        return 0;
    }
    if (piece == RED && to_row == 7) {
        return 0;
    }
    if (game->board[from_row + drow / 2][from_col + dcol / 2] != opponent) {
        return 0;
    }
    return 1;
}

void make_move(game_t *game, int from_row, int from_col, int to_row, int to_col) {
    piece_t piece = game->board[from_row][from_col];
    piece_t opponent = piece == BLACK ? RED : BLACK;
    game->board[from_row][from_col] = EMPTY;
    game->board[to_row][to_col] = piece;
    if (abs(to_row - from_row) == 2) {
        game->board[from_row + (to_row - from_row) /
            2][from_col + (to_col - from_col) / 2] = EMPTY;
        if (piece == BLACK) {
            game->black_pieces--;
        } else {
            game->red_pieces--;
        }
    }
    game->turn = opponent;
}

int is_game_over(game_t *game) {
    return game->black_pieces == 0 || game->red_pieces == 0;
}

int main() {
    game_t game;
    int from_row, from_col, to_row, to_col;

    init_game(&game);
    print_board(&game);

    while (!is_game_over(&game)) {
        printf("Player %s's turn:\n", game.turn == BLACK ? "Black" : "Red");
        printf("Enter move (from row, from column, to row, to column): ");
        scanf("%d %d %d %d", &from_row, &from_col, &to_row, &to_col);

        if (!is_valid_move(&game, from_row - 1, from_col - 1, to_row - 1, to_col - 1)) {
            printf("Invalid move!\n");
            continue;
        }

        make_move(&game, from_row - 1, from_col - 1, to_row - 1, to_col - 1);
        print_board(&game);
    }

    if (game.black_pieces == 0) {
        printf("Red wins!\n");
    } else {
        printf("Black wins!\n");
    }

    return 0;
}