//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOSTS 5

typedef struct Ghost {
    char name[20];
    int room;
    int active;
} Ghost;

Ghost ghosts[MAX_GHOSTS] = {
    {"Mr. Bartholomew", 1, 1},
    {"Ms. Eleanor", 2, 1},
    {"Mr. Henderson", 3, 1},
    {"Mrs. Jones", 4, 1},
    {"The Bloody Bride", 5, 0}
};

int main() {
    int i, j, k;
    int room, ghost_num;
    char sound;

    srand(time(NULL));

    // Spook the halls
    for (i = 0; i < MAX_GHOSTS; i++) {
        ghosts[i].active = rand() % 2;
    }

    // Enter the haunted house
    printf("You have entered the Haunted House of Thornfield Hall.\n");

    // Choose a room
    printf("Please select a room number (1-5): ");
    scanf("%d", &room);

    // Check for a ghost in the chosen room
    for (j = 0; j < MAX_GHOSTS; j++) {
        if (ghosts[j].room == room && ghosts[j].active) {
            // The ghost has been found
            ghost_num = j;
            break;
        }
    }

    // If the ghost has been found, interact with it
    if (ghost_num != -1) {
        printf("You have encountered the ghost of %s.\n", ghosts[ghost_num].name);

        // Listen for a sound
        printf("What sound do you hear? (A, B, C, D, E) ");
        scanf("%c", &sound);

        // The ghost's reaction
        switch (sound) {
            case 'A':
                printf("The ghost whispers secrets in your ear.\n");
                break;
            case 'B':
                printf("The ghost's chains rattle.\n");
                break;
            case 'C':
                printf("The ghost's laughter echoes through the halls.\n");
                break;
            case 'D':
                printf("The ghost's footsteps approach you.\n");
                break;
            case 'E':
                printf("The ghost's voice screams your name.\n");
                break;
            default:
                printf("The ghost is confused.\n");
                break;
        }

        // Escape the haunted house
        printf("You have escaped the Haunted House of Thornfield Hall.\n");
    } else {
        // No ghost found, proceed to the next room
        printf("There is no ghost in that room. You may proceed to the next room.\n");
    }

    return 0;
}