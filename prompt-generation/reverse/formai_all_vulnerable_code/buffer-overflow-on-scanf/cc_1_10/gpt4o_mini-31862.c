//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printWelcomeMessage() {
    printf("🎲 Welcome to the Happy Dice Roller! 🎲\n");
    printf("Let's roll some dice and have some fun! 😊\n\n");
}

void printGoodbyeMessage() {
    printf("\n🎉 Thank you for playing! Goodbye! 🎉\n");
}

int rollDice(int sides) {
    return (rand() % sides) + 1; // Returns a value between 1 and the number of sides
}

void rollMultipleDice(int numberOfDice, int sides) {
    printf("\nRolling %d D%d...\n", numberOfDice, sides);
    for (int i = 0; i < numberOfDice; i++) {
        int roll = rollDice(sides);
        printf("Roll %d: 🎲 %d 🎲\n", i + 1, roll);
    }
}

int getInput(const char *prompt) {
    int value;
    printf("%s", prompt);
    while (scanf("%d", &value) != 1 || value <= 0) {
        printf("Oops! Please enter a positive integer. Try again: ");
        while (getchar() != '\n'); // Clear newline from input buffer
    }
    return value;
}

int main() {
    srand(time(NULL)); // Seed for random number generation

    printWelcomeMessage();

    while (1) {
        // Get number of dice
        int numberOfDice = getInput("How many dice would you like to roll? ");
        
        // Get sides of the dice
        int sides = getInput("How many sides does each die have? (e.g., 6, 10, 20) ");

        rollMultipleDice(numberOfDice, sides);

        // Ask the user if they want to roll again
        char choice;
        printf("\nDo you want to roll again? (y/n): ");
        while (getchar() != '\n'); // Clear newline from input buffer
        scanf("%c", &choice);

        if (choice != 'y' && choice != 'Y') {
            break; // Exit the loop if user doesn't want to continue
        }
    }

    printGoodbyeMessage();
    return 0;
}