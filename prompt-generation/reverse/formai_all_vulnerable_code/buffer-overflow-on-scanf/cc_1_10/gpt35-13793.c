//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global Variables
char playerName[20];
int playerAge;
int playerScore = 0;
int playerHealth = 100;
int playerLocation = 0;

// Function Prototypes
void startGame();
int getMenuChoice();
void displayMenu();
void exploreForest();
void fightMonster();
void endGame();

// Asynchronous function
void delay(int seconds) {
    int microSeconds = 1000000 * seconds;
    usleep(microSeconds);
}

// Main Function
int main() {
    startGame();
    int choice;
    do {
        displayMenu();
        choice = getMenuChoice();
        switch (choice) {
            case 1: exploreForest(); break;
            case 2: fightMonster(); break;
            case 3: endGame(); break;
            default: printf("Invalid Choice! Please Try Again.\n\n");
        }
    } while (choice != 3);
    return 0;
}

// Function definitions
void startGame() {
    printf("Welcome to Adventure Game!\n\n");
    printf("Enter your Name: ");
    scanf("%s", playerName);
    printf("Enter your Age: ");
    scanf("%d", &playerAge);
    printf("\n");
    printf("Hello, %s! You are %d years old.\n", playerName, playerAge);
    printf("Your adventure begins!\n\n");
    delay(2); // Delay for 2 seconds
}

int getMenuChoice() {
    int choice;
    printf("Enter choice (1-3): ");
    scanf("%d", &choice);
    printf("\n");
    return choice;
}

void displayMenu() {
    printf("MENU:\n");
    printf("1. Explore Forest\n");
    printf("2. Fight Monster\n");
    printf("3. End Game\n");
}

void exploreForest() {
    printf("You are exploring the forest...\n");
    playerScore += 10;
    playerLocation = 1;
    printf("You have found a treasure chest! +10 score\n\n");
}

void fightMonster() {
    printf("You have encountered a monster!\n");
    delay(1); // Delay for 1 second
    printf("You have %d health remaining.\n", playerHealth);
    delay(1); // Delay for 1 second
    printf("You attack the monster...\n");
    delay(2); // Delay for 2 seconds
    int attackScore = rand() % 20 + 1;
    if (attackScore > 10) {
        printf("You have defeated the monster! +20 score\n\n");
        playerHealth -= 20;
        playerScore += 20;
    } else {
        printf("You were defeated by the monster! -20 score\n\n");
        playerHealth -= 50;
        playerScore -= 20;
    }
    if (playerHealth <= 0) {
        printf("Game Over! You have died.\n");
        endGame();
    }
}

void endGame() {
    printf("Thank you for playing, %s! Your final score is %d.\n", playerName, playerScore);
}