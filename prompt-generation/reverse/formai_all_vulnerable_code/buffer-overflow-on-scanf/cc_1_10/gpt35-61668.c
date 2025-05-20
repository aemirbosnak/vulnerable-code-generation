//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    srand(time(0)); // Seed value for random function
    int playerHealth = 100;
    int enemyHealth = 100;
    int damageGiven, damageTaken;
    char playerName[50], choice[50], attackType[50];
    
    printf("Welcome to the Adventure Game!\n\n");
    printf("Please enter your name: ");
    scanf("%s", playerName);
    printf("\nGreetings, %s! Your quest is to defeat the evil monster in the dungeon\n", playerName);
    
    while (playerHealth > 0 && enemyHealth > 0) {
        printf("\nYour current health: %d\n", playerHealth);
        printf("Enemy's current health: %d\n\n", enemyHealth);
        
        printf("What would you like to do? (Type 'attack' or 'heal'): ");
        scanf("%s", choice);
        
        if (strcmp(choice, "attack") == 0) {
            printf("\nChoose your attack type (Type 'basic' or 'special'): ");
            scanf("%s", attackType);
            
            if (strcmp(attackType, "basic") == 0) {
                damageGiven = rand() % 20 + 10; // Random value between 10-29
                enemyHealth -= damageGiven;
                printf("\nYou attacked with your sword and gave %d damage!\n", damageGiven);
            } else if (strcmp(attackType, "special") == 0) {
                damageGiven = rand() % 30 + 20; // Random value between 20-49
                enemyHealth -= damageGiven;
                printf("\nYou attacked with your wand and gave %d damage!\n", damageGiven);
            } else {
                printf("\nInvalid attack type!");
                continue;
            }
            
            damageTaken = rand() % 20 + 10; // Random value between 10-29
            playerHealth -= damageTaken;
            printf("The enemy attacked you and gave %d damage!\n", damageTaken);
        } else if (strcmp(choice, "heal") == 0) {
            if (playerHealth == 100) {
                printf("\nYou are already at max health!\n");
                continue;
            }
            
            damageTaken = rand() % 20 + 10; // Random value between 10-29
            playerHealth -= damageTaken;
            printf("\nThe enemy attacked you and gave %d damage!\n", damageTaken);
            
            damageGiven = rand() % 20 + 10; // Random value between 10-29
            playerHealth += damageGiven;
            if (playerHealth > 100) {
                playerHealth = 100;
            }
            printf("You healed yourself and gained %d health points!\n", damageGiven);
        } else {
            printf("\nInvalid choice!");
            continue;
        }
    }
    
    if (playerHealth > 0) {
        printf("\nCongratulations, %s! You have defeated the evil monster!\n", playerName);
    } else {
        printf("\nGame over! Better luck next time, %s!\n", playerName);
    }
    
    return 0;
}