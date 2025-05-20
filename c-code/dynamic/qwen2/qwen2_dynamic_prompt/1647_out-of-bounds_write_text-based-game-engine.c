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

void updatePlayer(Player *player, const char *newName, int newHealth) {
    strncpy(player->name, newName, MAX_NAME_LENGTH);
    player->health = newHealth;
}

int main() {
    Player player;
    printf("Enter your character's name: ");
    fgets(player.name, sizeof(player.name), stdin);

    // Remove newline character if present
    size_t len = strlen(player.name);
    if (len > 0 && player.name[len - 1] == '\n') {
        player.name[len - 1] = '\0';
    }

    printf("Enter your character's health: ");
    scanf("%d", &player.health);

    // Simulate an out-of-bounds write vulnerability
    char buffer[10];
    strcpy(buffer, "Overwritten");

    printf("Player Name: %s\n", player.name);
    printf("Player Health: %d\n", player.health);
    printf("Buffer Content: %s\n", buffer);

    return 0;
}
