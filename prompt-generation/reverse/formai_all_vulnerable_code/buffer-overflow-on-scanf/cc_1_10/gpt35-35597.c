//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to display the intro screen
void displayIntro()
{
    printf("Welcome to the Medieval Adventure!\n");
    printf("You are a brave adventurer who has been summoned by the King to save his daughter from the evil sorcerer who has kidnapped her.\n");
    printf("The King will reward you greatly if you succeed, but beware, the sorcerer's dungeon is full of traps and dangers.\n");
    printf("Are you ready to begin your quest?\n");
}

// Function to display the menu
void displayMenu()
{
    printf("\nWhat would you like to do?\n");
    printf("1. Explore the dungeon\n");
    printf("2. Check your inventory\n");
    printf("3. Rest and recover\n");
    printf("4. Quit the game\n");
}

// Function to generate a random number between min and max
int generateRandomNumber(int min, int max)
{
    srand(time(NULL));
    return (rand() % (max - min + 1)) + min;
}

// Function to start the game
void startGame()
{
    // Initialize game variables
    int health = 100;
    int strength = 10;
    int gold = 0;
    int potions = 5;
    int traps = 0;
    int enemiesDefeated = 0;
    int princessSaved = 0;
    int roomNumber = 0;
    char choice[10];

    // Start the game loop
    while (1)
    {
        // Display the menu and get the user's choice
        displayMenu();
        scanf("%s", choice);

        if (strcmp(choice, "1") == 0)
        {
            // Explore the dungeon
            printf("\nYou enter room %d.\n", roomNumber);

            // Generate a random event
            int event = generateRandomNumber(1, 3);
            if (event == 1)
            {
                // Fight an enemy
                int enemyStrength = generateRandomNumber(5, 15);
                printf("You encounter an enemy!\n");
                printf("Your health: %d\n", health);
                printf("Enemy strength: %d\n", enemyStrength);

                // Battle until one party is defeated
                while (1)
                {
                    // Player attacks
                    int playerDamage = generateRandomNumber(1, strength);
                    printf("You strike the enemy for %d damage.\n", playerDamage);
                    enemyStrength -= playerDamage;
                    if (enemyStrength <= 0)
                    {
                        printf("You defeated the enemy!\n");
                        gold += generateRandomNumber(10, 20);
                        enemiesDefeated++;
                        break;
                    }

                    // Enemy attacks
                    int enemyDamage = generateRandomNumber(1, enemyStrength);
                    printf("The enemy strikes you for %d damage.\n", enemyDamage);
                    health -= enemyDamage;
                    if (health <= 0)
                    {
                        printf("You have been defeated.\n");
                        printf("You defeated %d enemies and saved %d princesses.\n", enemiesDefeated, princessSaved);
                        exit(0);
                    }
                }
            }
            else if (event == 2)
            {
                // Find a trap
                printf("You find a trap!\n");
                traps++;
            }
            else
            {
                // Find a potion
                printf("You find a potion!\n");
                potions++;
            }

            // Check for princess
            if (generateRandomNumber(1, 10) == 1)
            {
                printf("You have found the princess!\n");
                princessSaved++;
            }

            // Move to the next room
            roomNumber++;
        }
        else if (strcmp(choice, "2") == 0)
        {
            // Check inventory
            printf("\nInventory:\n");
            printf("Health: %d\n", health);
            printf("Strength: %d\n", strength);
            printf("Gold: %d\n", gold);
            printf("Potions: %d\n", potions);
            printf("Traps: %d\n", traps);
        }
        else if (strcmp(choice, "3") == 0)
        {
            // Rest and recover
            int recovery = generateRandomNumber(5, 15);
            health += recovery;
            if (health > 100)
            {
                health = 100;
            }
            printf("\nYou rest and recover %d health.\n", recovery);
        }
        else if (strcmp(choice, "4") == 0)
        {
            // Quit the game
            printf("\nYou quit the game.\n");
            printf("You defeated %d enemies and saved %d princesses.\n", enemiesDefeated, princessSaved);
            exit(0);
        }
        else
        {
            // Invalid input
            printf("\nInvalid input.\n");
        }
    }
}

// Main function
int main()
{
    displayIntro();
    startGame();
    return 0;
}