#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int health;
    char name[20];
} Player;

void initializePlayer(Player *player, const char *name, int health) {
    player->health = health;
    strcpy(player->name, name);
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
    initializePlayer(player, "Hero", 100); // Dereference failure here

    printPlayerStatus(player);

    free(player); // Attempt to free a null pointer

    return 0;
}
