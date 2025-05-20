//Gemma-7B DATASET v1.0 Category: Temperature Converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX_Players 2

int main()
{
    int numPlayers = 2;
    char playerNames[MAX_Players][20];

    // Get player names
    for(int i = 0; i < numPlayers; i++)
    {
        printf("Enter player name: ");
        scanf("%s", playerNames[i]);
    }

    // Set up game loop
    int round = 1;
    while(round <= 5)
    {
        // Get temperature input from each player
        float temperature[MAX_Players];
        for(int i = 0; i < numPlayers; i++)
        {
            printf("%s, enter the temperature: ", playerNames[i]);
            scanf("%f", &temperature[i]);
        }

        // Convert temperatures
        float convertedTemperature[MAX_Players];
        for(int i = 0; i < numPlayers; i++)
        {
            convertedTemperature[i] = (temperature[i] * 1.8) + 32;
        }

        // Display converted temperatures
        printf("Round %d:\n", round);
        for(int i = 0; i < numPlayers; i++)
        {
            printf("%s, your converted temperature is: %.2f\n", playerNames[i], convertedTemperature[i]);
        }

        round++;
    }

    // End of game
    printf("Thank you for playing, %s!", playerNames[0]);
    printf("Thank you for playing, %s!", playerNames[1]);

    return 0;
}