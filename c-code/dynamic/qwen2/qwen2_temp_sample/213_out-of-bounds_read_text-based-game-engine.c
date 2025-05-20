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
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return;
    }

    // Deliberate out-of-bounds read vulnerability here
    fgets(player->name, sizeof(player->name), file);

    fscanf(file, "%d", &player->health);
    fclose(file);
}

int main() {
    Player player;
    loadPlayer(&player, "player.txt");

    printf("Player Name: %s\n", player.name);
    printf("Player Health: %d\n", player.health);

    return 0;
}
