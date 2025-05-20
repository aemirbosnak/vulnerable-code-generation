//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOULS 10

typedef struct Ghost {
    char name[20];
    int room_number;
    int health;
    int action_taken;
} Ghost;

Ghost ghosts[MAX_GHOULS];

void initializeGhosts() {
    for (int i = 0; i < MAX_GHOULS; i++) {
        ghosts[i].name[0] = '\0';
        ghosts[i].room_number = 0;
        ghosts[i].health = 100;
        ghosts[i].action_taken = 0;
    }
}

void scareGhost(Ghost *ghost) {
    ghost->action_taken = 1;
    printf("The ghostly figure of %s has been scared away!\n", ghost->name);
    ghost->health -= 10;
    if (ghost->health <= 0) {
        printf("The ghostly figure of %s has been defeated!\n", ghost->name);
        initializeGhosts();
    }
}

int main() {
    initializeGhosts();

    srand(time(NULL));

    for (int i = 0; i < MAX_GHOULS; i++) {
        ghosts[i].name[0] = 'A' + i;
        ghosts[i].room_number = rand() % 5 + 1;
    }

    for (int i = 0; i < MAX_GHOULS; i++) {
        printf("The ghostly figure of %s is lurking in room %d.\n", ghosts[i].name, ghosts[i].room_number);
    }

    printf("Enter the room number of the ghostly figure you want to scare:");
    int room_number;
    scanf("%d", &room_number);

    for (int i = 0; i < MAX_GHOULS; i++) {
        if (ghosts[i].room_number == room_number) {
            scareGhost(&ghosts[i]);
        }
    }

    return 0;
}