#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Game {
    char *name;
    char *description;
    int num_players;
} Game;

Game *create_game(const char *name, const char *description, int num_players) {
    Game *new_game = (Game *)malloc(sizeof(Game));
    new_game->name = strdup(name);
    new_game->description = strdup(description);
    new_game->num_players = num_players;
    return new_game;
}

void free_game(Game *game) {
    free(game->name);
    free(game->description);
    free(game);
}

void play_game(Game *game) {
    printf("Game: %s\n", game->name);
    printf("Description: %s\n", game->description);
    printf("Number of players: %d\n", game->num_players);

    // Simulate gameplay for a while, then free the game to introduce the use-after-free vulnerability
    for (int i = 0; i < 10; i++) {
        printf("Turn %d\n", i + 1);
    }

    free(game);
}

int main() {
    Game *tetris = create_game("Tetris", "Classic block-building game", 1);
    play_game(tetris);

    Game *starcraft = create_game("Starcraft", "Real-time strategy game", 2);
    play_game(starcraft);

    return 0;
}
