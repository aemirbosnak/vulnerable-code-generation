//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SPACESHIPS 2
#define MAX_HEALTH 100

int main()
{
    int playerHealth[SPACESHIPS] = {MAX_HEALTH, MAX_HEALTH}; // Initial health for each player
    int playerPosition[SPACESHIPS] = {0, 0}; // Initial position for each player
    int currentPlayer = 0; // Current player turn
    int attackPower = 0; // Attack power for each player
    int attackedPlayer = 0; // Attacked player for each player's attack
    srand(time(NULL)); // Seed for random number generator

    printf("Welcome to the Procedural Space Adventure game!\n");

    while (1) // Infinite game loop
    {
        printf("Player %d's turn:\n", currentPlayer + 1);
        printf("Position: %d\nHealth: %d\n", playerPosition[currentPlayer], playerHealth[currentPlayer]);
        printf("Enter attack power: ");
        scanf("%d", &attackPower);

        if (attackPower > 0 && attackPower <= 10) // Valid attack power
        {
            attackedPlayer = (currentPlayer + 1) % SPACESHIPS; // Determine attacked player
            playerHealth[attackedPlayer] -= attackPower; // Update attacked player's health

            if (playerHealth[attackedPlayer] < 0) // Attacked player dead
            {
                printf("Player %d has defeated Player %d!\n", currentPlayer + 1, attackedPlayer + 1);
                printf("Player %d is the winner!\n", currentPlayer + 1);
                break; // End game loop
            }
            else // Attacked player alive
            {
                printf("Player %d has dealt %d damage to Player %d! Player %d's health is now %d.\n", currentPlayer + 1, attackPower, attackedPlayer + 1, attackedPlayer + 1, playerHealth[attackedPlayer]);
            }

            playerPosition[currentPlayer] += (rand() % 10) + 1; // Update current player's position

            if (playerPosition[currentPlayer] >= 100) // Current player reached destination
            {
                printf("Player %d has reached the destination first! Player %d is the winner!\n", currentPlayer + 1, currentPlayer + 1);
                break; // End game loop
            }

            currentPlayer = (currentPlayer + 1) % SPACESHIPS; // Update current player turn
        }
        else // Invalid attack power
        {
            printf("Invalid attack power. Please enter a value between 1 and 10.\n");
        }
    }

    return 0;
}