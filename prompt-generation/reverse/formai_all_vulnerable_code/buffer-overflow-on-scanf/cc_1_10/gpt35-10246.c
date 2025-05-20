//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void printSpaces(int numSpaces) {
    for(int i = 0; i < numSpaces; i++) {
        printf(" ");
    }
}

int main() {
    srand(time(NULL));
    char playerName[50];
    int playerHealth = 100;
    int playerDamage = 10;
    int totalEnemies = 15;
    int enemiesDefeated = 0;
    int enemyDamage = 5;
    int enemyHealth = 20;
    int numSpaces = 30;
    
    printf("Welcome to Procedural Space Adventure, the only game where the enemies make themselves up as they go!\n");
    printf("Before we get started, what's your name? ");
    scanf("%s", playerName);
    printf("Alright %s, let's get started!\n\n", playerName);
    
    while(playerHealth > 0 && enemiesDefeated < totalEnemies) {
        int randomEnemy = rand() % 3 + 1;
        int enemyHealthRand = rand() % 10 + 10;
        if(randomEnemy == 1) {
            printSpaces(numSpaces);
            printf("*BLOB BLOB* A slime-like creature appears before you!\n");
            enemyHealth = enemyHealthRand;
        } else if(randomEnemy == 2) {
            printSpaces(numSpaces);
            printf("*ROAR* A giant space bear is charging at you!\n");
            enemyHealth = enemyHealthRand;
        } else {
            printSpaces(numSpaces);
            printf("*ZAP ZAP* An alien with a laser gun has targeted you!\n");
            enemyHealth = enemyHealthRand;
        }
        
        while(enemyHealth > 0 && playerHealth > 0) {
            int playerAttack = rand() % playerDamage + 5;
            int enemyAttack = rand() % enemyDamage + 2;
            
            printSpaces(numSpaces);
            printf("Your health: %d\n", playerHealth);
            printSpaces(numSpaces);
            printf("Enemy health: %d\n", enemyHealth);
            
            printSpaces(numSpaces);
            printf("What will you do? (1 - Attack, 2 - Defend, 3 - Run) ");
            int playerChoice;
            scanf("%d", &playerChoice);
            
            if(playerChoice == 1) {
                enemyHealth -= playerAttack;
                printSpaces(numSpaces);
                printf("You deal %d damage to the enemy!\n", playerAttack);
            } else if(playerChoice == 2) {
                playerHealth += 5;
                printSpaces(numSpaces);
                printf("You defend and heal yourself for 5 health.\n");
            } else {
                int runChance = rand() % 2;
                if(runChance == 1) {
                    printSpaces(numSpaces);
                    printf("You have successfully run away from the enemy!\n");
                    break;
                } else {
                    playerHealth -= enemyAttack;
                    printSpaces(numSpaces);
                    printf("You try to run, but the enemy attacks you for %d damage!\n", enemyAttack);
                }
            }
            
            playerHealth -= enemyAttack;
            printSpaces(numSpaces);
            printf("The enemy attacks you for %d damage!\n", enemyAttack);
        }
        
        if(playerHealth <= 0) {
            printf("Game over! You have been defeated by the enemy.\n");
        } else {
            printf("You have defeated the enemy!\n");
            enemiesDefeated++;
            playerDamage += 3;
        }
    }
    
    if(enemiesDefeated == totalEnemies) {
        printf("Congratulations %s! You have completed Procedural Space Adventure and saved the galaxy!\n", playerName);
    }
    
    return 0;
}