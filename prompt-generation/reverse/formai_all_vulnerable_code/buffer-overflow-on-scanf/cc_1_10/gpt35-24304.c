//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Initialize variables
    char name[20];
    int playerHealth = 100;
    int monsterHealth = 100;
    int playerAttack;
    int monsterAttack;
    int round = 1;
    char choice;

    // Welcome the player and get their name
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("What is your name, adventurer? ");
    scanf("%s", name);

    // Introduction
    printf("\nWelcome, %s! You have been summoned to defeat the monster that is terrorizing our town.\n", name);
    printf("The monster is incredibly strong, so you must choose your actions wisely.\n");

    // Game loop
    while (playerHealth > 0 && monsterHealth > 0)
    {
        // Generate the monster's attack
        srand(time(NULL));
        monsterAttack = rand() % 25 + 1;

        // Get the player's attack choice
        printf("\nRound %d. Your health: %d. Monster's health: %d.\n", round, playerHealth, monsterHealth);
        printf("What attack do you want to use? (a. Melee, b. Ranged, or c. Magic): ");
        scanf(" %c", &choice);

        // Calculate the player's attack damage
        if (choice == 'a')
        {
            playerAttack = rand() % 10 + 1;
            monsterHealth -= playerAttack;
            printf("You use Melee and deal %d damage to the monster!\n", playerAttack);
        }
        else if (choice == 'b')
        {
            playerAttack = rand() % 15 + 5;
            monsterHealth -= playerAttack;
            printf("You use Ranged and deal %d damage to the monster!\n", playerAttack);
        }
        else if (choice == 'c')
        {
            playerAttack = rand() % 20 + 10;
            monsterHealth -= playerAttack;
            printf("You use Magic and deal %d damage to the monster!\n", playerAttack);
        }
        else
        {
            printf("Invalid choice. The monster attacks you instead!\n");
        }

        // Check if the monster is dead
        if (monsterHealth <= 0)
        {
            printf("\nThe monster has been defeated! Congratulations, %s!\n", name);
            return 0;
        }

        // Calculate the monster's attack damage
        playerHealth -= monsterAttack;
        printf("The monster attacks you and deals %d damage!\n", monsterAttack);

        // Check if the player is dead
        if (playerHealth <= 0)
        {
            printf("\nYou have been defeated by the monster. Game over.\n");
            return 0;
        }

        // Increment the round counter
        round++;
    }

    return 0;
}