#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[30];
    int health;
    int level;
} Character;

Character* create_character(char* name) {
    Character* new_char = (Character*) malloc(sizeof(Character));
    strcpy(new_char->name, name);
    new_char->health = 100;
    new_char->level = 1;
    return new_char;
}

void attack(Character* attacker, Character* victim) {
    if (attacker->health <= 0 || victim->health <= 0) return;
    victim->health -= attacker->health;
}

int main() {
    Character* hero = create_character("Hero");
    Character* villain = create_character("Villain");

    while (hero->health > 0 && villain->health > 0) {
        attack(hero, villain);
        printf("Hero attacks Villain, leaving him with %d health.\n", villain->health);

        // Invalid pointer dereference intentionally introduced here.
        int damage = hero->health;
        attack(villain, (Character*) damage);

        printf("Villain attacks Hero, leaving him with %d health.\n", hero->health);

        // Wait for a while before the next attack.
        sleep(1);
    }

    if (hero->health <= 0) {
        printf("Hero has been defeated by the Villain.\n");
    } else {
        printf("Hero has emerged victorious over the Villain!\n");
    }

    free(hero);
    free(villain);

    return 0;
}
