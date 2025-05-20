//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOULS 10
#define MAX_THINGS 5

typedef struct Ghost {
    char name[20];
    int room;
    int action;
} Ghost;

typedef struct Thing {
    char name[20];
    int location;
    int state;
} Thing;

Ghost ghosts[MAX_GHOULS];
Thing things[MAX_THINGS];

void initializeGhosts() {
    for (int i = 0; i < MAX_GHOULS; i++) {
        ghosts[i].name[0] = '\0';
        ghosts[i].room = -1;
        ghosts[i].action = -1;
    }
}

void initializeThings() {
    for (int i = 0; i < MAX_THINGS; i++) {
        things[i].name[0] = '\0';
        things[i].location = -1;
        things[i].state = -1;
    }
}

void hauntHouse() {
    time_t start_time = time(NULL);

    // Ghost movement
    for (int i = 0; i < MAX_GHOULS; i++) {
        if (ghosts[i].name[0] != '\0') {
            // Randomly move the ghost to a new room
            ghosts[i].room = rand() % MAX_THINGS;

            // Perform the ghost's action
            switch (ghosts[i].action) {
                case 0:
                    printf("Ghost %s moves to room %d.\n", ghosts[i].name, ghosts[i].room);
                    break;
                case 1:
                    printf("Ghost %s screams.\n", ghosts[i].name);
                    break;
                case 2:
                    printf("Ghost %s opens a door.\n", ghosts[i].name);
                    break;
            }
        }
    }

    // Thing movement
    for (int i = 0; i < MAX_THINGS; i++) {
        if (things[i].name[0] != '\0') {
            // Randomly move the thing to a new location
            things[i].location = rand() % MAX_THINGS;

            // Change the thing's state
            things[i].state = rand() % 3;

            // Print the thing's movement
            printf("Thing %s moves to location %d and changes state to %d.\n", things[i].name, things[i].location, things[i].state);
        }
    }

    // Play spooky music
    system("play spooky_music.mp3");

    // Display a creepy message
    printf("The house shakes violently...\n");

    time_t end_time = time(NULL);
    printf("Time spent haunting the house: %d seconds\n", end_time - start_time);
}

int main() {
    initializeGhosts();
    initializeThings();

    hauntHouse();

    return 0;
}