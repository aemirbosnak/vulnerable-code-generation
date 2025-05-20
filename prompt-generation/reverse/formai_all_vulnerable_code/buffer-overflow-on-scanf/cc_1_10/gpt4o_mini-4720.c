//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void displayWelcomeMessage();
int rollDice(int sides);
void displayRollResults(int roll, int sides);
void askToRollAgain();
void thankUser();

int main() {
    // Seed the random number generator
    srand((unsigned int)time(NULL));
    
    displayWelcomeMessage();
    
    int roll, sides = 6; // Default dice is a 6-sided die
    char response;

    do {
        roll = rollDice(sides);
        displayRollResults(roll, sides);
        askToRollAgain();
        scanf(" %c", &response);
    } while (response == 'y' || response == 'Y');
    
    thankUser();

    return 0;
}

// Function to display a welcome message
void displayWelcomeMessage() {
    printf("====================================\n");
    printf("           Welcome to Dice Roller!\n");
    printf("====================================\n");
    printf("Ready to roll some dice? Let's get started!\n\n");
}

// Function to roll a dice with given sides
int rollDice(int sides) {
    return (rand() % sides) + 1; // Generates a random number between 1 and 'sides'
}

// Function to display the result of the roll
void displayRollResults(int roll, int sides) {
    printf("You rolled a %d on a %d-sided die.\n", roll, sides);
    printf("====================================\n");
}

// Function to ask the user if they want to roll again
void askToRollAgain() {
    printf("Would you like to roll again? (y/n): ");
}

// Function to thank the user for using the program
void thankUser() {
    printf("Thank you for using the Dice Roller! Have a great day!\n");
    printf("====================================\n");
}