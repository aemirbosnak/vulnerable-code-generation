//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 8
#define DARK '#'
#define LIGHT '.'
#define RED 'R'
#define WHITE 'W'
#define INVALID -1

typedef struct {
    char board[SIZE][SIZE];
    int selected_x, selected_y;
} GameState;

void initialize_board(GameState *game) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            game->board[i][j] = (i % 2 == j % 2) ? LIGHT : DARK;
            if (i < 3 && (i % 2 != j % 2)) {
                game->board[i][j] = RED;
            } else if (i > 4 && (i % 2 != j % 2)) {
                game->board[i][j] = WHITE;
            }
        }
    }
    game->selected_x = INVALID;
    game->selected_y = INVALID;
}

void print_board(const GameState *game) {
    printf("\033[0;32mCyberpunk Checkers\n\n\033[0m");
    printf("  a b c d e f g h\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", game->board[i][j]);
        }
        printf("\n");
    }
}

int is_valid_move(GameState *game, int old_x, int old_y, int new_x, int new_y) {
    if (new_x < 0 || new_y < 0 || new_x >= SIZE || new_y >= SIZE) {
        return 0;
    }
    if (game->board[new_x][new_y] != LIGHT) {
        return 0;
    }
    if (abs(new_x - old_x) != 1 || abs(new_y - old_y) != 1) {
        return 0;
    }
    return 1;
}

void select_piece(GameState *game, int x, int y) {
    if (game->board[x][y] == RED && (game->selected_x == INVALID)) {
        game->selected_x = x;
        game->selected_y = y;
    }
}

void move_piece(GameState *game, int x, int y) {
    if (game->selected_x != INVALID) {
        if (is_valid_move(game, game->selected_x, game->selected_y, x, y)) {
            game->board[y][x] = RED; // Move to new position
            game->board[game->selected_y][game->selected_x] = LIGHT; // Clear old position
        }
        game->selected_x = INVALID; // Reset selection
        game->selected_y = INVALID;
    }
}

int main() {
    GameState game;
    initialize_board(&game);
    char input[10];
    int x, y;

    while (1) {
        print_board(&game);
        printf("Select your piece (e.g., 'a1'): ");
        scanf("%s", input);
        if (input[0] == 'q') break; // Quit command
        x = input[0] - 'a';
        y = input[1] - '1';

        if (game.selected_x == INVALID) {
            select_piece(&game, y, x);
        } else {
            move_piece(&game, y, x);
        }
    }
    return 0;
}