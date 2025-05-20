//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
    int i, j, k, r, n, t, x, y;
    char c, d, e, f, g;
    time_t t1, t2;

    printf("Welcome to the Haunted House Simulator!\n");

    // Create a spooky atmosphere
    t1 = time(NULL);
    for (i = 0; i < 10; i++)
    {
        printf("\n");
        sleep(1);
    }
    t2 = time(NULL);
    printf("Time elapsed: %ld seconds\n", t2 - t1);

    // Generate a random number of ghosts
    n = rand() % 5 + 1;
    printf("Number of ghosts: %d\n", n);

    // Spawn the ghosts
    for (i = 0; i < n; i++)
    {
        x = rand() % 10 + 1;
        y = rand() % 10 + 1;
        printf("Ghost %d is at (%d, %d)\n", i + 1, x, y);
    }

    // Have the ghosts move around
    for (k = 0; k < 5; k++)
    {
        for (i = 0; i < n; i++)
        {
            x = rand() % 10 + 1;
            y = rand() % 10 + 1;
            printf("Ghost %d is moving to (%d, %d)\n", i + 1, x, y);
        }
        sleep(1);
    }

    // End the simulation
    printf("The haunted house simulator has ended.\n");

    return;
}