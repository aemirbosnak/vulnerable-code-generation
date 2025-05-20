//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOSTS 5

typedef struct Ghost {
    char name[20];
    int room_num;
    int spirit_level;
    int active;
} Ghost;

Ghost ghosts[MAX_GHOSTS];

void initializeGhosts() {
    for (int i = 0; i < MAX_GHOSTS; i++) {
        ghosts[i].active = 0;
    }
}

void activateGhost(int ghost_num) {
    ghosts[ghost_num].active = 1;
}

void simulateHauntedHouse() {
    int i, j, k;
    time_t t;

    initializeGhosts();

    for (k = 0; k < MAX_GHOSTS; k++) {
        ghosts[k].spirit_level = rand() % 3;
    }

    t = time(NULL);
    for (i = 0; i < 10; i++) {
        for (j = 0; j < MAX_GHOSTS; j++) {
            if (ghosts[j].active) {
                switch (ghosts[j].spirit_level) {
                    case 0:
                        printf("Ghost %s is whispering secrets...\n", ghosts[j].name);
                        break;
                    case 1:
                        printf("Ghost %s is moving slowly...\n", ghosts[j].name);
                        break;
                    case 2:
                        printf("Ghost %s is raging...\n", ghosts[j].name);
                        break;
                }
            }
        }
        sleep(rand() % 2);
    }

    time_t end_time = time(NULL) - t;
    printf("Total time spent in the haunted house: %d seconds\n", end_time);
}

int main() {
    simulateHauntedHouse();
    return 0;
}