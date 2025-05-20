//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); //initialize random number generator
    int playerHealth = 100;
    int enemyHealth = 50;
    int playerAttack = 10;
    int enemyAttack = 5;
    int itemDmg = 25;
    int playerChoice;
    
    printf("You find yourself in a world without boundaries.\nEvery path you take leads to a strange and surreal place.\n\n");
    printf("You come across a strange creature with tentacles for arms.\nIt approaches you, do you:\n1. Attack\n2. Try to reason with it\n\n");
    scanf("%d", &playerChoice);
    
    if(playerChoice == 1) { //player attacks creature
        printf("\nThe creature has taken %d damage!\n", playerAttack);
        enemyHealth -= playerAttack;
    } else if(playerChoice == 2) { //player tries to reason with creature
        printf("\nThe creature reveals that it was looking for a companion to explore the surreal world with.\n");
        printf("Do you:\n1. Accept its offer\n2. Continue on your own\n\n");
        scanf("%d", &playerChoice);
        
        if(playerChoice == 1) { //player accepts offer
            printf("\nThe creature is pleased and agrees to accompany you.\n");
        } else if(playerChoice == 2) { //player declines offer
            printf("\nThe creature is angered by your decision and attacks!\n");
            printf("The creature has dealt %d damage!\n", enemyAttack);
            playerHealth -= enemyAttack;
        } else { //invalid choice
            printf("\nI do not understand you.\n");
        }
    } else { //invalid choice
        printf("\nI do not understand you.\n");
    }
    
    if(playerHealth <= 0) { //player loses
        printf("\nYou have been defeated by the surreal world.\n");
        return 0;
    } else if(enemyHealth <= 0) { //player wins
        printf("\nYou have defeated the strange creature and it disappears into the surreal world.\n");
        printf("You come across a mysterious object, do you:\n1. Use it\n2. Ignore it\n\n");
        scanf("%d", &playerChoice);
        
        if(playerChoice == 1) { //player uses item
            printf("\nYou have dealt %d damage to a nearby enemy!\n", itemDmg);
            enemyHealth -= itemDmg;
        } else if(playerChoice == 2) { //player ignores item
            printf("\nYou continue on your journey.\n");
        } else { //invalid choice
            printf("\nI do not understand you.\n");
        }
    } else { //continue battle
        printf("\nThe creature has dealt %d damage!\n", enemyAttack);
        playerHealth -= enemyAttack;
    }
    
    if(playerHealth <= 0) { //player loses
        printf("\nYou have been defeated by the surreal world.\n");
    } else if(enemyHealth <= 0) { //player wins
        printf("\nYou have defeated the strange creature and it disappears into the surreal world.\n");
    } else { //continue battle
        printf("\nThe creature has dealt %d damage!\n", enemyAttack);
        playerHealth -= enemyAttack;
    }
    
    return 0;
}