//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate a random number
int randomNumber(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

int main()
{
    // Set up random number generator
    srand(time(NULL));

    // Initialize player's stats
    int playerHealth = 100;
    int playerAttack = 20;
    int playerDefense = 10;
    int playerCredits = 0;

    // Initialize game world
    int planetDistance = 0;
    int planetEnemies = 0;
    char planetName[20];
    int planetCredits = 0;

    // Welcome message
    printf("Welcome to Procedural Space Adventure!\n");

    // Game loop
    while (1)
    {
        // Generate a new planet
        planetDistance += 10;
        planetEnemies = randomNumber(1, 5);
        planetCredits = randomNumber(50, 100);
        sprintf(planetName, "Planet %d", planetDistance / 10);

        // Display planet information
        printf("\nYou arrive at %s.\n", planetName);
        printf("Enemies on this planet: %d\n", planetEnemies);
        printf("Credits on this planet: %d\n", planetCredits);

        // Combat loop
        while (planetEnemies > 0 && playerHealth > 0)
        {
            // Display combat information
            printf("\n%d enemies attack you!\n", planetEnemies);

            // Player attacks
            int playerDamage = randomNumber(playerAttack - 5, playerAttack + 5);
            printf("You deal %d damage to the enemies.\n", playerDamage);
            planetEnemies -= playerDamage / (playerDefense / 2);

            // Enemies attack
            int enemyDamage = randomNumber(5, 20);
            printf("Enemies deal %d damage to you.\n", enemyDamage);
            playerHealth -= enemyDamage / (playerDefense / 2);
            if (playerHealth <= 0)
            {
                printf("You died!\n");
                return 0;
            }
        }

        // Display results of combat
        printf("\nYou have defeated all enemies on %s!\n", planetName);
        playerCredits += planetCredits;
        printf("You earned %d credits.\n", planetCredits);

        // Shop loop
        while (1)
        {
            // Display player information
            printf("\nYou have %d credits and %d health.\n", playerCredits, playerHealth);

            // Display shop menu
            printf("\nWhat would you like to do?\n");
            printf("1. Buy health.\n");
            printf("2. Upgrade attack.\n");
            printf("3. Upgrade defense.\n");
            printf("4. Depart for next planet.\n");
            int choice;
            scanf("%d", &choice);

            // Process shop choice
            if (choice == 1)
            {
                if (playerCredits >= 50)
                {
                    playerHealth += 25;
                    playerCredits -= 50;
                }
                else
                {
                    printf("\nYou don't have enough credits.\n");
                }
            }
            else if (choice == 2)
            {
                if (playerCredits >= 100)
                {
                    playerAttack += 10;
                    playerCredits -= 100;
                }
                else
                {
                    printf("\nYou don't have enough credits.\n");
                }
            }
            else if (choice == 3)
            {
                if (playerCredits >= 75)
                {
                    playerDefense += 5;
                    playerCredits -= 75;
                }
                else
                {
                    printf("\nYou don't have enough credits.\n");
                }
            }
            else if (choice == 4)
            {
                break;
            }
            else
            {
                printf("\nInvalid choice.\n");
            }
        }
    }

    return 0;
}