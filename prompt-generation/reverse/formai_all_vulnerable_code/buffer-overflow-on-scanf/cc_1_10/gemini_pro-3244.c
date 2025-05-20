//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: Cryptic
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

typedef struct {
    int x, y;
} point_t;

typedef struct {
    point_t p1, p2;
} move_t;

typedef struct {
    bool board[BOARD_SIZE][BOARD_SIZE];
    bool flipped[BOARD_SIZE][BOARD_SIZE];
    int score;
} game_t;

void print_board(game_t *game);
bool is_valid_move(game_t *game, move_t move);
bool is_game_over(game_t *game);
void make_move(game_t *game, move_t move);
void flip_cards(game_t *game, move_t move);
void reset_game(game_t *game);

int main(void) {
    srand(time(NULL));  // Initialize random number generator

    game_t game;
    reset_game(&game);

    while (!is_game_over(&game)) {
        print_board(&game);

        move_t move;
        printf("Enter your move (e.g. \"1 2 3 4\"): ");
        scanf("%d %d %d %d", &move.p1.x, &move.p1.y, &move.p2.x, &move.p2.y);

        if (is_valid_move(&game, move)) {
            make_move(&game, move);
        } else {
            printf("Invalid move!\n");
        }
    }

    print_board(&game);

    if (game.score == BOARD_SIZE * BOARD_SIZE) {
        printf("You win!\n");
    } else {
        printf("You lose!\n");
    }

    return 0;
}

void print_board(game_t *game) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (game->flipped[i][j]) {
                printf("%d ", game->board[i][j]);
            } else {
                printf("X ");
            }
        }
        printf("\n");
    }
}

bool is_valid_move(game_t *game, move_t move) {
    return move.p1.x >= 0 && move.p1.x < BOARD_SIZE &&
           move.p1.y >= 0 && move.p1.y < BOARD_SIZE &&
           move.p2.x >= 0 && move.p2.x < BOARD_SIZE &&
           move.p2.y >= 0 && move.p2.y < BOARD_SIZE &&
           !game->flipped[move.p1.x][move.p1.y] &&
           !game->flipped[move.p2.x][move.p2.y];
}

bool is_game_over(game_t *game) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (!game->flipped[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void make_move(game_t *game, move_t move) {
    flip_cards(game, move);

    if (game->board[move.p1.x][move.p1.y] == game->board[move.p2.x][move.p2.y]) {
        game->score += 2;
    } else {
        flip_cards(game, move);
    }
}

void flip_cards(game_t *game, move_t move) {
    game->flipped[move.p1.x][move.p1.y] = true;
    game->flipped[move.p2.x][move.p2.y] = true;
}

void reset_game(game_t *game) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            game->board[i][j] = rand() % 2;
            game->flipped[i][j] = false;
        }
    }
    game->score = 0;
}