#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int health;
} Player;

void updatePlayerName(Player *player, const char *newName) {
    strcpy(player->name, newName);
}

int main() {
    Player player;
    player.health = 100;

    printf("Welcome to the Game Engine!\n");
    printf("Enter your character's name: ");
    char input[30];
    fgets(input, sizeof(input), stdin);

    // Vulnerability: Writing beyond the allocated buffer
    updatePlayerName(&player, input);

    printf("Your character %s has been created with %d health.\n", player.name, player.health);

    return 0;
}
