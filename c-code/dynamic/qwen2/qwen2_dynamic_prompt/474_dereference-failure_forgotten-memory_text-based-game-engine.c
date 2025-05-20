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

    // Simulate a game loop
    while (player->health > 0) {
        printf("Player %s has %d health\n", player->name, player->health);
        // Intentionally dereference an invalid pointer to cause a crash
        printf("%s's weapon attack: %d\n", player->name, *(player->name + 100));
        player->health -= 10;
    }

    freePlayer(player);
    free(player); // Double free to simulate forgotten memory

    return 0;
}
