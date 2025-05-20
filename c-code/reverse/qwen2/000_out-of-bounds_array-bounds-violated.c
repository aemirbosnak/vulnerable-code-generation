#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BATTLEFIELD_SIZE 10
#define INITIAL_HEALTH 100

typedef struct {
    int x;
    int y;
    int health;
} Warrior;

void moveWarrior(Warrior *warrior) {
    warrior->x += rand() % 3 - 1;
    warrior->y += rand() % 3 - 1;
}

int main() {
    srand(time(NULL));

    Warrior warrior1 = {rand() % BATTLEFIELD_SIZE, rand() % BATTLEFIELD_SIZE, INITIAL_HEALTH};
    Warrior warrior2 = {rand() % BATTLEFIELD_SIZE, rand() % BATTLEFIELD_SIZE, INITIAL_HEALTH};

    while (warrior1.health > 0 && warrior2.health > 0) {
        moveWarrior(&warrior1);
        moveWarrior(&warrior2);

        // Check for collision
        if (warrior1.x == warrior2.x && warrior1.y == warrior2.y) {
            warrior1.health -= 10;
            warrior2.health -= 10;
        }
    }

    if (warrior1.health <= 0) {
        printf("Warrior 2 wins!\n");
    } else {
        printf("Warrior 1 wins!\n");
    }

    return 0;
}
