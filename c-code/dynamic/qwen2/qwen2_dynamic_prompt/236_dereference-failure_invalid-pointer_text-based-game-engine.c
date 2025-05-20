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

void attack(Player *p, int damage) {
    p->health -= damage;
}

int main() {
    Player player1 = {"Hero", 100};
    Player *player2 = NULL;

    printf("Player 1: %s, Health: %d\n", player1.name, player1.health);

    // Dereferencing a null pointer
    attack(player2, 10); // This will cause a segmentation fault

    return 0;
}
