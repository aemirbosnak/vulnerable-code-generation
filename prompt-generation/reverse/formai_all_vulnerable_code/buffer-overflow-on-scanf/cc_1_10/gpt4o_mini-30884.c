//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 10
#define MAX_SIDES 100

// Function prototypes
void rollDice(int numDice, int numSides);
void displayStatistics(int rolls[], int totalRolls, int numSides);

int main() {
    int numDice = 0, numSides = 0;
    
    // Seed the random number generator
    srand(time(NULL));

    printf("Welcome to the C Dice Roller!\n");
    printf("You can roll up to %d dice, each having up to %d sides.\n\n", MAX_DICE, MAX_SIDES);

    // Input loop for number of dice
    while (numDice <= 0 || numDice > MAX_DICE) {
        printf("Enter the number of dice to roll (1 - %d): ", MAX_DICE);
        scanf("%d", &numDice);
        if (numDice <= 0 || numDice > MAX_DICE) {
            printf("Invalid input. Please try again.\n");
        }
    }

    // Input loop for number of sides
    while (numSides <= 0 || numSides > MAX_SIDES) {
        printf("Enter the number of sides on each die (1 - %d): ", MAX_SIDES);
        scanf("%d", &numSides);
        if (numSides <= 0 || numSides > MAX_SIDES) {
            printf("Invalid input. Please try again.\n");
        }
    }

    // Roll the dice
    rollDice(numDice, numSides);

    return 0;
}

void rollDice(int numDice, int numSides) {
    int i, totalRolls = 0;
    int rolls[MAX_DICE];

    printf("\nRolling %d dice with %d sides...\n", numDice, numSides);

    // Rolling the dice
    for (i = 0; i < numDice; i++) {
        rolls[i] = (rand() % numSides) + 1; // Generate a roll between 1 and numSides
        totalRolls += rolls[i];
        printf("Roll %d: %d\n", i + 1, rolls[i]);
    }

    // Display the statistics
    displayStatistics(rolls, totalRolls, numSides);
}

void displayStatistics(int rolls[], int totalRolls, int numSides) {
    int frequency[MAX_SIDES + 1] = {0}; // Frequency array to hold the number of occurrences for each side
    int i;

    // Calculate frequency of each roll
    for (i = 0; i < MAX_DICE; i++) {
        if (rolls[i] > 0) {
            frequency[rolls[i]]++;
        }
    }

    // Display the total of all rolls
    printf("\nTotal of all rolls: %d\n", totalRolls);

    // Display the frequency of each side rolled
    printf("Frequency of each side rolled:\n");
    for (i = 1; i <= numSides; i++) {
        if (frequency[i] > 0) {
            printf("Side %d: %d times\n", i, frequency[i]);
        }
    }
    
    printf("\nThank you for using the C Dice Roller!\n");
}