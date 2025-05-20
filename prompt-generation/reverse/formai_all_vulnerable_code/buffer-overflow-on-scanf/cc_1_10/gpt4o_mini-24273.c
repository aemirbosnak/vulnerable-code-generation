//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Function prototypes
void welcome();
void forestPath();
void encounterCreature();
void choosePath();
void displayOutcome(bool victory);

int main() {
    srand(time(NULL)); // Seed the random number generator
    welcome();          // Display welcome message
    forestPath();      // Start the forest adventure
    return 0;
}

// Function to welcome the player
void welcome() {
    printf("Welcome to the Mysterious Forest Adventure!\n");
    printf("In this game, you will explore a forest filled with unexpected encounters.\n");
    printf("Choose your path wisely, and may luck be on your side!\n\n");
}

// Function to navigate through the forest
void forestPath() {
    printf("You find yourself at the edge of a dark forest.\n");
    printf("Do you want to enter the forest? (y/n): ");
    
    char choice;
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        choosePath();
    } else {
        printf("You chose to stay away from the forest. Maybe next time!\n");
    }
}

// Function to choose a path in the forest
void choosePath() {
    printf("\nYou step into the forest, and you see two paths in front of you:\n");
    printf("1. The left path, shrouded in fog.\n");
    printf("2. The right path, with bright flowers.\n");
    
    int path;
    printf("Which path do you want to take? (1/2): ");
    scanf("%d", &path);

    if (path == 1) {
        printf("\nYou take the left path and find yourself surrounded by fog.\n");
        encounterCreature();
    } else if (path == 2) {
        printf("\nYou take the right path and enjoy the beauty of the flowers.\n");
        encounterCreature();
    } else {
        printf("That's not a valid choice. You hesitate and get lost in the forest!\n");
    }
}

// Function to simulate an encounter with a creature
void encounterCreature() {
    printf("Suddenly, a creature appears!\n");
    printf("It's a wild beast, and you have two choices:\n");
    printf("1. Fight the beast.\n");
    printf("2. Attempt to scare it away.\n");
    
    int action;
    printf("What will you do? (1/2): ");
    scanf("%d", &action);

    bool victory = false;
    if (action == 1) {
        victory = rand() % 2; // 50% chance to win
        printf(victory ? "You bravely fight the beast and win!\n" : "You fought bravely, but the beast overpowers you.\n");
    } else if (action == 2) {
        victory = rand() % 2; // 50% chance to win
        printf(victory ? "You successfully scare the beast away!\n" : "Unfortunately, the beast isn't scared and charges at you!\n");
    } else {
        printf("You hesitate and miss your chance!\n");
    }

    displayOutcome(victory);
}

// Function to display the outcome of the player's choice
void displayOutcome(bool victory) {
    if (victory) {
        printf("Congratulations! You've survived the encounter and can continue your adventure!\n");
    } else {
        printf("Game Over! You didn't make it out of the forest.\n");
    }

    printf("Do you want to play again? (y/n): ");
    char playAgain;
    scanf(" %c", &playAgain);
    
    if (playAgain == 'y' || playAgain == 'Y') {
        main(); // Restart the game
    } else {
        printf("Thank you for playing! Goodbye!\n");
    }
}