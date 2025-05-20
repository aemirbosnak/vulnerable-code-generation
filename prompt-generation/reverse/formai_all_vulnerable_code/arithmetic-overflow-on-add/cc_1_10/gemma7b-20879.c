//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOULS 5
#define GHOUL_DELAY 1000

int main()
{
    int numGhosts = 0;
    int i, j, k;
    time_t t;

    // Initialize the random number generator
    srand(time(NULL));

    // Create a loop to generate a random number of ghosts
    for (i = 0; i < MAX_GHOULS; i++)
    {
        int randNum = rand() % 2;

        // If the random number is 0, a ghost is created
        if (randNum == 0)
        {
            numGhosts++;
        }
    }

    // Print the number of ghosts
    printf("Number of ghosts: %d\n", numGhosts);

    // Create a loop to simulate the haunted house
    for (k = 0; k < numGhosts; k++)
    {
        // Sleep for a random amount of time
        t = time(NULL) + GHOUL_DELAY;
        sleep(t - time(NULL));

        // Randomly choose a sound to play
        int soundNum = rand() % 3;

        // Play the sound
        switch (soundNum)
        {
            case 0:
                printf("Screaming\n");
                break;
            case 1:
                printf("Whispering\n");
                break;
            case 2:
                printf("Footsteps\n");
                break;
        }
    }

    return 0;
}