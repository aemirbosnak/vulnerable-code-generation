//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    // Variables for game logic
    int playerHealth = 100;
    int ghostHealth = 50;
    int foundKey = 0;
    int isPlaying = 1;
    int escape = 0;
    int playerChoice;
    
    // Seed random number generator
    srand(time(0));
    
    // Introduction
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You have entered a haunted house and are being pursued by a ghost.\n");
    printf("Your objective is to find the key to the front door and escape before the ghost catches you.\n");
    printf("You have 100 health points. The ghost has 50 health points.\n");
    
    // Game loop
    while(isPlaying){
        printf("\n");
        printf("Current health: %d\n", playerHealth);
        printf("Current ghost health: %d\n", ghostHealth);
        printf("\n");
        printf("Choose what to do next:\n");
        printf("1. Search for the key\n");
        printf("2. Hide\n");
        printf("3. Fight the ghost\n");
        printf("4. Attempt to escape\n");
        scanf("%d", &playerChoice);
        
        // Player chooses to search for key
        if(playerChoice == 1){
            printf("You search the room...\n");
            int keyChance = rand() % 100;
            if(keyChance < 50){
                printf("You found the key!\n");
                foundKey = 1;
            } else {
                printf("You did not find the key.\n");
            }
        }
        
        // Player chooses to hide
        if(playerChoice == 2){
            printf("You hide under the bed...\n");
            int ghostChance = rand() % 100;
            if(ghostChance < 25){
                printf("The ghost found you and attacks!\n");
                playerHealth -= 25;
            } else {
                printf("The ghost did not find you.\n");
            }
        }
        
        // Player chooses to fight the ghost
        if(playerChoice == 3){
            printf("You try to fight the ghost...\n");
            int ghostChance = rand() % 100;
            if(ghostChance < 50){
                printf("You hit the ghost and it takes 10 damage!\n");
                ghostHealth -= 10;
                if(ghostHealth <= 0){
                    printf("You defeated the ghost!\n");
                    isPlaying = 0;
                }
            } else {
                printf("The ghost dodges your attack.\n");
            }
        }
        
        // Player chooses to attempt escape
        if(playerChoice == 4){
            printf("You try to escape...\n");
            if(foundKey){
                int escapeChance = rand() % 100;
                if(escapeChance < 75){
                    printf("You successfully escaped! Congratulations!\n");
                    isPlaying = 0;
                    escape = 1;
                } else {
                    printf("You couldn't escape. The ghost catches up and attacks!\n");
                    playerHealth -= 25;
                }
            } else {
                printf("You need to find the key first!\n");
            }
        }
        
        // Check if player has lost
        if(playerHealth <= 0){
            printf("You have died. Game over.\n");
            isPlaying = 0;
        }
        
        // Check if player has won
        if(escape){
            printf("You have won the game!\n");
            isPlaying = 0;
        }
    }
    
    return 0;
}