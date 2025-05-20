//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between two given integers
int randomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    srand(time(NULL));
    int fuelLevel = 100;
    int enemyHealth = 100;
    int enemyDamage = 10;
    int playerHealth = 100;
    int playerDamage = 15;
    int credits = 0;
    int encounters = 0;
    printf("Welcome to Procedural Space Adventure!\n");
    printf("Your mission is to travel through space, encounter and defeat enemy spacecrafts, and earn credits for upgrades.\n");
    printf("You start with full fuel and health.\n");

    while(fuelLevel > 0 && playerHealth > 0) {
        int enemyLevel = randomNumber(1, 10); // Generate a random enemy level between 1 and 10
        int enemyDamageTaken = 0; // Initialize enemy damage taken to 0
        int playerDamageTaken = 0; // Initialize player damage taken to 0
        printf("\nEncounter %d:\n", encounters+1);
        printf("You have encountered a level %d enemy spacecraft!\n", enemyLevel);
        printf("Your fuel level: %d\n", fuelLevel);
        printf("Your health: %d\n", playerHealth);
        printf("Enemy health: %d\n", enemyHealth);

        while(enemyHealth > 0 && playerHealth > 0 && fuelLevel > 0) {
            int action;
            printf("\nChoose an action:\n");
            printf("1. Attack\n");
            printf("2. Flee\n");
            printf("Action: ");
            scanf("%d", &action);

            if(action == 1) { // If player chooses to attack
                enemyDamageTaken = randomNumber(10, 25) + playerDamage; // Calculate enemy damage taken
                playerDamageTaken = randomNumber(10, 20) + enemyDamage; // Calculate player damage taken
                playerHealth -= playerDamageTaken; // Reduce player health by player damage taken
                enemyHealth -= enemyDamageTaken; // Reduce enemy health by enemy damage taken
                printf("\nYou dealt %d damage to the enemy!\n", playerDamageTaken);
                printf("You took %d damage from the enemy's counterattack!\n", enemyDamageTaken);
                if(enemyHealth <= 0) { // If enemy is defeated
                    int creditsGained = enemyLevel * 10; // Calculate credits gained
                    credits += creditsGained; // Add credits gained to total credits
                    printf("\nCongratulations, you have defeated the enemy and gained %d credits!\n", creditsGained);
                }
            }
            else if(action == 2) { // If player chooses to flee
                int fleeChance = randomNumber(1, 10); // Generate a random number between 1 and 10
                if(fleeChance <= 5) { // If flee chance is 50% or less
                    printf("\nYou were unsuccessful in fleeing and took %d damage!\n", enemyDamage);
                    playerHealth -= enemyDamage; // Reduce player health by enemy damage
                }
                else { // If flee chance is more than 50%
                    printf("\nYou have successfully fled from the enemy!\n");
                    fuelLevel -= 20; // Reduce fuel level by 20
                    break; // Break out of the encounter loop
                }
            }
            else { // If player enters an invalid action
                printf("\nInvalid action, try again.\n");
                continue; // Continue the encounter loop
            }
            printf("Your fuel level: %d\n", fuelLevel);
            printf("Your health: %d\n", playerHealth);
            printf("Enemy health: %d\n", enemyHealth);
            fuelLevel -= 10; // Reduce fuel level by 10
        }
        encounters++; // Increment number of encounters
        if(playerHealth <= 0) { // If player is defeated
            printf("\nGame over, you were defeated by the enemy spacecrafts!\n");
            printf("You encountered %d enemies and earned %d credits.\n", encounters, credits);
            break; // Break out of the game loop
        }
        if(fuelLevel <= 0) { // If player runs out of fuel
            printf("\nGame over, you ran out of fuel!\n");
            printf("You encountered %d enemies and earned %d credits.\n", encounters, credits);
            break; // Break out of the game loop
        }
        printf("\nYou can now visit the shop to upgrade your spacecraft with %d credits.\n", credits);
        int shopChoice;
        printf("\nChoose an upgrade:\n");
        printf("1. Increase maximum health (+10)\n");
        printf("2. Increase damage (+5)\n");
        printf("3. Refill fuel (+20)\n");
        printf("4. Leave the shop\n");
        printf("Shop choice: ");
        scanf("%d", &shopChoice);

        switch(shopChoice) {
            case 1:
                playerHealth += 10; // Increase maximum health by 10
                credits -= 20; // Reduce credits by 20
                printf("\nYour maximum health is now %d.\n", playerHealth);
                break;
            case 2:
                playerDamage += 5; // Increase damage by 5
                credits -= 25; // Reduce credits by 25
                printf("\nYour damage is now %d.\n", playerDamage);
                break;
            case 3:
                fuelLevel += 20; // Refill fuel by 20
                credits -= 15; // Reduce credits by 15
                printf("\nYour fuel level is now %d.\n", fuelLevel);
                break;
            case 4:
                printf("\nLeaving the shop...\n");
                break;
            default:
                printf("\nInvalid choice, leaving the shop...\n");
        }
    }
    printf("\nThank you for playing Procedural Space Adventure!\n");
    return 0;
}