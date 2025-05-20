#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Game {
    char *name;
    int max_players;
    int current_player;
    char **players;
} Game;

Game create_game(char *name, int max_players) {
    Game game;
    game.name = strdup(name);
    game.max_players = max_players;
    game.current_player = 0;
    game.players = malloc(max_players * sizeof(char *));
    return game;
}

void add_player(Game *game, char *player) {
    if (game->current_player >= game->max_players) {
        printf("Max number of players reached.\n");
        return;
    }
    game->players[game->current_player] = strdup(player);
    game->current_player++;
}

void list_players(Game *game) {
    for (int i = 0; i < game->current_player; i++) {
        printf("%s\n", game->players[i]);
    }
}

int main() {
    Game game = create_game("AdventureGame", 5);
    add_player(&game, "John");
    add_player(&game, "Sarah");
    add_player(&game, "Steve");
    add_player(&game, "Emily");

    list_players(&game);

    free(game.name);
    printf("Let's start the game with %s as the first player.\n", game.players[0]);
    printf("Player: %s\n", game.players[game.current_player]); // Null pointer dereference vulnerability

    return 0;
}
