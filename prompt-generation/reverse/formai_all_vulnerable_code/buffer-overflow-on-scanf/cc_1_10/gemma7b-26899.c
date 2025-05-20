//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOULS 5

typedef struct Ghost {
    char name[20];
    int room;
    int health;
    int action;
} Ghost;

Ghost ghosts[MAX_GHOULS] = {
    {"Jack", 1, 100, 0},
    {"Mary", 2, 80, 1},
    {"Bob", 3, 60, 2},
    {"Alice", 4, 40, 3},
    {"Tom", 5, 20, 4}
};

void moveGhost(Ghost *ghost) {
    switch (ghost->action) {
        case 0:
            ghost->room++;
            break;
        case 1:
            ghost->room--;
            break;
        case 2:
            ghost->room = (ghost->room + 1) % MAX_GHOULS;
            break;
        case 3:
            ghost->room = (ghost->room - 1) % MAX_GHOULS;
            break;
    }
}

void interactGhost(Ghost *ghost) {
    printf("You encounter %s in room %d.\n", ghost->name);
    printf("What do you want to do? (attack, defend, flee)\n");
    char input[20];
    scanf("%s", input);

    switch (input[0]) {
        case 'a':
            ghost->health--;
            printf("You attacked %s.\n", ghost->name);
            break;
        case 'd':
            printf("You defended against %s.\n", ghost->name);
            break;
        case 'f':
            ghost->room = MAX_GHOULS;
            printf("You fled from %s.\n", ghost->name);
            break;
    }

    if (ghost->health <= 0) {
        printf("%s has been defeated.\n", ghost->name);
    }
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < MAX_GHOULS; i++) {
        moveGhost(&ghosts[i]);
    }

    for (int i = 0; i < MAX_GHOULS; i++) {
        interactGhost(&ghosts[i]);
    }

    return 0;
}