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

void loadPlayer(Player *player, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Failed to open file.\n");
        return;
    }

    fscanf(file, "%s %d", player->name, &player->health);
    fclose(file);

    // Out-of-bounds read vulnerability
    printf("Player Name: %s\n", player->name);
    printf("Player Health: %d\n", player->health);
}

int main() {
    Player player;
    loadPlayer(&player, "nonexistent_file.txt");

    return 0;
}
