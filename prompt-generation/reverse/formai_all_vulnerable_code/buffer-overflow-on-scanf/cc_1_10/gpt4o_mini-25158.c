//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void displayInstructions();
int rollDice();
void askToRollAgain();
void handleRoll(int rollCount);

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Display instructions
    displayInstructions();

    // Start handling rolls
    handleRoll(0);

    return 0;
}

// Function to display instructions to the user
void displayInstructions() {
    printf("Welcome to the Recursive Dice Roller!\n");
    printf("This program will roll a 6-sided die for you.\n");
    printf("You can choose to roll again as many times as you like.\n");
    printf("Let's get started!\n\n");
}

// Function to roll a 6-sided die
int rollDice() {
    return (rand() % 6) + 1; // Returns a number between 1 and 6
}

// Function to ask the user if they want to roll again
void askToRollAgain() {
    char choice;

    // Prompt the user
    printf("Do you want to roll again? (y/n): ");
    scanf(" %c", &choice);

    // Check user input for rolling again
    if (choice == 'y' || choice == 'Y') {
        handleRoll(0); // Recursive call to roll again
    } else {
        printf("Thank you for using the Dice Roller! Goodbye!\n");
        exit(0); // Exit the program
    }
}

// Function to handle the rolling process
void handleRoll(int rollCount) {
    // Roll the dice
    int result = rollDice();
    
    // Output the result
    printf("Roll #%d: You rolled a %d!\n", rollCount + 1, result);

    // Increment the roll count
    rollCount++;
    
    // Ask user if they want to roll again
    askToRollAgain();
}