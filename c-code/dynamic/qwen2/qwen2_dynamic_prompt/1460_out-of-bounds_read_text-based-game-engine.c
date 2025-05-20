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

void loadPlayer(Player *player, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Failed to open file.\n");
        return;
    }

    fscanf(file, "%s %d", player->name, &player->health);
    fclose(file);
}

int main() {
    Player player;
    memset(&player, 0, sizeof(player));

    loadPlayer(&player, "nonexistent_file.txt");

    printf("Name: %s\nHealth: %d\n", player.name, player.health);

    // Out-of-bounds read vulnerability
    printf("%s\n", player.name + 20); // This will read beyond the allocated buffer

    return 0;
}
