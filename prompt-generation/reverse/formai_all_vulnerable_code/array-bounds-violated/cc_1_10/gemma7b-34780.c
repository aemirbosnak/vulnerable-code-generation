//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: protected
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_GHOSTS 5
#define MAX_ROOM 10

typedef struct Ghost {
    char name[20];
    int room;
    int active;
} Ghost;

Ghost ghosts[MAX_GHOSTS] = {
    {"John Doe", 1, 1},
    {"Jane Doe", 2, 1},
    {"Mary Smith", 3, 1},
    {"Jack Smith", 4, 1},
    {"Alice White", 5, 1}
};

int main() {
    int room, i;
    time_t t;

    srand(time(NULL));

    // Select a random room
    room = rand() % MAX_ROOM + 1;

    // Activate a random ghost
    ghosts[rand() % MAX_GHOSTS].active = 1;

    // Start the haunted house simulation
    printf("You have entered the haunted house.\n");

    // Listen for ghostly activity
    for (i = 0; i < 10; i++) {
        // Check if the ghost is active
        if (ghosts[room].active) {
            // Ghostly activity
            printf("You hear a noise.\n");
            printf("You feel a cold breeze on your skin.\n");
            printf("You sense a presence in the room.\n");
        }

        // Sleep for a random amount of time
        sleep(rand() % 5 + 1);
    }

    // End the haunted house simulation
    printf("You have left the haunted house.\n");

    return 0;
}