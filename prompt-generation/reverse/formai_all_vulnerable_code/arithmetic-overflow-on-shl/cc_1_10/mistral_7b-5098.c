//MISTRAL-7B DATASET v1.0 Category: Memory Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 4
#define HEIGHT 4
#define BIT_MASK 0x1

typedef unsigned int cell_t;
typedef struct {
    cell_t grid[WIDTH][HEIGHT];
    int moves;
} game_t;

void init_game(game_t *game) {
    int i, j;

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            game->grid[j][i] = (rand() % 2) << (2 * i);
        }
    }

    game->moves = 0;
}

void print_game(const game_t *game) {
    int i, j;

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("%s ", i == j && (game->grid[j][i] & BIT_MASK) ? "  X  " : "   _  ");
        }
        printf("\n");
    }
}

int check_match(const game_t *game, int x1, int y1, int x2, int y2) {
    if (x1 == x2 && y1 == y2) {
        return game->grid[x1][y1] == game->grid[x2][y2];
    }

    return 0;
}

void make_move(game_t *game, int x1, int y1, int x2, int y2) {
    if (check_match(game, x1, y1, x2, y2)) {
        game->grid[x1][y1] ^= BIT_MASK << (2 * (y1 + (x1 < x2 ? x2 - x1 : x1 - x2)));
        game->grid[x2][y2] ^= BIT_MASK << (2 * (y2 + (x2 < x1 ? x1 - x2 : x2 - x1)));
        game->moves++;
    }
}

int game_over(const game_t *game) {
    int i, j;

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (!(game->grid[j][i] & BIT_MASK)) {
                return 0;
            }
        }
    }

    return 1;
}

void play_game(game_t *game) {
    int x1, y1, x2, y2;

    while (!game_over(game)) {
        print_game(game);

        printf("Enter the first cell coordinates (x y): ");
        scanf("%d%d", &x1, &y1);

        printf("Enter the second cell coordinates (x y): ");
        scanf("%d%d", &x2, &y2);

        make_move(game, x1, y1, x2, y2);
    }

    printf("Congratulations, you won!\n");
}

int main() {
    srand(time(NULL));
    game_t game;

    init_game(&game);
    play_game(&game);

    return 0;
}