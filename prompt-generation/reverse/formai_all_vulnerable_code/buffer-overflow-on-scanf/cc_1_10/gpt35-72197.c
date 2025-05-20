//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: calm
#include <stdio.h>
#include <string.h>

#define MAX_LEN 50

char playerName[MAX_LEN]; // To store the player's name
char playerClass[MAX_LEN]; // To store the player's class
int playerHealth = 100; // To store the player's health
int monsterHealth = 100; // To store the monster's health

void clearScreen() {
    // This function clears the screen
    printf("\e[1;1H\e[2J");
}

void intro() {
    // This function displays the intro to the game
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("Please enter your name: ");
    scanf("%s", playerName);
    printf("Please choose a class (Warrior/Mage/Rogue): ");
    scanf("%s", playerClass);
    printf("\nHello %s the %s! \n\n", playerName, playerClass);
    printf("You find yourself in a dark and eerie cave. As you make your way deeper into the cave, you hear the sound of approaching footsteps.\n\n");
}

void battle() {
    // This function handles the battle sequence
    int choice;
    clearScreen();
    printf("You have encountered a monster!\n\n");
    while(playerHealth > 0 && monsterHealth > 0) {
        printf("Your Health: %d\n", playerHealth);
        printf("Monster's Health: %d\n\n", monsterHealth);
        printf("1. Attack\n");
        printf("2. Defend\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if(choice == 1){
            // Player attacks the monster
            int playerAttack = 10;
            int monsterAttack = 5;
            printf("\nYou attack the monster and deal %d damage!\n", playerAttack);
            monsterHealth -= playerAttack;
            if(monsterHealth <= 0) {
                // Player wins the battle
                printf("\nYou have defeated the monster!\n");
                return;
            }
            printf("\nThe monster counterattacks and deals %d damage! \n", monsterAttack);
            playerHealth -= monsterAttack;
        } else if(choice == 2) {
            // Player defends against the monster's attack
            int monsterAttack = 1;
            printf("\nYou defend yourself and take no damage!\n");
            printf("\nThe monster counterattacks and deals %d damage! \n", monsterAttack);
            playerHealth -= monsterAttack;
        } else {
            // Invalid choice
            printf("\nInvalid choice, try again!\n");
        }
    }
    if(playerHealth <= 0) {
        // Player loses the battle
        printf("\nYou have been defeated by the monster!\n");
    }
}

int main() {
    // Main function to run the game
    intro();
    char choice;
    do {
        battle();
        printf("\nDo you want to play again? (Y/N): ");
        scanf(" %c", &choice);
        if(choice == 'Y' || choice == 'y') {
            // Reset health values for a new game
            playerHealth = 100;
            monsterHealth = 100;
        }
    } while(choice == 'Y' || choice == 'y');
    printf("\nThanks for playing!\n");
    return 0;
}