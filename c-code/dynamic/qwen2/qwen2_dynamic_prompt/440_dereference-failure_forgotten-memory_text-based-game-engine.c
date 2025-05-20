#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int health;
    char *name;
} Player;

void attack(Player *p, int damage) {
    p->health -= damage;
}

int main() {
    Player player = {100, "Hero"};
    printf("Player %s starts with %d health.\n", player.name, player.health);

    // Simulate an attack
    attack(&player, 20);
    printf("Player %s now has %d health.\n", player.name, player.health);

    // Intentionally forget to free allocated memory
    // This is a deliberate mistake for demonstration purposes

    return 0;
}
