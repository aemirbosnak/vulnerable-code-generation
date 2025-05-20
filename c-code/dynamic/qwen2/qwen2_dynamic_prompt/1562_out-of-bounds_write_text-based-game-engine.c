#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 10

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
    char input[20];
    fgets(input, sizeof(input), stdin);

    // Remove newline character if present
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    // Update player name without bounds checking
    updatePlayerName(&player, input);

    printf("Your new name is %s\n", player.name);
    printf("Health: %d\n", player.health);

    return 0;
}
