//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: detailed
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_GHOULS 5

typedef struct Ghost {
    char name[20];
    int haunt_location;
    int presence;
} Ghost;

Ghost ghosts[MAX_GHOULS] = {
    {"Mary", 101, 1},
    {"Jack", 202, 1},
    {"Anna", 303, 0},
    {"Peter", 404, 0},
    {"Sarah", 505, 0}
};

int main()
{
    int i, j, k, haunt_location, presence;
    time_t t;

    // Seed the random number generator
    srand(time(NULL));

    // Create a haunted house
    for (i = 0; i < MAX_GHOULS; i++)
    {
        ghosts[i].presence = rand() % 2;
    }

    // Get the haunt location
    haunt_location = rand() % 500;

    // Check if the house is haunted
    presence = ghosts[haunt_location].presence;

    // If the house is haunted, the ghost will appear
    if (presence)
    {
        printf("You hear a ghostly moan.\n");
        printf("The hairs on your neck stand on end.\n");
        printf("You feel a cold hand brush against your skin.\n");
    }

    return 0;
}