//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll a dice and return the result
int rollDice() {
    return (rand() % 6) + 1; // Generates a number between 1 and 6
}

// Function to display the welcome message
void displayWelcomeMessage() {
    printf("==========================================\n");
    printf("     🎲 Welcome to the Cheerful Dice Roller! 🎲\n");
    printf("==========================================\n");
    printf("Ready to roll the dice? Let's have some fun! 🎉\n");
}

// Function to display the rolling instructions
void displayInstructions() {
    printf("To roll the dice, simply press 'r'.\n");
    printf("To exit the game, press 'q'.\n");
    printf("Let's see how lucky you can get! 🌟\n");
}

// Main function to handle the game loop
int main() {
    char choice;
    
    // Seed for random number generation
    srand(time(NULL));
    
    // Display welcome message and instructions
    displayWelcomeMessage();
    displayInstructions();
    
    do {
        // Prompt user for choice
        printf("\nYour choice: ");
        scanf(" %c", &choice); // Use whitespace to ignore preceding newlines

        if (choice == 'r') {
            // Roll the dice
            int result = rollDice();
            printf("🎲 You rolled a %d! 🎉\n", result);
        } else if (choice == 'q') {
            printf("Thank you for playing! 🎈 Have a great day! ☀️\n");
        } else {
            printf("Oops! That's not a valid choice. Try again! 😅\n");
        }

    } while (choice != 'q');

    return 0;
}