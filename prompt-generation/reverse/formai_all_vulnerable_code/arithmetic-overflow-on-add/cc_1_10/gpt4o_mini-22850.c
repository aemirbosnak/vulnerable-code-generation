//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll a single die
int rollDie(int sides) {
    return (rand() % sides) + 1; // Returns a number between 1 and sides
}

// Function to display the results of the rolls
void displayResults(int rolls[], int count) {
    printf("\n🎲🎲 Dice Roll Results 🎲🎲\n");
    for (int i = 0; i < count; i++) {
        printf("Roll %d: %d\n", i + 1, rolls[i]);
    }
    printf("\nTotal: %d\n", sumRolls(rolls, count));
}

// Function to calculate the sum of all rolls
int sumRolls(int rolls[], int count) {
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += rolls[i];
    }
    return sum;
}

// Function to play the dice rolling game
void playDiceGame() {
    int numDice, sides, i;
    printf("Welcome to the Ultimate Dice Roller Game! 🎉\n");
    printf("How many dice would you like to roll? ");
    scanf("%d", &numDice);
    printf("How many sides does each die have? ");
    scanf("%d", &sides);

    int rolls[numDice]; // Array to store the results of each roll

    printf("Rolling %d dice with %d sides...\n", numDice, sides);

    for (i = 0; i < numDice; i++) {
        rolls[i] = rollDie(sides);
        printf("Die %d rolled a %d! 🎲\n", i + 1, rolls[i]);
    }

    displayResults(rolls, numDice); // Display all results
}

// Function to display the menu
void displayMenu() {
    printf("\n=====================\n");
    printf("🎲 DICE ROLLER MENU 🎲\n");
    printf("=====================\n");
    printf("1. Roll Dice\n");
    printf("2. Exit\n");
    printf("=====================\n");
    printf("Select an option: ");
}

int main() {
    srand(time(NULL)); // Seeding the random number generator
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                playDiceGame();
                break;
            case 2:
                printf("Thank you for playing! 🎉 Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}