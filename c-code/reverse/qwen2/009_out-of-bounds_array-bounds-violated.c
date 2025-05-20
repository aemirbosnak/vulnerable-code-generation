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

void move(Warrior *warrior) {
    warrior->x += rand() % 3 - 1;
    warrior->y += rand() % 3 - 1;
}

int attack(Warrior *attacker, Warrior *defender) {
    return rand() % 2; // Simplified attack logic
}

int main() {
    srand(time(NULL));

    Warrior warrior1 = {GRID_SIZE / 2, GRID_SIZE / 2};
    Warrior warrior2 = {GRID_SIZE / 2, GRID_SIZE / 2};

    while (1) {
        move(&warrior1);
        move(&warrior2);

        if (attack(&warrior1, &warrior2)) {
            printf("Warrior 1 attacks Warrior 2!\n");
        } else {
            printf("Warrior 2 attacks Warrior 1!\n");
        }

        // Simplified collision detection
        if (warrior1.x == warrior2.x && warrior1.y == warrior2.y) {
            printf("Collision! Battle ends.\n");
            break;
        }
    }

    return 0;
}
