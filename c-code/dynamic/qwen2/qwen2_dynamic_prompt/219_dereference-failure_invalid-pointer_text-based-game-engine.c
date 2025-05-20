#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int health;
    char name[20];
} Player;

void initializePlayer(Player *player, int health, const char *name) {
    player->health = health;
    strcpy(player->name, name);
}

void printPlayerStatus(Player *player) {
    if (player != NULL) {
        printf("Player: %s, Health: %d\n", player->name, player->health);
    } else {
        printf("Error: Invalid player pointer.\n");
    }
}

int main() {
    Player *player = NULL;
    initializePlayer(player, 100, "Hero");

    // Intentional dereference failure
    printf("Initial player status:\n");
    printPlayerStatus(player);

    // Simulate an invalid pointer usage
    player = (Player *)malloc(sizeof(Player));
    if (player == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return EXIT_FAILURE;
    }

    initializePlayer(player, 150, "Villain");
    printf("Updated player status:\n");
    printPlayerStatus(player);

    free(player);

    // Attempt to use a freed pointer
    printf("Attempting to access freed memory:\n");
    printPlayerStatus(player); // Dereference failure

    return EXIT_SUCCESS;
}
