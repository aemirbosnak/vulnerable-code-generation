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
    int attackPower;
} Player;

void loadPlayer(Player *player, const char *name, int health, int attackPower) {
    strncpy(player->name, name, MAX_NAME_LENGTH - 1);
    player->health = health;
    player->attackPower = attackPower;
}

int main() {
    Player player;
    loadPlayer(&player, "Hero", 100, 20);

    printf("Welcome, %s! Your health is %d and your attack power is %d.\n",
           player.name, player.health, player.attackPower);

    // Simulate an out-of-bounds read
    char buffer[10];
    strcpy(buffer, player.name);
    buffer[9] = 'X'; // This should overwrite adjacent memory

    printf("Buffer content: %s\n", buffer);

    return 0;
}
