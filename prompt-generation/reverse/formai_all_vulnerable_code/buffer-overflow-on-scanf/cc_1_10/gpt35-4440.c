//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to get user input as integer
int getIntegerInput() {
    int choice;
    scanf("%d", &choice);
    while(getchar() != '\n');
    return choice;
}

int main() {

    // Set the random seed using current time
    srand(time(NULL));
    
    // Player stats
    int playerHealth = 100;
    int playerGold = 0;
    int playerLevel = 1;
    int playerExperience = 0;

    // Introductory message and character creation
    printf("Welcome to the Adventure Game! \n");
    printf("Can you please enter your name? ");
    char playerName[20];
    fgets(playerName, 20, stdin);
    playerName[strcspn(playerName, "\n")] = '\0'; // Remove newline character from input
    printf("\nWelcome, %s! Let's begin your adventure.\n", playerName);
    printf("You find yourself in a dimly lit room with a door on your left and right.\n");
 
    // Game loop
    while(playerHealth > 0) {

        // Randomly generate a monster
        int monsterHealth = rand() % 50 + 50;
        int monsterGold = rand() % 10 + 5;
        int monsterExperience = rand() % 50 + 20;
        int monsterAttack = rand() % 10 + 5;

        // Room options
        printf("\nWhat would you like to do?\n");
        printf("1. Go left and fight the monster\n");
        printf("2. Go right and search for treasure\n");
        printf("3. Check player stats\n");
        printf("4. Exit game\n");

        // Get user choice
        printf("Enter your choice (1-4): ");
        int choice = getIntegerInput();

        // Handle user choice
        switch(choice) {
            case 1: // Fight the monster
                printf("\nYou encounter a scary monster with %d health!\n", monsterHealth);

                while(monsterHealth > 0) {
                    // Player attacks first
                    printf("\nYou attack the monster and cause %d damage!\n", playerLevel * 10);
                    monsterHealth -= playerLevel * 10;
                    if(monsterHealth <= 0) break;

                    // Monster attacks back
                    printf("The monster attacks you and causes %d damage!\n", monsterAttack);
                    playerHealth -= monsterAttack;

                    // Check if player is dead
                    if(playerHealth <= 0) {
                        printf("\nOh no, you have died! Game over.\n");
                        return 0;
                    }
                }

                // Player wins
                printf("\nCongratulations, you have defeated the monster and earned %d gold and %d experience!\n", monsterGold, monsterExperience);
                playerGold += monsterGold;
                playerExperience += monsterExperience;
                if(playerExperience >= playerLevel * 50) {
                    playerLevel++;
                    printf("Congratulations, you have advanced to level %d!\n", playerLevel);
                    playerExperience = 0;
                }
                break;

            case 2: // Search for treasure
                printf("\nYou find a chest containing %d gold!\n", playerLevel * 5);
                playerGold += playerLevel * 5;
                break;

            case 3: // Display player stats
                printf("\nPlayer name: %s\n", playerName);
                printf("Player health: %d\n", playerHealth);
                printf("Player gold: %d\n", playerGold);
                printf("Player level: %d\n", playerLevel);
                printf("Player experience: %d/%d\n", playerExperience, playerLevel * 50);
                break;

            case 4: // Exit game
                printf("\nGoodbye, %s! Thanks for playing.\n", playerName);
                exit(0);
                break;

            default: // Invalid choice
                printf("\nSorry, that is an invalid choice. Please try again.\n");
                break;
        }

    }

    return 0;
}