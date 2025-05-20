//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX_GOATS 5

typedef struct Goat {
    char name[20];
    int health;
    int strength;
} Goat;

Goat goats[MAX_GOATS];

void initializeGoats() {
    for (int i = 0; i < MAX_GOATS; i++) {
        goats[i].health = 100;
        goats[i].strength = rand() % 10 + 1;
        goats[i].name[0] = 'a' + i;
    }
}

void battle(Goat* goat1, Goat* goat2) {
    printf("The battle between %s and %s begins!\n", goat1->name, goat2->name);

    while (goat1->health > 0 && goat2->health > 0) {
        int damage = goat1->strength * rand() % 5 + 1;
        goat2->health -= damage;

        printf("%s attacks %s for %d damage.\n", goat1->name, goat2->name, damage);

        damage = goat2->strength * rand() % 5 + 1;
        goat1->health -= damage;

        printf("%s attacks %s for %d damage.\n", goat2->name, goat1->name, damage);
    }

    if (goat1->health <= 0) {
        printf("%s has been defeated!\n", goat1->name);
    } else if (goat2->health <= 0) {
        printf("%s has been defeated!\n", goat2->name);
    } else {
        printf("It's a draw!\n");
    }
}

int main() {
    initializeGoats();

    battle(&goats[0], &goats[1]);

    return 0;
}