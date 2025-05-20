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
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    strncpy(player->name, name, MAX_NAME_LENGTH - 1);
    player->health = health;
    return player;
}

void destroy_player(Player* player) {
    free(player);
}

void print_player(Player* player) {
    printf("Player: %s, Health: %d\n", player->name, player->health);
}

int main() {
    Player* player = create_player("Hero", 100);
    print_player(player);

    // Simulate some actions
    player->health -= 20;
    print_player(player);

    // Free the player
    destroy_player(player);

    // Use-after-free vulnerability
    print_player(player); // This line will cause undefined behavior

    return 0;
}
