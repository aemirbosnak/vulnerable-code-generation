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

void loadPlayer(Player *player, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Failed to open file.\n");
        return;
    }

    // Simulate loading player data
    fscanf(file, "%s %d", player->name, &player->health);
    fclose(file);
}

int main() {
    Player player;
    memset(&player, 0, sizeof(player));

    printf("Enter player filename: ");
    char filename[256];
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';

    loadPlayer(&player, filename);

    printf("Player Name: %s\n", player.name);
    printf("Player Health: %d\n", player.health);

    // Out-of-bounds read vulnerability
    printf("Player Name Length: %lu\n", strlen(player.name));
    printf("Player Health: %d\n", player.health);

    return 0;
}
