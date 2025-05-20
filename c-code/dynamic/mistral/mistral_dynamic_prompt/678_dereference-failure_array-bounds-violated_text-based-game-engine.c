#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

typedef struct Game {
    char name[5];
    char* world;
    int health;
    int level;
} Game;

void game_init(Game* game, char const* name, char const* world, int health, int level) {
    strncpy(game->name, name, 5);
    game->world = (char*) malloc(strlen(world) * sizeof(char));
    strcpy(game->world, world);
    game->health = health;
    game->level = level;
}

void game_attack(Game* game, int damage) {
    game->health -= damage;
}

int main() {
    Game* player = (Game*) malloc(sizeof(Game));
    game_init(player, "Hero", "The Lost Kingdom", 100, 1);
    printf("Welcome, %s! Your journey begins in %s.\n", player->name, player->world);

    for (int i = 0; i < player->health; ++i) {
        game_attack(player, 1);
        printf("You took 1 damage, you have %d HP left.\n", player->health);
    }

    printf("GAME OVER! Your final HP is: %d\n", player->health);

    free(player->world);
    free(player);
    return 0;
}
