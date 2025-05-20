//FormAI DATASET v1.0 Category: Game ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int playerHealth = 100;
int enemyHealth = 100;

int main() {
    srand(time(NULL)); // Seed the random number generator

    printf("Welcome to Retro Battle!\n");

    // Main game loop
    while (playerHealth > 0 && enemyHealth > 0) {
        printf("Your health: %d\n", playerHealth);
        printf("Enemy health: %d\n", enemyHealth);

        // Get player input
        printf("Choose your attack:\n");
        printf("1. Punch\n");
        printf("2. Kick\n");
        printf("3. Special attack\n");

        int playerAttack;
        printf("Enter your choice: ");
        scanf("%d", &playerAttack);

        // Enemy attack
        int enemyAttack = rand() % 3 + 1;

        // Determine attack damage
        int playerDamage = 0;
        int enemyDamage = 0;

        if (playerAttack == 1) {
            printf("You punched the enemy!\n");
            playerDamage = rand() % 10 + 1;
        }
        else if (playerAttack == 2) {
            printf("You kicked the enemy!\n");
            playerDamage = rand() % 15 + 1;
        }
        else if (playerAttack == 3) {
            printf("You used your special attack!\n");
            playerDamage = rand() % 20 + 1;
        }

        if (enemyAttack == 1) {
            printf("The enemy punched you!\n");
            enemyDamage = rand() % 10 + 1;
        }
        else if (enemyAttack == 2) {
            printf("The enemy kicked you!\n");
            enemyDamage = rand() % 15 + 1;
        }
        else if (enemyAttack == 3) {
            printf("The enemy used their special attack!\n");
            enemyDamage = rand() % 20 + 1;
        }

        // Apply damage
        playerHealth -= enemyDamage;
        enemyHealth -= playerDamage;

        // Check for death
        if (playerHealth <= 0) {
            printf("You died! Game Over.\n");
            break;
        }
        else if (enemyHealth <= 0) {
            printf("You have defeated the enemy! You Win!\n");
            break;
        }

        // A pause for dramatic effect
        printf("\n");
        for (unsigned int i = 0; i < 100000000; i++) {}
        printf("\n");
    }

    printf("Thanks for playing Retro Battle!\n");
    return 0;
}