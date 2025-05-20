//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int playerHealth = 100;
    int enemyHealth = 75;
    int playerGold = 0;
    int randomNumber;
    char playerName[20];
    
    srand(time(NULL));
    
    printf("Welcome to Procedural Space Adventure!\n");
    printf("Please enter your name: ");
    scanf("%s", playerName);
    printf("\n");
    
    printf("Greetings, %s! You are an adventurer on a mission to explore uncharted territory in space.\n", playerName);
    printf("Your ship has crash-landed on a remote planet, and your main goal now is to find a way out of here alive.\n");
    printf("You notice that there are hostile alien creatures lurking around, so be careful!\n\n");
    
    while(playerHealth > 0 && enemyHealth > 0) {
        printf("Your health: %d/100, Enemy health: %d/75\n", playerHealth, enemyHealth);
        printf("What would you like to do?\n");
        printf("1. Attack enemy\n2. Flee\n");
        scanf("%d", &randomNumber);
        
        if(randomNumber == 1) {
            int attackPower = rand() % 30 + 10;
            enemyHealth -= attackPower;
            printf("You dealt %d damage to the enemy.\n", attackPower);
            
            if(enemyHealth <= 0) {
                printf("Congratulations! You defeated the enemy and earned 50 gold coins.\n");
                playerGold += 50;
                break;
            }
            
            int enemyAttackPower = rand() % 20 + 5;
            playerHealth -= enemyAttackPower;
            printf("The enemy dealt %d damage to you.\n", enemyAttackPower);
            
            if(playerHealth <= 0) {
                printf("Game over! You were defeated by the enemy.\n");
                break;
            }
        } else { 
            printf("You fled from the enemy.\n");
            break;
        }
    }
    
    printf("\nYou currently have %d gold coins. What would you like to do?\n", playerGold);
    printf("1. Buy healing potion (50 gold coins)\n2. Explore more of the planet\n");
    scanf("%d", &randomNumber);
    
    if(randomNumber == 1) {
        if(playerGold >= 50) {
            playerGold -= 50;
            playerHealth += 25;
            printf("You have successfully bought a healing potion and restored 25 health points.\n");
            printf("Your health is now %d.\n", playerHealth);
        } else {
            printf("You don't have enough gold coins to buy a healing potion. Please explore more of the planet to earn more coins.\n");
        }
    } else {
        printf("You decide to explore more of the planet.\n");
    }
    
    printf("\nThank you for playing Procedural Space Adventure! Good luck on your journey!\n");
    
    return 0;
}