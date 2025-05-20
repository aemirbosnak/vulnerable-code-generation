//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function declaration */
void travel();
void encounterEnemy();
void encounterPlanet();
void encounterTreasure();

/* Global variables */
int playerGold = 0;
int playerHealth = 100;
int currentPlanet = 1;

/* Main function */
int main() {
    srand(time(NULL));
    
    printf("Welcome to Procedural Space Adventure!\n");
    printf("You have been stranded in space and must find your way back home.\n");
    printf("Your journey begins on Planet 1.\n\n");
    
    while (playerHealth > 0 && currentPlanet < 5) {
        travel();
    }
    
    if (currentPlanet == 5) {
        printf("Congratulations! You have made it back home with %d gold.\n", playerGold);
    }
    else {
        printf("Game over. You did not make it back home.\n");
    }
    
    return 0;
}

/* Function definitions */
void travel() {
    int encounter = rand() % 3;
    
    switch (encounter) {
        case 0:
            encounterEnemy();
            break;
        case 1:
            encounterPlanet();
            break;
        case 2:
            printf("You travel safely through space.\n");
            break;
    }
}

void encounterEnemy() {
    int enemyHealth = 50;
    int playerAttack = rand() % 20 + 10;
    int enemyAttack = rand() % 15 + 5;
    
    printf("You encounter an enemy!\n");
    
    while (playerHealth > 0 && enemyHealth > 0) {
        printf("Your health: %d, Enemy health: %d\n", playerHealth, enemyHealth);
        
        // Player attacks enemy
        enemyHealth -= playerAttack;
        printf("You hit the enemy for %d damage!\n", playerAttack);
        
        // Enemy attacks player
        playerHealth -= enemyAttack;
        printf("The enemy hits you for %d damage!\n", enemyAttack);
    }
    
    if (playerHealth <= 0) {
        printf("You are dead. Game over.\n");
        exit(0);
    }
    else {
        printf("You defeated the enemy and gained 20 gold!\n");
        playerGold += 20;
        printf("You now have %d gold.\n", playerGold);
    }
}

void encounterPlanet() {
    int planetType = rand() % 3;
    
    switch (planetType) {
        case 0:
            printf("You have found a merchant! Do you want to buy or sell?\n");
            printf("1. Buy\n2. Sell\n");
            int choice;
            scanf("%d", &choice);
            
            if (choice == 1) {
                printf("The merchant sells you a sword for 30 gold.\n");
                
                if (playerGold >= 30) {
                    playerGold -= 30;
                    printf("You now have %d gold.\n", playerGold);
                }
                else {
                    printf("You don't have enough gold to buy the sword.\n");
                }
            }
            else if (choice == 2) {
                printf("The merchant buys your space helmet for 20 gold.\n");
                playerGold += 20;
                printf("You now have %d gold.\n", playerGold);
            }
            else {
                printf("Invalid choice.\n");
            }
            
            break;
        case 1:
            printf("You have found a space station! Do you want to heal or upgrade?\n");
            printf("1. Heal (10 gold)\n2. Upgrade attack (25 gold)\n");
            int choice2;
            scanf("%d", &choice2);
            
            if (choice2 == 1) {
                if (playerGold >= 10) {
                    playerGold -= 10;
                    playerHealth = 100;
                    printf("You have been healed to full health.\n");
                    printf("You now have %d gold.\n", playerGold);
                }
                else {
                    printf("You don't have enough gold to heal.\n");
                }
            }
            else if (choice2 == 2) {
                if (playerGold >= 25) {
                    playerGold -= 25;
                    printf("You have upgraded your attack!\n");
                    printf("You now have %d gold.\n", playerGold);
                }
                else {
                    printf("You don't have enough gold to upgrade.\n");
                }
            }
            else {
                printf("Invalid choice.\n");
            }
            
            break;
        case 2:
            encounterTreasure();
            break;
    }
    
    currentPlanet++;
}

void encounterTreasure() {
    int treasureAmount = rand() % 50 + 50;
    
    printf("You have found a treasure chest! It contains %d gold.\n", treasureAmount);
    playerGold += treasureAmount;
    printf("You now have %d gold.\n", playerGold);
}