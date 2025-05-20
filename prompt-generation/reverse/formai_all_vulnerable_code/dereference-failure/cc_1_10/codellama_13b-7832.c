//Code Llama-13B DATASET v1.0 Category: Table Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 6
#define MAX_COLS 7

// Define a struct to represent a table game
typedef struct {
    int rows;
    int cols;
    int** cells;
} Game;

// Define a function to initialize a game
void init_game(Game* game) {
    game->rows = MAX_ROWS;
    game->cols = MAX_COLS;
    game->cells = (int**)malloc(game->rows * sizeof(int*));
    for (int i = 0; i < game->rows; i++) {
        game->cells[i] = (int*)malloc(game->cols * sizeof(int));
        for (int j = 0; j < game->cols; j++) {
            game->cells[i][j] = 0;
        }
    }
}

// Define a function to print the game board
void print_game_board(Game* game) {
    for (int i = 0; i < game->rows; i++) {
        for (int j = 0; j < game->cols; j++) {
            printf("%d ", game->cells[i][j]);
        }
        printf("\n");
    }
}

// Define a function to make a move
void make_move(Game* game, int row, int col) {
    game->cells[row][col] = 1;
}

// Define a function to check if the game is over
int check_game_over(Game* game) {
    for (int i = 0; i < game->rows; i++) {
        for (int j = 0; j < game->cols; j++) {
            if (game->cells[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

// Define a function to run the game
void run_game(Game* game) {
    srand(time(NULL));
    while (1) {
        int row = rand() % game->rows;
        int col = rand() % game->cols;
        make_move(game, row, col);
        print_game_board(game);
        if (check_game_over(game)) {
            printf("Game over!\n");
            break;
        }
    }
}

int main() {
    Game game;
    init_game(&game);
    run_game(&game);
    return 0;
}