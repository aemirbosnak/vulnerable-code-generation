#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

typedef struct Game {
    char name[100];
    int level;
    int* health;
    char* inventory[10];
} Game;

void equip(Game* player, char* item) {
    int index = player->level % 10;
    player->inventory[index] = item;
}

void unequip(Game* player, int index) {
    player->inventory[index] = NULL;
}

int main() {
    Game alice;
    strcpy(alice.name, "Alice");
    alice.level = 1;
    alice.health = &alice.level; // invalid pointer assignment

    equip(&alice, "Sword of Mystery");
    printf("%s has equipped the %s.\n", alice.name, alice.inventory[0]);

    unequip(&alice, 0);
    printf("%s has unequipped her weapon.\n", alice.name);

    printf("Alice's current level is: %d\n", *alice.health); // dereference invalid pointer

    return 0;
}
