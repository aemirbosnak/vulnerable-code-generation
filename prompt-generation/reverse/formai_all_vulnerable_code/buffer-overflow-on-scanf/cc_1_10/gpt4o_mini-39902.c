//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void welcomeMessage() {
    printf("================================\n");
    printf("          Dice Roller          \n");
    printf("================================\n");
    printf("Welcome to the tranquil world of dice rolling.\n");
    printf("May your rolls be ever in your favor!\n\n");
}

void displayInstructions() {
    printf("Instructions:\n");
    printf("1. Enter the number of dice you wish to roll.\n");
    printf("2. Choose the type of dice (6-sided, 10-sided, etc.).\n");
    printf("3. Enjoy the roll results peacefully.\n");
    printf("================================\n");
}

int rollDice(int sides) {
    return (rand() % sides) + 1;
}

void rollMultipleDice(int number, int sides) {
    printf("Rolling %d %d-sided dice...\n", number, sides);
    int total = 0;

    for (int i = 0; i < number; i++) {
        int roll = rollDice(sides);
        total += roll;
        printf("Roll %d: %d\n", i + 1, roll);
    }

    printf("Total of rolls: %d\n", total);
}

void thankYouMessage() {
    printf("\nThank you for enjoying a peaceful dice-rolling experience!\n");
    printf("May your journey be filled with serenity.\n");
    printf("================================\n");
}

int main() {
    int numberOfDice;
    int sides;

    srand(time(NULL)); // Seed the random number generator with the current time

    welcomeMessage();

    displayInstructions();

    // Get user input for the number of dice
    printf("Enter the number of dice to roll: ");
    scanf("%d", &numberOfDice);

    // Validate the input for number of dice
    if (numberOfDice < 1) {
        printf("Please enter a positive number of dice to roll.\n");
        return 1;
    }

    // Get user input for the type of dice
    printf("Enter the number of sides for the dice (e.g., 6, 10, 20): ");
    scanf("%d", &sides);

    // Validate the input for sides of the dice
    if (sides < 2) {
        printf("Please enter a valid number of sides (at least 2).\n");
        return 1;
    }

    rollMultipleDice(numberOfDice, sides);

    thankYouMessage();

    return 0;
}