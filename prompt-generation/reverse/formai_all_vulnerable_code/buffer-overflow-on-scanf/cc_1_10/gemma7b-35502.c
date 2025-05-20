//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
    int i, j, k;
    time_t t;

    // Set up the haunted house
    printf("Welcome to the Haunted House of Doom!\n");
    printf("Please enter the number of ghosts you want to encounter: ");
    scanf("%d", &k);

    // Create a random number generator
    srand(time(NULL));

    // Spawn the ghosts
    for (i = 0; i < k; i++)
    {
        printf("Ghost %d appears!\n", i + 1);
        printf("Ghost %d is moving towards you...\n", i + 1);

        // Make the ghost move
        for (j = 0; j < 5; j++)
        {
            int direction = rand() % 4;

            switch (direction)
            {
                case 0:
                    printf("Ghost %d is moving north.\n", i + 1);
                    break;
                case 1:
                    printf("Ghost %d is moving south.\n", i + 1);
                    break;
                case 2:
                    printf("Ghost %d is moving east.\n", i + 1);
                    break;
                case 3:
                    printf("Ghost %d is moving west.\n", i + 1);
                    break;
            }

            // Sleep for a while
            sleep(1);
        }

        // The ghost has gone away
        printf("Ghost %d has retreated.\n", i + 1);
    }

    // The end of the haunted house
    printf("You have survived the Haunted House of Doom!\n");

    return;
}