//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Cyberpunk
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main() {
    //Initialize variables
    char playerName[50];
    int playerHealth = 100;
    int enemyHealth = 75;
    bool isGameOver = false;
    int numEnemies = 0;
    int maxEnemies = 3;
    bool hasKey = false;
    
    //Ask for player's name
    printf("Welcome to the Cyberpunk Adventure Game! What's your name?\n");
    scanf("%s", playerName);
    
    //Narrate the story
    printf("Hello %s, you are a hacker in a futuristic city. Your mission is to infiltrate the highly secure building of a corrupt corporation and steal their top secret plans. \n", playerName);
    printf("You make your way to the building and hack into their security system. Inside, you find a group of guards roaming around.\n");
    printf("You must defeat them all to gain access to the top floor. Be careful, they are armed and dangerous. Good luck!\n\n");
    
    //Combat loop
    while(!isGameOver) {
        //Player turn
        printf("You have %d health points and are facing %d enemies. What do you want to do? Type 'attack' or 'run'\n", playerHealth, numEnemies);
        char playerChoice[10];
        scanf("%s", playerChoice);
        
        if(strcmp(playerChoice, "attack") == 0) {
            //Calculate player's damage
            int playerDamage = rand() % 10 + 1;
            printf("You deal %d damage to the enemy!\n", playerDamage);
            enemyHealth -= playerDamage;
            
            //Check if enemy is defeated
            if(enemyHealth <= 0) {
                printf("You have defeated the enemy!\n");
                numEnemies--;
                if(numEnemies == 0) {
                    printf("Congratulations! You have defeated all enemies and obtained the top secret plans. You win!\n");
                    isGameOver = true;
                }
                else {
                    //Find a key
                    int keyChance = rand() % 2;
                    if(keyChance == 1) {
                        printf("You found a key on the enemy. This might be useful!\n");
                        hasKey = true;
                    }
                    else {
                        printf("No luck, the enemy had no key on them.\n");
                    }
                    //Reset enemy's health
                    enemyHealth = 75;
                }
            } 
        }
        else if(strcmp(playerChoice, "run") == 0) {
            //Calculate player's chance of escape
            int escapeChance = rand() % 2;
            if(escapeChance == 1) {
                printf("You run away from the enemies and hide. They couldn't find you.\n");
                //Reset enemy's health
                enemyHealth = 75;
            }
            else {
                printf("You cannot escape from the enemies. You must fight!\n");
                //Enemy turn
                int enemyDamage = rand() % 10 + 1;
                printf("The enemy deals %d damage to you!\n", enemyDamage);
                playerHealth -= enemyDamage;
                //Check if player died
                if(playerHealth <= 0) {
                    printf("You died in combat. GAME OVER!\n");
                    isGameOver = true;
                }
            }
        }
        else {
            printf("Invalid input. Choose 'attack' or 'run'\n");
        }
        
        //If there are less enemies than the max, generate a new enemy
        if(numEnemies < maxEnemies) {
            printf("Another enemy approaches!");
            numEnemies++;
        }
    }
    
    return 0;
}