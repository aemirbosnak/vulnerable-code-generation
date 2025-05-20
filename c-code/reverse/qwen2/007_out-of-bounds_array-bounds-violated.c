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

int main() {
    srand(time(NULL));

    Warrior warrior1 = {GRID_SIZE / 2, GRID_SIZE / 2};
    Warrior warrior2 = {GRID_SIZE / 2, GRID_SIZE / 2};

    while (1) {
        moveWarrior(&warrior1);
        moveWarrior(&warrior2);

        printf("Warrior 1 at (%d, %d)\n", warrior1.x, warrior1.y);
        printf("Warrior 2 at (%d, %d)\n", warrior2.x, warrior2.y);

        if (warrior1.x == warrior2.x && warrior1.y == warrior2.y) {
            printf("Battle! Both warriors attack each other!\n");
            // Simulate attack logic here
        }

        printf("\nPress Enter to continue...");
        getchar();
    }

    return 0;
}
