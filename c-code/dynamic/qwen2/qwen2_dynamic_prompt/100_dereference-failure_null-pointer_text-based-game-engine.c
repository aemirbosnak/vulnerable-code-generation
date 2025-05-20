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

void attack(Player *p, Player *e) {
    if (p == NULL || e == NULL) {
        printf("Error: Null pointer encountered.\n");
        return;
    }
    p->health -= 10;
    e->health -= 5;
}

int main() {
    Player player = {100, "Hero"};
    Player enemy = {80, "Goblin"};

    printf("%s attacks %s!\n", player.name, enemy.name);
    attack(&player, &enemy);

    printf("%s has %d health left.\n", player.name, player.health);
    printf("%s has %d health left.\n", enemy.name, enemy.health);

    // Intentionally set enemy pointer to null to cause dereference failure
    Player *nullEnemy = NULL;
    attack(&player, nullEnemy);

    return 0;
}
