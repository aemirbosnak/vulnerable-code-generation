//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the Shocked Game!\n");
    printf("In this game, you are a stranded astronaut trying to survive on a deserted planet.\n");
    printf("Your objective is to find and activate the distress beacon while avoiding dangerous creatures lurking on the planet.\n\n");

    // Random seed generator
    srand(time(0));

    // Player stats
    int playerHealth = 100;
    int playerStamina = 50;
    int playerX = 0;
    int playerY = 0;

    // Distress beacon location
    int beaconX = rand() % 10;
    int beaconY = rand() % 10;

    // Creature locations
    int creature1X = rand() % 10;
    int creature1Y = rand() % 10;
    int creature2X = rand() % 10;
    int creature2Y = rand() % 10;

    // Game loop
    while (1)
    {
        // Player stats
        printf("\nPlayer Stats:\n");
        printf("Health: %d\n", playerHealth);
        printf("Stamina: %d\n", playerStamina);
        printf("Location: (%d,%d)\n\n", playerX, playerY);

        // Distress beacon location
        printf("Distress Beacon Location: (%d,%d)\n\n", beaconX, beaconY);

        // Creature locations
        printf("Creature Locations:\n");
        printf("Creature 1: (%d,%d)\n", creature1X, creature1Y);
        printf("Creature 2: (%d,%d)\n\n", creature2X, creature2Y);

        // Player input
        printf("Enter direction (w/a/s/d): ");
        char direction;
        scanf(" %c", &direction);

        // Check player direction
        switch (direction)
        {
        case 'w':
            playerY++;
            break;
        case 'a':
            playerX--;
            break;
        case 's':
            playerY--;
            break;
        case 'd':
            playerX++;
            break;
        default:
            printf("Invalid direction!\n");
            break;
        }

        // Check if player is out of bounds
        if (playerX < 0 || playerX > 9 || playerY < 0 || playerY > 9)
        {
            printf("You have gone out of bounds!\n");
            playerHealth = 0;
        }

        // Check if player has reached the distress beacon
        if (playerX == beaconX && playerY == beaconY)
        {
            printf("Congratulations, you have activated the distress beacon and have been rescued! You win!\n");
            break;
        }

        // Check if player has encountered a creature
        if ((playerX == creature1X && playerY == creature1Y) || (playerX == creature2X && playerY == creature2Y))
        {
            printf("Oh no, you have encountered a creature!\n");
            playerStamina -= 10;

            if (playerStamina < 0)
            {
                printf("You have run out of stamina and have been killed by the creature! You lose!\n");
                break;
            }

            printf("You have survived the encounter but have lost 10 stamina points.\n");
        }

        // Update creature locations
        creature1X = rand() % 10;
        creature1Y = rand() % 10;
        creature2X = rand() % 10;
        creature2Y = rand() % 10;

        // Decrease player stamina at end of turn
        playerStamina -= 5;

        // Check if player has run out of stamina
        if (playerStamina < 0)
        {
            printf("You have run out of stamina and have died! You lose!\n");
            break;
        }

        // Decrease player health if player has not moved
        if (direction == '\n')
        {
            playerHealth--;
        }

        // Check if player has died
        if (playerHealth <= 0)
        {
            printf("You have died! You lose!\n");
            break;
        }
    }

    return 0;
}