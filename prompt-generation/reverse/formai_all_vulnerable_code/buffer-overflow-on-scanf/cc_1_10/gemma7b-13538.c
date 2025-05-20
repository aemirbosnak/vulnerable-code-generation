//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GHOULS 5

typedef struct Ghost {
    char name[20];
    int room_num;
    int is_active;
} Ghost;

Ghost ghosts[MAX_GHOULS] = {
    {"Mr. Jones", 1, 1},
    {"Mrs. Smith", 2, 1},
    {"Mr. Brown", 3, 0},
    {"Ms. Johnson", 4, 1},
    {"Mr. Green", 5, 0}
};

void move_ghost(Ghost *ghost) {
    int new_room = rand() % MAX_GHOULS + 1;
    if (new_room != ghost->room_num) {
        ghost->room_num = new_room;
    }
}

void interact_with_ghost(Ghost *ghost) {
    printf("You encountered %s in room %d.\n", ghost->name);
    switch (rand() % 3) {
        case 0:
            printf("They asked you a question.\n");
            break;
        case 1:
            printf("They threatened you.\n");
            break;
        case 2:
            printf("They offered you a deal.\n");
            break;
    }
}

int main() {
    int i;
    for (i = 0; i < MAX_GHOULS; i++) {
        move_ghost(&ghosts[i]);
    }

    printf("Welcome to the haunted house.\n");
    printf("Please enter your name: ");
    char name[20];
    scanf("%s", name);

    for (i = 0; i < MAX_GHOULS; i++) {
        if (strcmp(ghosts[i].name, name) == 0) {
            interact_with_ghost(&ghosts[i]);
        }
    }

    printf("Thank you for visiting the haunted house.\n");

    return 0;
}