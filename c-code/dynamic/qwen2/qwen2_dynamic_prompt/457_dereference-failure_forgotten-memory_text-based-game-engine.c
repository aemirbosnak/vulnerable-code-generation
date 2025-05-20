#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int health;
    char *name;
} Player;

void setupPlayer(Player *player, const char *name, int health) {
    player->health = health;
    player->name = strdup(name);
}

void freePlayer(Player *player) {
    if (player->name != NULL) {
        free(player->name);
    }
}

int main() {
    Player *player = malloc(sizeof(Player));
    if (player == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    setupPlayer(player, "Hero", 100);

    printf("Welcome, %s! Your health is %d.\n", player->name, player->health);

    // Intentional dereference failure: forgetting to call freePlayer
    // This will lead to a memory leak

    // Simulate gameplay
    player->health -= 20;
    printf("After battle, your health is %d.\n", player->health);

    // No call to freePlayer here

    return 0;
}
