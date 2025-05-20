//Code Llama-13B DATASET v1.0 Category: Table Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_ROWS 5
#define NUM_COLS 5
#define MAX_LEN 256

struct GameState {
    int game_over;
    int score;
    char board[NUM_ROWS][NUM_COLS];
};

void initialize_board(struct GameState* game) {
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            game->board[i][j] = ' ';
        }
    }
}

void print_board(struct GameState* game) {
    printf("  1 2 3 4 5\n");
    for (int i = 0; i < NUM_ROWS; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < NUM_COLS; j++) {
            printf("%c ", game->board[i][j]);
        }
        printf("\n");
    }
}

int is_move_valid(struct GameState* game, int row, int col) {
    if (row < 0 || row >= NUM_ROWS || col < 0 || col >= NUM_COLS) {
        return 0;
    }
    if (game->board[row][col] != ' ') {
        return 0;
    }
    return 1;
}

void make_move(struct GameState* game, int row, int col, char player) {
    if (is_move_valid(game, row, col)) {
        game->board[row][col] = player;
        game->score += (player == 'X') ? 1 : -1;
    }
}

void play_game(struct GameState* game) {
    initialize_board(game);
    game->score = 0;
    game->game_over = 0;
    while (!game->game_over) {
        print_board(game);
        int row, col;
        printf("Enter a row and column to make a move: ");
        scanf("%d %d", &row, &col);
        make_move(game, row, col, 'X');
        if (game->score == NUM_ROWS * NUM_COLS) {
            game->game_over = 1;
        }
    }
}

int main() {
    srand(time(NULL));
    struct GameState game;
    play_game(&game);
    return 0;
}