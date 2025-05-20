//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOULS 5

typedef struct Ghost {
    char name[20];
    int haunt_level;
    float location_x;
    float location_y;
    int active;
} Ghost;

Ghost ghosts[MAX_GHOULS];

void initializeGhosts() {
    for (int i = 0; i < MAX_GHOULS; i++) {
        ghosts[i].active = 0;
    }
}

void spawnGhost() {
    int random_index = rand() % MAX_GHOULS;
    if (ghosts[random_index].active == 0) {
        ghosts[random_index].active = 1;
        ghosts[random_index].name[0] = 'A' + random_index;
        ghosts[random_index].haunt_level = rand() % 3;
        ghosts[random_index].location_x = rand() % 10;
        ghosts[random_index].location_y = rand() % 10;
    }
}

int main() {
    initializeGhosts();
    spawnGhost();
    spawnGhost();
    spawnGhost();

    printf("Welcome to the Haunted House of Doom!\n");
    printf("Prepare to be scared...\n");

    time_t start_time = time(NULL);
    while (time(NULL) - start_time < 3) {
        spawnGhost();
    }

    printf("Thanks for visiting the Haunted House of Doom!\n");
    printf("Now get out of here!\n");

    return 0;
}