#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 16

typedef struct {
    char name[MAX_NAME_LENGTH];
    int health;
} Player;

void printPlayer(Player *player) {
    printf("Name: %s\n", player->name);
    printf("Health: %d\n", player->health);
}

int main() {
    Player player;
    strcpy(player.name, "Hero");
    player.health = 100;

    printPlayer(&player);

    // Out-of-bounds write vulnerability
    char buffer[8];
    strcpy(buffer, "Exploit");

    // This will overwrite adjacent memory
    player.health = *(int *)(buffer + 4);

    printPlayer(&player);

    return 0;
}
