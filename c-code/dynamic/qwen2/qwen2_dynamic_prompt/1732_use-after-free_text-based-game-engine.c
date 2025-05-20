#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 256

typedef struct {
    char name[MAX_NAME_LENGTH];
    int health;
} Player;

Player* create_player(const char* name, int health) {
    Player* player = (Player*)malloc(sizeof(Player));
    if (player == NULL) {
        return NULL;
    }
    strncpy(player->name, name, MAX_NAME_LENGTH - 1);
    player->health = health;
    return player;
}

void destroy_player(Player* player) {
    free(player);
}

void print_player(Player* player) {
    printf("Name: %s\nHealth: %d\n", player->name, player->health);
}

int main() {
    Player* player = create_player("Hero", 100);
    if (player != NULL) {
        print_player(player);
        destroy_player(player);
        // Use-after-free vulnerability
        print_player(player); // Accessing freed memory
    } else {
        printf("Failed to create player.\n");
    }
    return 0;
}
