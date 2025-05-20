//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Define the number of suspects
    int numSuspects = 5;

    // Create an array of suspect names
    char **suspectNames = (char **)malloc(numSuspects * sizeof(char *));

    // Initialize the suspect names
    suspectNames[0] = "Mr. Boddy";
    suspectNames[1] = "Mr. Green";
    suspectNames[2] = "Mr. Plum";
    suspectNames[3] = "Mr. Scarlet";
    suspectNames[4] = "Mr. Yellow";

    // Define the list of suspects' weapons
    char **suspectWeapons = (char **)malloc(numSuspects * sizeof(char *));

    // Initialize the suspect weapons
    suspectWeapons[0] = "Knife";
    suspectWeapons[1] = "Gun";
    suspectWeapons[2] = "Swords";
    suspectWeapons[3] = "Wrench";
    suspectWeapons[4] = "Stick";

    // Define the list of suspects' locations
    char **suspectLocations = (char **)malloc(numSuspects * sizeof(char *));

    // Initialize the suspect locations
    suspectLocations[0] = "Library";
    suspectLocations[1] = "Study";
    suspectLocations[2] = "Hall";
    suspectLocations[3] = "Dining Room";
    suspectLocations[4] = "Kitchen";

    // Play the game
    int gameWon = 0;
    while (!gameWon)
    {
        // Get the player's guess
        char guessSuspectName[20];
        printf("Enter the suspect's name: ");
        scanf("%s", guessSuspectName);

        // Check if the guess is correct
        for (int i = 0; i < numSuspects; i++)
        {
            if (strcmp(guessSuspectName, suspectNames[i]) == 0)
            {
                // The guess is correct
                gameWon = 1;
                printf("You have won! The suspect is %s.", suspectNames[i]);
            }
        }

        // If the guess is not correct, tell the player to try again
        if (!gameWon)
        {
            printf("Incorrect guess. Please try again.\n");
        }
    }

    // Free the memory allocated for the suspect names, weapons, and locations
    free(suspectNames);
    free(suspectWeapons);
    free(suspectLocations);

    return 0;
}