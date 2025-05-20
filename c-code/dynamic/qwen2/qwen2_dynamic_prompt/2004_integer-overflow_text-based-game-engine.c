#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_LEVELS 100

typedef struct {
    int level;
    int score;
} Player;

void updateScore(Player *player, int points) {
    player->score += points;
}

int main() {
    Player player = {1, 0};
    int levels[MAX_LEVELS];

    // Initialize levels with some values
    for (int i = 0; i < MAX_LEVELS; i++) {
        levels[i] = i + 1;
    }

    // Simulate playing levels
    for (int i = 0; i < MAX_LEVELS; i++) {
        if (i == 99) {
            // Intentionally cause an integer overflow by adding a large number to the score
            updateScore(&player, 2147483647); // This will wrap around due to overflow
        }
        printf("Level %d: Score %d\n", levels[i], player.score);
    }

    return 0;
}
