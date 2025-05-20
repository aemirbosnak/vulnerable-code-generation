//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(0)); //set random seed
    const int maxHealth = 100; //maximum health of player
    int playerHealth = maxHealth; //initial health of player
    int enemyHealth = rand() % (maxHealth/2) + maxHealth/2; //enemy's initial health

    printf("Welcome to Cyber Battle!\n");
    printf("You are a hacker who has been caught by the government.\n");
    printf("You must fight your way out of their servers in order to escape.\n\n");
    
    while (playerHealth > 0 && enemyHealth > 0){ //keep playing until either player or enemy's health reaches 0
        int playerDamage = rand() % (maxHealth/2); //randomly generate player's damage
        int enemyDamage = rand() % (maxHealth/2); //randomly generate enemy's damage
        
        printf("Your health: %d\n", playerHealth);
        printf("Enemy's health: %d\n\n", enemyHealth);
        printf("Choose your move:\n");
        printf("1. Attack\n");
        printf("2. Defend\n");
        
        int choice;
        scanf("%d", &choice); //get user's choice
        
        switch (choice){
            case 1: //user chose to attack
                printf("You attacked the enemy and dealt %d damage.\n", playerDamage);
                enemyHealth -= playerDamage;
                break;
                
            case 2: //user chose to defend
                printf("You defended yourself.\n");
                break;
                
            default: //invalid input
                printf("Invalid input.\n");
                continue;
        }
        
        if (enemyHealth <= 0) //enemy has been defeated
            break;
        
        printf("The enemy attacked you and dealt %d damage.\n", enemyDamage);
        playerHealth -= enemyDamage;
    }
    
    if (playerHealth <= 0){ //player has lost
        printf("Game over!\n");
        printf("You were caught by the government.\n");
    }
    else{ //player has won
        printf("Congratulations!\n");
        printf("You have successfully escaped from their servers.\n");
    }
    
    return 0;
}