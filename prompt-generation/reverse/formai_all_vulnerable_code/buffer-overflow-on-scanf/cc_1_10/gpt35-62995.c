//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: standalone
#include <stdio.h>
#include <string.h>

int main() {
    char playerName[20];
    int playerScore = 0;
    
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("Please enter your name: ");
    scanf("%s", playerName);
    printf("Hello, %s! Let's start the game!\n", playerName);
    
    // Introduction
    printf("\nYou find yourself in a mysterious forest.\n");
    printf("There are two paths in front of you, one leads left and another right.\n");
    printf("Which path do you choose?\n");
    
    // Player's first choice
    char firstChoice[10];
    scanf("%s", firstChoice);
    if (strcmp(firstChoice, "left") == 0) {
        printf("\nYou chose the left path.\n");
        printf("You stumbled upon a treasure chest!\n");
        printf("Do you open the chest? (yes or no)\n");
        
        // Player's second choice
        char secondChoice[10];
        scanf("%s", secondChoice);
        if (strcmp(secondChoice, "yes") == 0) {
            printf("\nCongratulations! The chest was full of treasure!\n");
            playerScore += 100;
        } else {
            printf("\nYou decided not to take the risk.\n");
        }
    } else {
        printf("\nYou chose the right path.\n");
        printf("You hear a strange noise from the distance.\n");
        printf("Do you investigate the noise? (yes or no)\n");
        
        // Player's second choice
        char secondChoice[10];
        scanf("%s", secondChoice);
        if (strcmp(secondChoice, "yes") == 0) {
            printf("\nYou found a magical portal and activated it!\n");
            printf("You were teleported to another dimension.\n");
            printf("Your journey continues...\n");
            playerScore += 200;
        } else {
            printf("\nYou decided not to take the risk.\n");
        }
    }
    
    // End of game
    printf("\n----- GAME OVER -----\n");
    printf("Congratulations, %s!\n", playerName);
    printf("Your final score is: %d\n", playerScore);
    printf("Thank you for playing!\n");
    
    return 0;
}