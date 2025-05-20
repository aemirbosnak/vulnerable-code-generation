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
    int level;
} Player;

void loadPlayer(Player *player, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Failed to open file.\n");
        return;
    }

    fscanf(file, "%s %d %d", player->name, &player->health, &player->level);
    fclose(file);

    // Intentional out-of-bounds read vulnerability
    char buffer[100];
    fread(buffer, sizeof(char), 100, file);
}

int main() {
    Player player;
    loadPlayer(&player, "player.dat");

    printf("Name: %s\nHealth: %d\nLevel: %d\n", player.name, player.health, player.level);

    return 0;
}
