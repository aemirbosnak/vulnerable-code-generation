//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: retro
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_GHOSTS 5

typedef struct Ghost {
    char name[20];
    int room;
    int health;
    int isAlive;
} Ghost;

Ghost ghosts[MAX_GHOSTS] = {
    {"Mr. Bartholomew", 1, 100, 1},
    {"Miss Abigail", 2, 80, 1},
    {"Mr. Edgar", 3, 60, 1},
    {"Mrs. Henderson", 4, 40, 1},
    {"The Bloody Mary", 5, 20, 1}
};

void moveGhost(Ghost *ghost) {
    switch (rand() % 4) {
        case 0:
            ghost->room++;
            break;
        case 1:
            ghost->room--;
            break;
        case 2:
            ghost->room += 2;
            break;
        case 3:
            ghost->room -= 2;
            break;
    }
}

void checkGhostHealth(Ghost *ghost) {
    if (ghost->health <= 0) {
        ghost->isAlive = 0;
    }
}

void playHauntedHouse(void) {
    int playerRoom = 1;
    int isAlive = 1;

    while (isAlive) {
        printf("You are in room %d.\n", playerRoom);

        for (int i = 0; i < MAX_GHOSTS; i++) {
            if (ghosts[i].isAlive && ghosts[i].room == playerRoom) {
                printf("A ghost named %s is in the same room as you!\n", ghosts[i].name);
            }
        }

        printf("What do you want to do? (move, check health, exit)\n");
        char input[20];
        scanf("%s", input);

        if (strcmp(input, "move") == 0) {
            moveGhost(&ghosts[0]);
            checkGhostHealth(&ghosts[0]);
        } else if (strcmp(input, "check health") == 0) {
            checkGhostHealth(&ghosts[0]);
        } else if (strcmp(input, "exit") == 0) {
            isAlive = 0;
        } else {
            printf("Invalid input.\n");
        }

        playerRoom = ghosts[0].room;
    }

    printf("You have exited the haunted house.\n");
}

int main() {
    srand(time(NULL));
    playHauntedHouse();

    return 0;
}