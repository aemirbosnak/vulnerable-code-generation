//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOSTS 5

typedef struct Ghost {
    char name[20];
    int room_num;
    int health;
    int is_active;
} Ghost;

Ghost ghosts[MAX_GHOSTS] = {
    {"Mary", 1, 100, 1},
    {"Jack", 2, 80, 1},
    {"Anna", 3, 60, 1},
    {"Tom", 4, 40, 1},
    {"Alice", 5, 20, 1}
};

void move_ghost(Ghost *ghost) {
    int direction = rand() % 4;
    switch (direction) {
        case 0:
            ghost->room_num++;
            break;
        case 1:
            ghost->room_num--;
            break;
        case 2:
            ghost->room_num += 2;
            break;
        case 3:
            ghost->room_num -= 2;
            break;
    }
}

void interact_with_ghost(Ghost *ghost) {
    printf("You encounter %s in room %d.\n", ghost->name);
    printf("What do you want to do? (attack, flee, talk)\n");
    char input[20];
    scanf("%s", input);

    if (strcmp(input, "attack") == 0) {
        ghost->health--;
        printf("You attacked %s. They have %d health remaining.\n", ghost->name, ghost->health);
    } else if (strcmp(input, "flee") == 0) {
        printf("You fled from %s.\n", ghost->name);
    } else if (strcmp(input, "talk") == 0) {
        printf("You talked to %s. They said, '%s'.\n", ghost->name, ghost->name);
    } else {
        printf("Invalid input.\n");
    }
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < MAX_GHOSTS; i++) {
        move_ghost(&ghosts[i]);
    }

    for (int i = 0; i < MAX_GHOSTS; i++) {
        interact_with_ghost(&ghosts[i]);
    }

    return 0;
}