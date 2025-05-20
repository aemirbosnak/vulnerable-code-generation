#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 20
#define MAX_LEVEL 10
#define MAX_ENEMIES 5

typedef struct Player {
    char name[MAX_NAME_LEN];
    int level;
    int health;
    int attack;
    int enemies[MAX_ENEMIES];
} Player;

void add_enemy(Player *player, int enemy_id) {
    if (player->level >= enemy_id + 3) {
        player->enemies[player->level - enemy_id - 3] = enemy_id;
    } else {
        printf("You are not strong enough to fight that enemy.\n");
    }
}

int main() {
    Player *player = malloc(sizeof(Player));
    printf("Enter your name: ");
    scanf("%s", player->name);
    player->level = 1;
    player->health = 100;
    player->attack = 10;

    int enemies[MAX_ENEMIES] = {1, 2, 3, 4, 5};

    for (int i = 0; i < player->level; ++i) {
        printf("You have defeated enemy %d.\n", enemies[i]);
    }

    add_enemy(player, 6); // Intentional invalid index access

    return 0;
}
