//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/* Function declarations */
void displayIntro();
void displayTitle();
void displayMap();
void gameOver();
void printHelp();
void exploreRoom();
void movePlayer();
void inventory();

/* Global variables */
char decision[10];
char action[10];
char item[30];
char playerName[20];
int playerHealth = 100;
int playerGold = 0;
int currentPosition = 0;
int roomCount = 10;
int roomVisited[10] = {0,0,0,0,0,0,0,0,0,0};

/* Main Function */
int main()
{
    displayIntro();
    displayTitle();

    while (strcmp(action, "quit") != 0 && playerHealth > 0 && currentPosition < roomCount) {
        displayMap();
        exploreRoom();
        movePlayer();
    }

    gameOver();
    return 0;
}

/* Functions */

// Introduction function
void displayIntro() {
    printf("\n\nWelcome to the Medieval Adventure Game!\n");
    printf("In this game, you will explore a world of castles, dragons, and magic!\n");
    printf("What is your name, brave adventurer? ");
    scanf("%s", playerName);
}

// Title function
void displayTitle() {
    printf("\n\nYou are now entering the world of Medieval Adventure Game!\n\n");
}

// Map function
void displayMap() {
    printf("\n\nYou are in Room %d\n", currentPosition + 1);
    printf("Where would you like to go next?\n");
    printf("You may move north, south, east, or west.\n");
    printf("Enter 'help' to see a list of available commands.\n");
}

// Game over function
void gameOver() {
    if (playerHealth <= 0) {
        printf("\n\nSorry, %s, you have died.\n", playerName);
    } else if (currentPosition == roomCount) {
        printf("\n\nCongratulations, %s, you have completed the game!\n", playerName);
    }
}

// Help function
void printHelp() {
    printf("\n\nAvailable commands:\n");
    printf("north\n");
    printf("south\n");
    printf("east\n");
    printf("west\n");
    printf("inventory\n");
    printf("quit\n");
}

// Explore room function
void exploreRoom() {
    if (roomVisited[currentPosition] == 0) {
        printf("\n\nYou enter Room %d for the first time.\n", currentPosition + 1);
        printf("This room seems to be empty.\n");
        roomVisited[currentPosition] = 1;

        // Random chance to find gold
        int chance = rand() % 10;
        if (chance < 3) {
            printf("\n\nYou found 10 gold coins!\n");
            playerGold += 10;
        }
    } else {
        printf("\n\nYou enter Room %d again.\n", currentPosition + 1);
        printf("There is nothing here.\n");
    }
}

// Move player function
void movePlayer() {
    printf("\n\nWhat do you want to do? ");
    scanf("%s", decision);

    // Lowercase the decision for easier comparison
    for (int i = 0; i < strlen(decision); i++) {
        decision[i] = tolower(decision[i]);
    }

    // Compare decision to corresponding action
    if (strcmp(decision, "north") == 0) {
        if (currentPosition >= 3) {
            currentPosition -= 3;
        } else {
            printf("\n\nYou cannot go further north.\n");
        }
    } else if (strcmp(decision, "south") == 0) {
        if (currentPosition < 6) {
            currentPosition += 3;
        } else {
            printf("\n\nYou cannot go further south.\n");
        }
    } else if (strcmp(decision, "west") == 0) {
        if (currentPosition % 3 != 0) {
            currentPosition -= 1;
        } else {
            printf("\n\nYou cannot go further west.\n");
        }
    } else if (strcmp(decision, "east") == 0) {
        if ((currentPosition + 1) % 3 != 0) {
            currentPosition += 1;
        } else {
            printf("\n\nYou cannot go further east.\n");
        }
    } else if (strcmp(decision, "inventory") == 0) {
        inventory();
    } else if (strcmp(decision, "help") == 0) {
        printHelp();
    } else if (strcmp(decision, "quit") == 0) {
        printf("\n\nGoodbye, %s.\n", playerName);
    } else {
        printf("\n\nI'm sorry, I don't understand.\n");
    }
}

// Inventory function
void inventory() {
    printf("\n\nYou currently have %d gold coins.\n", playerGold);
    printf("You are currently carrying nothing.\n");
}