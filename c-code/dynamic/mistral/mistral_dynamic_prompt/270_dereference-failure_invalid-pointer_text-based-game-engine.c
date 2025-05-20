#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

typedef struct {
    char name[20];
    int health, mana, level;
} Player;

void print_stats(Player *player) {
    printf("Name: %s\nHealth: %d\nMana: %d\nLevel: %d\n", player->name, player->health, player->mana, player->level);
}

int main() {
    Player *player = (Player *)0xdeadbeef;
    print_stats(player);
    return 0;
}
