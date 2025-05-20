//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void generateGalaxy(int, int);
void travel(int, int);

// Global variables
int currentSector = 1;
int galaxySize;

int main()
{
    // Seed the random number generator
    srand(time(NULL));
    
    // Get user input for the size of the galaxy
    printf("Size of the galaxy: ");
    scanf("%d", &galaxySize);
    printf("\n");

    // Generate the galaxy
    generateGalaxy(currentSector, galaxySize);

    // Start the adventure
    travel(currentSector, galaxySize);

    return 0;
}

// Function that generates the galaxy
void generateGalaxy(int currentSector, int galaxySize)
{
    printf("Generating galaxy...\n");

    if (currentSector == 1)
    {
        printf("You are currently sector 1. This is the starting point of your adventure.\n\n");
    }

    for (int i = 2; i <= galaxySize; i++)
    {
        // Generate a random boolean value to determine if the sector has a planet or not
        int hasPlanet = rand() % 2;

        if (hasPlanet == 1)
        {
            printf("Sector %d has a planet!\n", i);
        }
        else
        {
            printf("Sector %d is empty.\n", i);
        }
    }

    printf("\n");
}

// Function that allows the player to travel through the galaxy
void travel(int currentSector, int galaxySize)
{
    int destination;

    while (currentSector <= galaxySize)
    {
        // Ask the player for their destination
        printf("Current sector: %d\n", currentSector);
        printf("Choose your destination (enter 0 to quit): ");
        scanf("%d", &destination);

        // If the user enters 0, quit the game
        if (destination == 0)
        {
            printf("Thanks for playing!\n");
            break;
        }

        // If the destination is out of range, prompt the user to enter a valid sector
        if (destination < currentSector || destination > galaxySize)
        {
            printf("Invalid sector. Please choose a sector between %d and %d.\n", currentSector, galaxySize);
            continue;
        }

        // If the player chooses the current sector, don't do anything
        if (destination == currentSector)
        {
            printf("You are already in sector %d.\n", currentSector);
            continue;
        }

        // Otherwise, move the player to the destination sector
        printf("Traveling to sector %d...\n", destination);
        currentSector = destination;

        // If the destination sector has a planet, give the player a chance to explore it
        int hasPlanet = rand() % 2;

        if (hasPlanet == 1)
        {
            printf("You have arrived at a planet!\n");
            printf("Do you want to explore it? (y/n): ");

            char choice;
            scanf(" %c", &choice);

            if (choice == 'y')
            {
                printf("Exploring the planet...\n");
            }
            else
            {
                printf("Returning to space...\n");
            }
        }
    }
}