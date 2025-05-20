//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: curious
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_GHOULS 5
#define GHOUL_SPEED 10

typedef struct Ghost {
    char name[20];
    int x, y;
    int direction;
    time_t last_move_time;
} Ghost;

Ghost ghosts[MAX_GHOULS];

void initializeGhosts() {
    for (int i = 0; i < MAX_GHOULS; i++) {
        ghosts[i].name[0] = '\0';
        ghosts[i].x = -1;
        ghosts[i].y = -1;
        ghosts[i].direction = 0;
        ghosts[i].last_move_time = time(NULL);
    }
}

void moveGhosts() {
    for (int i = 0; i < MAX_GHOULS; i++) {
        if (time(NULL) - ghosts[i].last_move_time >= GHOUL_SPEED) {
            ghosts[i].direction = rand() % 4;
            ghosts[i].last_move_time = time(NULL);
            switch (ghosts[i].direction) {
                case 0:
                    ghosts[i].x--;
                    break;
                case 1:
                    ghosts[i].x++;
                    break;
                case 2:
                    ghosts[i].y--;
                    break;
                case 3:
                    ghosts[i].y++;
                    break;
            }
        }
    }
}

void printGhosts() {
    for (int i = 0; i < MAX_GHOULS; i++) {
        printf("%s is at (%d, %d)\n", ghosts[i].name, ghosts[i].x, ghosts[i].y);
    }
}

int main() {
    initializeGhosts();
    moveGhosts();
    printGhosts();

    return 0;
}