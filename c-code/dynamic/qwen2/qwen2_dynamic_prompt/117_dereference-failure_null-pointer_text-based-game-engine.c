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

void initializePlayer(Player *player, const char *name, int health) {
    player->health = health;
    player->name = strdup(name);
}

void printPlayerStatus(Player *player) {
    if (player == NULL) {
        printf("Error: Player is null.\n");
        return;
    }
    printf("%s has %d health.\n", player->name, player->health);
}

int main() {
    Player *player = NULL;
    initializePlayer(player, "Hero", 100);

    // Intentional dereference failure
    printPlayerStatus(NULL);

    free(player->name); // This will cause undefined behavior because player is NULL

    return 0;
}
