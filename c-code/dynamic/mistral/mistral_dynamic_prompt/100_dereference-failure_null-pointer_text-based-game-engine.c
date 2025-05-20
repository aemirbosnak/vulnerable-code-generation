#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    int health;
    int attack;
} Character;

void take_damage(Character* character, int damage) {
    character->health -= damage;
}

void attack_enemy(Character* attacker, Character* defender, int attack_power) {
    take_damage(defender, attack_power + attacker->attack);
}

int main() {
    Character* player = malloc(sizeof(Character));
    player->name = "Player";
    player->health = 100;
    player->attack = 20;

    Character* enemy = malloc(sizeof(Character));
    enemy->name = "Enemy";
    enemy->health = 100;
    enemy->attack = 10;

    while (player->health > 0 && enemy->health > 0) {
        attack_enemy(player, enemy, player->attack);
        printf("Player attacks enemy for %d damage, enemy health: %d\n", player->attack, enemy->health);

        attack_enemy(enemy, player, enemy->attack);
        printf("Enemy attacks player for %d damage, player health: %d\n", enemy->attack, player->health);
    }

    if (player->health <= 0) {
        printf("Game Over. Player has lost.\n");
    } else {
        printf("Victory! Player has defeated the enemy.\n");
    }

    free(player);
    free(enemy);
    return 0;
}
