#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[10];
    int health, level;
} Player;

void attack(Player* player, Player* enemy) {
    int damage = 10;
    enemy->health -= damage;
    printf("Player %s attacks enemy %s for %d damage!\n", player->name, enemy->name, damage);

    // Null pointer vulnerability: Dereferencing an uninitialized pointer 'new_enemy'
    if (enemy->health <= 0) {
        printf("%s has defeated %s!\n", player->name, enemy->name);
        free(enemy);

        // Create new enemy
        Player* new_enemy = malloc(sizeof(Player));
        strcpy(new_enemy->name, "Giant Spider");
        new_enemy->health = 50;
        new_enemy->level = 3;
    }
}

int main() {
    Player player = {"John", 100, 1};
    Player* enemy = malloc(sizeof(Player));
    strcpy(enemy->name, "Goblin");
    enemy->health = 20;
    enemy->level = 1;

    while (player.health > 0 && enemy->health > 0) {
        attack(&player, enemy);
        if (enemy->health <= 0) {
            free(enemy);
            enemy = NULL;
        } else {
            attack(enemy, &player);
        }
    }

    if (enemy != NULL)
        free(enemy);

    return 0;
}
