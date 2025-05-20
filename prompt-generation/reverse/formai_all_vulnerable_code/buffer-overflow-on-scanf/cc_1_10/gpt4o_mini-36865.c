//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define maximum lengths for inputs
#define MAX_NAME_LENGTH 100
#define MAX_PASSWORD_LENGTH 100

// Function declarations
void initGame();
void inputPlayerInfo(char *name);
void displayMenu();
void playGame(char *name);
void checkSafety(int *health, int *safety);
void searchRoom(int *health);
int choiceDecision(int *health);
int encounterEnemy(int *health);
void showStatus(int health, int safety);
void endGame(int health);

int main() {
    char playerName[MAX_NAME_LENGTH];
    initGame();
    inputPlayerInfo(playerName);
    displayMenu();
    playGame(playerName);
    return 0;
}

// Initialize the game
void initGame() {
    printf("Initializing...\n");
    srand(time(NULL)); // Seed random number generator
}

// Input player's name
void inputPlayerInfo(char *name) {
    printf("Enter your name (max %d characters): ", MAX_NAME_LENGTH - 1);
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // Remove the newline character
    printf("Welcome, %s!\n", name);
}

// Display game menu
void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Start Game\n");
    printf("2. Exit\n");
    printf("Select an option: ");
}

// Main game loop
void playGame(char *name) {
    int health = 100;
    int safety = 100;
    int choice;

    printf("\nYou are in a deserted, creepy house filled with shadows and whispers.\n");

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nStarting game...\n");
            while (health > 0 && safety > 0) {
                checkSafety(&health, &safety);
                searchRoom(&health);
                showStatus(health, safety);
            }
            endGame(health);
            break; // End game after loop completion
        } else if (choice == 2) {
            printf("Exiting the game. Stay safe!\n");
            break;
        } else {
            printf("Invalid choice! Try again.\n");
        }
    }
}

// Check the player's safety status
void checkSafety(int *health, int *safety) {
    printf("You look around nervously. Your current health: %d, Safety Level: %d\n", *health, *safety);
    if (rand() % 10 < 3) { // 30% chance something strange happens
        printf("You feel a chill run down your spine!\n");
        *health -= 10;
    }
}

// Search the room
void searchRoom(int *health) {
    printf("\nYou search the room...\n");

    int result = rand() % 10;
    if (result < 4) {
        printf("You found a useful item!\n");
        *health += 10; // Found a health item
    } else if (result < 8) {
        printf("Nothing here...\n");
    } else {
        *health = encounterEnemy(health); // Encounter an enemy
    }
}

// Encounter an enemy
int encounterEnemy(int *health) {
    printf("An enemy appears! Fight or Run!\n");
    int action;
    printf("Enter 1 to Fight, 2 to Run: ");
    scanf("%d", &action);

    if (action == 1) {
        printf("You chose to fight!\n");
        int fightOutcome = rand() % 2;
        if (fightOutcome == 0) {
            printf("You defeated the enemy!\n");
        } else {
            printf("You were injured in the fight!\n");
            *health -= 30; // Lose health
        }
    } else {
        printf("You ran away safely.\n");
    }

    return *health;
}

// Show current status of player
void showStatus(int health, int safety) {
    printf("\nCurrent Status:\n");
    printf("Health: %d, Safety: %d\n", health, safety);
}

// End the game and show result
void endGame(int health) {
    if (health <= 0) {
        printf("You have succumbed to the dangers of the house...\nGame Over!\n");
    } else {
        printf("Congratulations! You survived the creepy house...\n");
    }
}