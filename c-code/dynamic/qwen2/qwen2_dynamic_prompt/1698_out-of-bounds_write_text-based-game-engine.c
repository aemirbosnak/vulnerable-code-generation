#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

#define MAX_LEVELS 10

typedef struct {
    int health;
    int mana;
} Player;

void loadLevel(Player *player, int level) {
    if (level >= 0 && level < MAX_LEVELS) {
        player->health = 100 + level * 10;
        player->mana = 50 + level * 5;
    } else {
        printf("Invalid level: %d\n", level);
    }
}

int main() {
    Player player;
    int currentLevel = 15;

    loadLevel(&player, currentLevel);

    return 0;
}
