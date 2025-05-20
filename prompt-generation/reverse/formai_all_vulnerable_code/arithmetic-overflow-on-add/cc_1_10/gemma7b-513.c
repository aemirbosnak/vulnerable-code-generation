//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOSTS 10
#define GHOST_DELAY 2

typedef struct Ghost {
    char name[20];
    int room_num;
    int behavior;
} Ghost;

Ghost ghosts[MAX_GHOSTS] = {
    {"Mr. Jones", 1, 3},
    {"Mrs. Smith", 2, 2},
    {"The Poltergeist", 3, 5},
    {"The Phantom", 4, 4},
    {"The Witch", 5, 3},
    {"The Vampire", 6, 2},
    {"The Ghostly Bride", 7, 5},
    {"The Disembodied Hand", 8, 4},
    {"The Bloody Mary", 9, 3},
    {"The Babbling Spirit", 10, 2}
};

void simulate_haunted_house() {
    int i, j, room_num, ghost_num;
    time_t t;

    // Randomly select a room number
    room_num = rand() % MAX_GHOSTS;

    // Select a ghost from that room
    ghost_num = ghosts[room_num].room_num;

    // Create a time delay
    t = time(NULL) + GHOST_DELAY;

    // Have the ghost move around the house
    for (i = 0; i < MAX_GHOSTS; i++) {
        if (ghosts[i].room_num == ghost_num) {
            printf("%s has moved to room %d.\n", ghosts[i].name, ghosts[i].room_num);
        }
    }

    // Wait for the delay
    sleep(t - time(NULL));

    // Print a message
    printf("The ghost has moved on.\n");
}

int main() {
    int i;

    // Simulate the haunted house
    simulate_haunted_house();

    return 0;
}