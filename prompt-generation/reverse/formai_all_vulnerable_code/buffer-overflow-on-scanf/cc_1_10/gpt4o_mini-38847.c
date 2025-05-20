//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
void rollDice(int diceCount, int sides);
void displayResults(int *results, int diceCount);
void simulateRolls(int rolls, int diceCount, int sides);

int main() {
    int diceCount, sides, rolls;
    
    // Seed the random number generator
    srand(time(NULL));

    // User input for number of dice, sides and rolls
    printf("Welcome to the Dice Roller Program!\n");
    printf("Enter the number of dice to roll: ");
    scanf("%d", &diceCount);
    printf("Enter the number of sides on each die: ");
    scanf("%d", &sides);
    printf("How many times do you want to roll the dice? ");
    scanf("%d", &rolls);

    // Simulate rolling the dice multiple times
    simulateRolls(rolls, diceCount, sides);

    return 0;
}

// Function to simulate rolling dice the specified number of times
void simulateRolls(int rolls, int diceCount, int sides) {
    int *results = (int *)malloc(diceCount * sizeof(int));
    
    if (results == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    printf("\nRolling the dice %d times...\n", rolls);
    
    for (int i = 0; i < rolls; i++) {
        rollDice(diceCount, sides);
        printf("Roll %d: ", i + 1);
        displayResults(results, diceCount);
    }
    
    free(results);
}

// Function to roll dice and store the results
void rollDice(int diceCount, int sides) {
    printf("Rolling %d dice with %d sides: ", diceCount, sides);
    
    for (int i = 0; i < diceCount; i++) {
        int roll = (rand() % sides) + 1; // Random roll between 1 and sides
        printf("%d ", roll);
    }
    
    printf("\n");
}

// Function to display the results of each roll
void displayResults(int *results, int diceCount) {
    for (int j = 0; j < diceCount; j++) {
        printf("%d ", results[j]);
    }
    printf("\n");
}

// Example additional function for analyzing rolls statistics
void analyzeRollsStatistics(int rolls, int totalRolls) {
    printf("\nAnalyzing Statistics...\n");
    // You can implement logic here to analyze outcomes, e.g. count occurrences
}

// Function to validate user inputs
int validateInput(int input, int min, int max) {
    if (input < min || input > max) {
        printf("Invalid input! Please enter a value between %d and %d.\n", min, max);
        return 0;
    }
    return 1;
}