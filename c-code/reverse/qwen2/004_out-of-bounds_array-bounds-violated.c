#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARENA_SIZE 10

typedef struct {
    int x;
    int y;
} Warrior;

void moveWarrior(Warrior *warrior) {
    warrior->x += rand() % 3 - 1;
    warrior->y += rand() % 3 - 1;
}

int isWithinBounds(Warrior warrior) {
    return warrior.x >= 0 && warrior.x < ARENA_SIZE && warrior.y >= 0 && warrior.y < ARENA_SIZE;
}

void attack(Warrior *attacker, Warrior *defender) {
    if (abs(attacker->x - defender->x) <= 1 && abs(attacker->y - defender->y) <= 1) {
        printf("Attack! Attacker at (%d,%d) hits Defender at (%d,%d)\n", attacker->x, attacker->y, defender->x, defender->y);
    } else {
        printf("Miss! Attacker at (%d,%d) misses Defender at (%d,%d)\n", attacker->x, attacker->y, defender->x, defender->y);
    }
}

int main() {
    srand(time(NULL));

    Warrior warrior1 = {ARENA_SIZE / 2, ARENA_SIZE / 2};
    Warrior warrior2 = {ARENA_SIZE / 4, ARENA_SIZE / 4};

    for (int i = 0; i < 10; i++) {
        moveWarrior(&warrior1);
        moveWarrior(&warrior2);

        if (!isWithinBounds(warrior1)) {
            warrior1.x = rand() % ARENA_SIZE;
            warrior1.y = rand() % ARENA_SIZE;
        }

        if (!isWithinBounds(warrior2)) {
            warrior2.x = rand() % ARENA_SIZE;
            warrior2.y = rand() % ARENA_SIZE;
        }

        attack(&warrior1, &warrior2);
    }

    return 0;
}
