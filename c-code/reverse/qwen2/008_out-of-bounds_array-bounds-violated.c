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

int main() {
    srand(time(NULL));

    Warrior warrior1 = {BATTLEFIELD_SIZE / 2, BATTLEFIELD_SIZE / 2};
    Warrior warrior2 = {BATTLEFIELD_SIZE / 2, BATTLEFIELD_SIZE / 2};

    for (int i = 0; i < 100; i++) {
        moveWarrior(&warrior1);
        moveWarrior(&warrior2);

        if (warrior1.x >= 0 && warrior1.x < BATTLEFIELD_SIZE && warrior1.y >= 0 && warrior1.y < BATTLEFIELD_SIZE &&
            warrior2.x >= 0 && warrior2.x < BATTLEFIELD_SIZE && warrior2.y >= 0 && warrior2.y < BATTLEFIELD_SIZE) {
            printf("Warriors clash at (%d, %d)\n", warrior1.x, warrior1.y);
        }
    }

    return 0;
}
