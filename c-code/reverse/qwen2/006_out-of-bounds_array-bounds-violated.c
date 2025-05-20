#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BATTLEFIELD_SIZE 10

typedef struct {
    int x;
    int y;
} Warrior;

void moveWarrior(Warrior *warrior) {
    warrior->x += rand() % 3 - 1;
    warrior->y += rand() % 3 - 1;
}

int isOutOfBounds(Warrior warrior) {
    return warrior.x < 0 || warrior.x >= BATTLEFIELD_SIZE || warrior.y < 0 || warrior.y >= BATTLEFIELD_SIZE;
}

void attack(Warrior *attacker, Warrior *defender) {
    if (isOutOfBounds(*attacker)) {
        printf("Attacker out of bounds!\n");
    } else if (isOutOfBounds(*defender)) {
        printf("Defender out of bounds!\n");
    } else {
        printf("Attack successful!\n");
    }
}

int main() {
    srand(time(NULL));

    Warrior warrior1 = {BATTLEFIELD_SIZE / 2, BATTLEFIELD_SIZE / 2};
    Warrior warrior2 = {BATTLEFIELD_SIZE / 2, BATTLEFIELD_SIZE / 2};

    for (int i = 0; i < 100; i++) {
        moveWarrior(&warrior1);
        moveWarrior(&warrior2);

        attack(&warrior1, &warrior2);
    }

    return 0;
}
