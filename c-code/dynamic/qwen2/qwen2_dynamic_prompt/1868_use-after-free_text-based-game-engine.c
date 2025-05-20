#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *name;
} Player;

void createPlayer(Player *player) {
    player->name = (char *)malloc(20 * sizeof(char));
    sprintf(player->name, "Hero");
}

void destroyPlayer(Player *player) {
    free(player->name);
}

void renamePlayer(Player *player, const char *newName) {
    player->name = (char *)realloc(player->name, strlen(newName) + 1);
    strcpy(player->name, newName);
}

int main() {
    Player hero;
    createPlayer(&hero);

    printf("Player name: %s\n", hero.name);

    renamePlayer(&hero, "Villain");

    printf("Player name: %s\n", hero.name);

    destroyPlayer(&hero);

    // Use-after-free vulnerability
    printf("Player name: %s\n", hero.name); // Undefined behavior

    return 0;
}
