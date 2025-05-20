//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void displayWelcomeMessage();
void rollDice(int *dice1, int *dice2);
void displayResults(int dice1, int dice2, int total);
void exitMessage();

int main() {
    // Seed the random number generator
    srand(time(0));
    
    // Variable initialization
    int dice1, dice2;
    char choice;

    // Display the welcome message
    displayWelcomeMessage();

    // Keep rolling the dice until the user decides to exit
    do {
        rollDice(&dice1, &dice2);
        int total = dice1 + dice2;
        displayResults(dice1, dice2, total);

        // Prompt the user for the next action
        printf("Do you want to roll again? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    // Display the exit message
    exitMessage();

    return 0;
}

// Function to display welcome message
void displayWelcomeMessage() {
    printf("====================================\n");
    printf("          Welcome to the Dice       \n");
    printf("            Roller Program!         \n");
    printf("====================================\n");
    printf("Instructions: You will roll two 6-sided dice.\n");
    printf("The results will be displayed along with the total.\n");
    printf("Press 'y' to roll again or 'n' to exit.\n");
    printf("====================================\n");
}

// Function to roll the dice
void rollDice(int *dice1, int *dice2) {
    *dice1 = (rand() % 6) + 1; // Dice 1 roll
    *dice2 = (rand() % 6) + 1; // Dice 2 roll
}

// Function to display the results of the rolls
void displayResults(int dice1, int dice2, int total) {
    printf("You rolled: %d and %d.\n", dice1, dice2);
    printf("Total: %d\n", total);
}

// Function to display exit message
void exitMessage() {
    printf("Thank you for playing!\n");
    printf("====================================\n");
    printf("  May your future rolls be ever in your favor!\n");
    printf("====================================\n");
}