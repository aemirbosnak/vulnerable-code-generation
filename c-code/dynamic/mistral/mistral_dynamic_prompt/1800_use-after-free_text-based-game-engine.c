#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Game {
    char *name;
    int health, max_health;
    char *equipment;
} Game;

Game *create_game(char *name, int health, char *equipment) {
    Game *game = (Game *) malloc(sizeof(Game));
    game->name = strdup(name);
    game->health = health;
    game->max_health = health;
    game->equipment = strdup(equipment);
    return game;
}

void destroy_game(Game *game) {
    free(game->name);
    free(game->equipment);
    free(game);
}

void attack(Game *target, Game *attacker, int damage) {
    target->health -= damage;
    printf("%s has been attacked by %s for %d points of damage. Current health: %d\n", target->name, attacker->name, damage, target->health);
}

int main() {
    Game *player = create_game("Player", 100, "Iron Sword");
    Game *enemy = create_game("Enemy", 200, "Dagger");

    while (player->health > 0 && enemy->health > 0) {
        attack(player, enemy, 10);

        if (enemy->health <= 0) {
            printf("You have defeated the enemy!\n");
            break;
        }

        attack(enemy, player, 5);
    }

    destroy_game(player);
    destroy_game(enemy);

    return 0;
}
