//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYER_HEALTH 100
#define MAX_ENEMY_HEALTH 50

int main()
{
    int playerHealth = MAX_PLAYER_HEALTH;
    int enemyHealth = MAX_ENEMY_HEALTH;

    char playerName[20];
    printf("Enter your name: ");
    scanf("%s", playerName);

    printf("Welcome, %s, to the future!\n", playerName);

    // Game loop
    while (playerHealth > 0 && enemyHealth > 0)
    {
        // Display inventory
        printf("Inventory: \n");
        printf("------------------------\n");
        printf("Health: %d/%d\n", playerHealth, MAX_PLAYER_HEALTH);
        printf("Weapons: None\n");
        printf("------------------------\n");

        // Get player input
        char input[20];
        printf("Enter your command: ");
        scanf("%s", input);

        // Check if player input is valid
        if (strcmp(input, "attack") == 0)
        {
            // Attack the enemy
            enemyHealth -= 10;
            printf("You attacked the enemy! Enemy health is now %d.\n", enemyHealth);
        }
        else if (strcmp(input, "defend") == 0)
        {
            // Defend against the enemy
            playerHealth -= 5;
            printf("You defended against the enemy. Your health is now %d.\n", playerHealth);
        }
        else if (strcmp(input, "heal") == 0)
        {
            // Heal yourself
            playerHealth += 10;
            printf("You healed yourself. Your health is now %d.\n", playerHealth);
        }
        else
        {
            // Invalid input
            printf("Invalid command. Please try again.\n");
        }

        // Check if the enemy is dead
        if (enemyHealth <= 0)
        {
            printf("You have defeated the enemy! Congratulations!\n");
            break;
        }

        // Check if the player is dead
        if (playerHealth <= 0)
        {
            printf("You have died. Game over.\n");
            break;
        }
    }

    return 0;
}