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

void loadPlayer(Player *player) {
    char input[256];
    printf("Enter player name: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    sscanf(input, "%s", player->name); // Vulnerable to buffer overflow
}

int main() {
    Player player;
    player.health = 100;

    printf("Welcome to the Game Engine!\n");
    loadPlayer(&player);

    printf("Hello, %s! Your health is %d.\n", player.name, player.health);

    return 0;
}
