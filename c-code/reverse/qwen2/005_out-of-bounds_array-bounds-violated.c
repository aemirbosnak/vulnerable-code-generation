#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 10

typedef struct {
    int x;
    int y;
} Warrior;

void moveWarrior(Warrior *warrior) {
    warrior->x += rand() % 3 - 1;
    warrior->y += rand() % 3 - 1;
}

int isOutOfBounds(Warrior warrior) {
    return warrior.x < 0 || warrior.x >= GRID_SIZE || warrior.y < 0 || warrior.y >= GRID_SIZE;
}

int main() {
    srand(time(NULL));
    Warrior warrior1 = {GRID_SIZE / 2, GRID_SIZE / 2};
    Warrior warrior2 = {GRID_SIZE / 2, GRID_SIZE / 2};

    while (1) {
        moveWarrior(&warrior1);
        moveWarrior(&warrior2);

        if (isOutOfBounds(warrior1)) {
            printf("Warrior 1 out of bounds!\n");
            break;
        }
        if (isOutOfBounds(warrior2)) {
            printf("Warrior 2 out of bounds!\n");
            break;
        }

        // Simulate attack
        if (warrior1.x == warrior2.x && warrior1.y == warrior2.y) {
            printf("Attack! Both warriors collide!\n");
            break;
        }
    }

    return 0;
}
