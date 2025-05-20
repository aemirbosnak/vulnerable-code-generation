//GEMINI-pro DATASET v1.0 Category: Checkers Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8

typedef struct {
    int row;
    int col;
} Move;

typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
    int num_black_pieces;
    int num_white_pieces;
    int current_player; // 0 for black, 1 for white
} Game;

void init_game(Game *game) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0) {
                game->board[i][j] = ' ';
            } else if (i < 3) {
                game->board[i][j] = 'b';
                game->num_black_pieces++;
            } else if (i > 4) {
                game->board[i][j] = 'w';
                game->num_white_pieces++;
            }
        }
    }
    game->current_player = 0;
}

void print_board(Game *game) {
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", game->board[i][j]);
        }
        printf("\n");
    }
}

int is_valid_move(Game *game, Move move) {
    if (game->board[move.row][move.col] != ' ') {
        return 0;
    }

    int opponent_color = game->current_player == 0 ? 'w' : 'b';
    if (abs(move.row - game->current_player) == 1 && abs(move.col - game->current_player) == 1 && game->board[move.row - game->current_player][move.col - game->current_player] == opponent_color) {
        return 1;
    }

    if (abs(move.row - game->current_player) == 2 && abs(move.col - game->current_player) == 2 && game->board[move.row - game->current_player / 2][move.col - game->current_player / 2] == opponent_color) {
        return 1;
    }

    return 0;
}

void make_move(Game *game, Move move) {
    game->board[move.row][move.col] = game->current_player == 0 ? 'b' : 'w';
    if (abs(move.row - game->current_player) == 2 && abs(move.col - game->current_player) == 2) {
        game->board[move.row - game->current_player / 2][move.col - game->current_player / 2] = ' ';
        if (game->current_player == 0) {
            game->num_white_pieces--;
        } else {
            game->num_black_pieces--;
        }
    }
    game->current_player = 1 - game->current_player;
}

int is_game_over(Game *game) {
    if (game->num_black_pieces == 0 || game->num_white_pieces == 0) {
        return 1;
    }

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (is_valid_move(game, (Move) {i, j})) {
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    Game game;
    init_game(&game);

    while (!is_game_over(&game)) {
        print_board(&game);

        char input[10];
        printf("Enter your move (row, col): ");
        scanf("%s", input);

        int row = input[0] - '0';
        int col = input[2] - '0';

        Move move = {row, col};

        if (is_valid_move(&game, move)) {
            make_move(&game, move);
        } else {
            printf("Invalid move. Please try again.\n");
        }
    }

    print_board(&game);

    if (game.num_black_pieces > game.num_white_pieces) {
        printf("Black wins!\n");
    } else if (game.num_white_pieces > game.num_black_pieces) {
        printf("White wins!\n");
    } else {
        printf("Draw!\n");
    }

    return 0;
}