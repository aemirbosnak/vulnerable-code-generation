//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    // Initialize game variables
    int playerHealth = 100;
    int enemyHealth = 100;
    int playerDamage = 0;
    int enemyDamage = 0;
    int playerArmor = 0;
    int enemyArmor = 0;
    int potionCount = 3;
    int enemyType = rand() % 3 + 1;
    char input;

    // Game introduction
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are an adventurer on a quest to defeat the evil creatures that have been terrorizing the land.\n\n");

    // Game loop
    while (playerHealth > 0 && enemyHealth > 0) {
        enemyType = rand() % 3 + 1;
        if (enemyType == 1) {
            printf("You encountered a goblin!\n");
            enemyHealth = 50;
            enemyArmor = 5;
        } else if (enemyType == 2) {
            printf("You encountered an orc!\n");
            enemyHealth = 75;
            enemyArmor = 10;
        } else {
            printf("You encountered a dragon!\n");
            enemyHealth = 100;
            enemyArmor = 20;
        }

        // Player turn
        printf("Your turn! Choose an action:\n");
        printf("(a) Attack\n");
        printf("(p) Use potion (%d)\n", potionCount);
        scanf(" %c", &input);

        if (input == 'a') {
            playerDamage = rand() % 20 + 10;
            printf("You attacked the enemy for %d damage!\n", playerDamage);
            enemyHealth -= playerDamage;
        } else if (input == 'p' && potionCount > 0) {
            playerHealth += 25;
            if (playerHealth > 100) {
                playerHealth = 100;
            }
            potionCount--;
            printf("You used a potion and gained 25 health!\n");
        }

        // Enemy turn
        if (enemyHealth > 0) {
            printf("Enemy turn!\n");
            enemyDamage = rand() % 20 + 10;
            printf("The enemy attacked you for %d damage!\n", enemyDamage);
            playerArmor = rand() % 10;
            playerHealth -= (enemyDamage - playerArmor);
        }

        // Print stats
        printf("Your health: %d\n", playerHealth);
        printf("Enemy health: %d\n\n", enemyHealth);
    }

    // Game over message
    if (playerHealth <= 0) {
        printf("You died! Game over.\n");
    } else {
        printf("You defeated the enemy! Congratulations!\n");
    }

    return 0;
}