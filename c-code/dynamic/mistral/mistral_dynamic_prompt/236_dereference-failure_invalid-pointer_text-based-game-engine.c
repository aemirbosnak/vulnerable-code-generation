#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct GameObject {
    char* name;
    int health;
    int attack;
} GameObject;

void game_loop(GameObject* player, GameObject* enemy) {
    while (player->health > 0 && enemy->health > 0) {
        enemy->health -= player->attack;
        player->health -= enemy->attack * 2;
    }

    if (player->health > 0) {
        printf("Player wins!\n");
    } else {
        printf("Game Over. Player loses.\n");
    }
}

int main() {
    GameObject player = {.name = "Player", .health = 100, .attack = 20};
    GameObject enemy = {.name = "Enemy", .health = 200, .attack = 10};

    GameObject* ptr_player = &player;
    GameObject* ptr_enemy = &enemy;

    game_loop(ptr_player->name, ptr_enemy->attack); // Dereference error intentionally

    return 0;
}
