#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 20

struct Player {
    char name[MAX_NAME_LENGTH];
    int health;
    int inventory[10];
};

void print_inventory(struct Player *player, int index) {
    printf("Item %d: %d\n", index, player->inventory[index]);
}

int main() {
    struct Player player;
    strcpy(player.name, "Hero");
    player.health = 100;
    memset(player.inventory, 0, sizeof(player.inventory));

    // Intentionally accessing an out-of-bounds index to demonstrate vulnerability
    print_inventory(&player, 10);

    return 0;
}
