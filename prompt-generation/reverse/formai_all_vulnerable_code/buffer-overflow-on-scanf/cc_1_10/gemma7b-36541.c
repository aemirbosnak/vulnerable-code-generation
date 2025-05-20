//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Define variables
    int choice;
    char name[20];
    int health = 100;

    // Intro
    printf("Welcome, traveler, to the mystical land of Zaria.\n");
    printf("Please tell me your name: ");
    scanf("%s", name);

    // Main Loop
    while (health > 0)
    {
        // Display options
        printf("What would you like to do? (1) Attack, (2) Defend, (3) Heal\n");
        scanf("%d", &choice);

        // Process choice
        switch (choice)
        {
            case 1:
                // Attack
                printf("You attacked the enemy.\n");
                break;
            case 2:
                // Defend
                printf("You defended against the enemy.\n");
                break;
            case 3:
                // Heal
                printf("You healed yourself.\n");
                break;
            default:
                // Invalid choice
                printf("Invalid choice.\n");
                break;
        }

        // Combat results
        if (choice == 1)
        {
            // Randomly determine enemy's health
            int enemyHealth = rand() % 100 + 1;

            // Attack damage
            int damage = rand() % 20 + 1;

            // Subtract damage from enemy's health
            enemyHealth -= damage;

            // Check if enemy is dead
            if (enemyHealth <= 0)
            {
                printf("The enemy is dead.\n");
            }
            else
            {
                printf("The enemy's health is %d.\n", enemyHealth);
            }
        }

        // Check if player is dead
        if (health <= 0)
        {
            printf("You are dead. Game over.\n");
        }
    }

    // End game
    printf("Thank you for playing, %s. May your journey be continued.\n", name);

    return 0;
}