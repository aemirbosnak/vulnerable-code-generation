//Falcon2-11B DATASET v1.0 Category: Pac-Man Game Clone ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_ROWS 20
#define MAX_COLS 20
#define PADDING 2

typedef struct {
    int row;
    int col;
    int score;
    int direction;
    int alive;
} Player;

typedef struct {
    char grid[MAX_ROWS][MAX_COLS];
    int num_moves;
    Player pacman;
    Player ghost;
    Player food;
} Game;

int main() {
    srand(time(NULL));

    Game game;
    game.pacman.row = (rand() % MAX_ROWS) + 1;
    game.pacman.col = (rand() % MAX_COLS) + 1;
    game.pacman.direction = 0;
    game.pacman.alive = 1;

    game.ghost.row = (rand() % MAX_ROWS) + 1;
    game.ghost.col = (rand() % MAX_COLS) + 1;
    game.ghost.direction = 0;
    game.ghost.alive = 1;

    game.food.row = (rand() % MAX_ROWS) + 1;
    game.food.col = (rand() % MAX_COLS) + 1;
    game.food.direction = 0;
    game.food.alive = 1;

    game.num_moves = 0;

    printf("Welcome to Pac-Man!\n");

    while (game.pacman.alive && game.ghost.alive) {
        printf("Pacman: %d,%d ", game.pacman.row, game.pacman.col);
        printf("Ghost: %d,%d ", game.ghost.row, game.ghost.col);
        printf("Food: %d,%d\n", game.food.row, game.food.col);

        if (game.pacman.alive) {
            game.pacman.direction = (game.pacman.direction + 1) % 4;
            game.pacman.row += (game.pacman.direction == 0)? 0 : 1;
            game.pacman.col += (game.pacman.direction == 1)? 0 : 1;
            game.pacman.row = game.pacman.row % MAX_ROWS;
            game.pacman.col = game.pacman.col % MAX_COLS;
            game.num_moves++;
        }

        if (game.ghost.alive) {
            game.ghost.direction = (game.ghost.direction + 1) % 4;
            game.ghost.row += (game.ghost.direction == 0)? 0 : 1;
            game.ghost.col += (game.ghost.direction == 1)? 0 : 1;
            game.ghost.row = game.ghost.row % MAX_ROWS;
            game.ghost.col = game.ghost.col % MAX_COLS;
            game.num_moves++;
        }

        if (game.pacman.row == game.food.row && game.pacman.col == game.food.col) {
            game.food.alive = 0;
            game.pacman.score++;
        }

        if (game.pacman.row == game.ghost.row && game.pacman.col == game.ghost.col) {
            game.ghost.alive = 0;
            game.pacman.score++;
        }

        if (game.ghost.row == game.food.row && game.ghost.col == game.food.col) {
            game.food.alive = 0;
            game.ghost.score++;
        }

        if (game.ghost.row == game.pacman.row && game.ghost.col == game.pacman.col) {
            game.pacman.alive = 0;
            game.ghost.score++;
        }

        if (game.pacman.alive && game.ghost.alive) {
            printf("Game over!\n");
            break;
        }

        sleep(1);
    }

    printf("Pacman score: %d\n", game.pacman.score);
    printf("Ghost score: %d\n", game.ghost.score);

    return 0;
}