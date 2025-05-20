//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 10

// Function prototypes
void displayMenu();
int rollDice(int sides);
void playDiceGame();
void displayResults(int *rolls, int numRolls);
void summarizeRolls(int *rolls, int numRolls);

int main() {
    srand(time(NULL)); // Seed for random number generation
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                playDiceGame();
                break;
            case 2:
                printf("Thank you for playing! Have a great day!\n");
                exit(0);
            default:
                printf("Invalid selection. Please try again.\n");
        }
    }

    return 0;
}

// Function to display the menu
void displayMenu() {
    printf("\n=================================\n");
    printf("           Dice Roller          \n");
    printf("=================================\n");
    printf("1. Roll the dice\n");
    printf("2. Exit\n");
    printf("=================================\n");
}

// Function to roll a dice with a given number of sides
int rollDice(int sides) {
    return (rand() % sides) + 1;
}

// Function to manage the dice rolling game
void playDiceGame() {
    int numDice, sides;
    int rolls[MAX_DICE] = {0};

    printf("Welcome to the Dice Rolling Game!\n");
    printf("How many dice would you like to roll? (1-%d): ", MAX_DICE);
    scanf("%d", &numDice);
    
    // Input validation for number of dice
    if (numDice < 1 || numDice > MAX_DICE) {
        printf("Error: You must roll between 1 and %d dice!\n", MAX_DICE);
        return;
    }

    printf("How many sides do you want on each dice? (e.g. 4, 6, 8, 10, 12, 20): ");
    scanf("%d", &sides);

    // Input validation for number of sides
    if (sides < 4) {
        printf("Error: The dice must have at least 4 sides!\n");
        return;
    }

    printf("Rolling %d dice with %d sides...\n", numDice, sides);
    
    // Rolling the dice and storing the results
    for (int i = 0; i < numDice; i++) {
        rolls[i] = rollDice(sides);
        printf("Roll %d: %d\n", i + 1, rolls[i]);
    }

    // Display results
    displayResults(rolls, numDice);
}

// Function to display the results of the rolls
void displayResults(int *rolls, int numRolls) {
    printf("\n=========================\n");
    printf("      Roll Results       \n");
    printf("=========================\n");
    for (int i = 0; i < numRolls; i++) {
        printf("Roll %d: %d\n", i + 1, rolls[i]);
    }
    printf("=========================\n");

    summarizeRolls(rolls, numRolls);
}

// Function to summarize the rolls performed
void summarizeRolls(int *rolls, int numRolls) {
    int sum = 0;
    
    for (int i = 0; i < numRolls; i++) {
        sum += rolls[i];
    }

    printf("Total of all rolls: %d\n", sum);
    
    // Finding the highest and lowest roll
    int highest = rolls[0];
    int lowest = rolls[0];
    
    for (int i = 1; i < numRolls; i++) {
        if (rolls[i] > highest) highest = rolls[i];
        if (rolls[i] < lowest) lowest = rolls[i];
    }

    printf("Highest roll: %d\n", highest);
    printf("Lowest roll: %d\n", lowest);
}