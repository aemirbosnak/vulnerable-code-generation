//FormAI DATASET v1.0 Category: Smart home light control ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define NUM_PLAYERS 3  // Number of players in the game
#define NUM_LIGHTS 8   // Number of lights in the house

int main()
{
    int lights[NUM_LIGHTS] = {0}; // Initialize all lights to be off
    int currentPlayer, selectedLight;
    int winner = -1;
    int numOnLights = 0;
    
    // Seed the random number generator
    srand(time(NULL));
    
    // Let each player take turns selecting a light to turn on or off
    while(numOnLights < NUM_LIGHTS)
    {
        for(currentPlayer = 1; currentPlayer <= NUM_PLAYERS; currentPlayer++)
        {
            printf("Player %d, it's your turn.\n", currentPlayer);
            printf("Enter the number of the light you want to toggle (1-8): ");
            scanf("%d", &selectedLight);
            
            // Check for valid input
            if(selectedLight < 1 || selectedLight > NUM_LIGHTS)
            {
                printf("Invalid light number. Choose a number between 1 and 8.\n");
                currentPlayer--; // Repeat this player's turn
                continue; // Skip the rest of this loop iteration
            }
            
            // Toggle the selected light
            lights[selectedLight-1] = !lights[selectedLight-1];
            
            // Count the number of on lights
            numOnLights = 0;
            for(int i = 0; i < NUM_LIGHTS; i++)
            {
                if(lights[i] == 1)
                {
                    numOnLights++;
                }
            }
            
            // Check for a winner
            if(numOnLights == NUM_LIGHTS)
            {
                winner = currentPlayer;
                break; // Exit the loop
            }
        }
    }
    
    // Display the winner
    printf("Player %d wins!\n", winner);
    
    return 0;
}