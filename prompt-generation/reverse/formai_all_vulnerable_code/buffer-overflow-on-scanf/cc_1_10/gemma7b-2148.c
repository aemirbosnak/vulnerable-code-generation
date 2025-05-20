//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: Linus Torvalds
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define MAX_GHOSTS 5

typedef struct Ghost {
    char name[20];
    int room_num;
    int active;
} Ghost;

Ghost ghosts[MAX_GHOSTS];

void initializeGhosts() {
    for (int i = 0; i < MAX_GHOSTS; i++) {
        ghosts[i].name[0] = '\0';
        ghosts[i].room_num = -1;
        ghosts[i].active = 0;
    }
}

void spawnGhost() {
    int room_num = rand() % 5;
    char name[20];
    printf("Enter the name of the ghost: ");
    scanf("%s", name);
    Ghost new_ghost;
    strcpy(new_ghost.name, name);
    new_ghost.room_num = room_num;
    new_ghost.active = 1;
    ghosts[MAX_GHOSTS - 1] = new_ghost;
}

void hauntHouse() {
    for (int i = 0; i < MAX_GHOSTS; i++) {
        if (ghosts[i].active) {
            printf("The ghost of %s haunts room %d.\n", ghosts[i].name, ghosts[i].room_num);
        }
    }
}

int main() {
    initializeGhosts();
    spawnGhost();
    hauntHouse();

    return 0;
}