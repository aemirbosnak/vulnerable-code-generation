//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 10  // Maximum number of dice
#define MAX_SIDES 20  // Maximum number of sides on each die

void displayResult(int *results, int count);
void validateInput(int *numDice, int *numSides);
void rollDice(int *results, int numDice, int numSides);

int main() {
    int numDice, numSides;
    
    // Adding initial surprise!
    printf("Welcome to the SHOCKING Dice Roller!\n");
    printf("Are you prepared for an unpredictable adventure? Let's find out!\n\n");

    // Validating user input for the number of dice and sides
    validateInput(&numDice, &numSides);
    
    // Array to hold the results of the dice rolls
    int results[MAX_DICE] = {0};

    // Rolling the dice! Brace yourself!
    printf("Rolling %d dice with %d sides each!\n", numDice, numSides);
    rollDice(results, numDice, numSides); // This is it!

    // Displaying the results
    displayResult(results, numDice);

    // Final shocking outcome!
    printf("\nThank you for playing the SHOCKING Dice Roller!\nHope you enjoyed the surprise!\n");
    
    return 0;
}

// Function to validate user input
void validateInput(int *numDice, int *numSides) {
    while (1) {
        printf("Enter the number of dice (1 to %d): ", MAX_DICE);
        scanf("%d", numDice);
        if (*numDice < 1 || *numDice > MAX_DICE) {
            printf("SHOCK! Invalid number of dice! Try again...\n");
            continue;
        }

        printf("Enter the number of sides for each die (1 to %d): ", MAX_SIDES);
        scanf("%d", numSides);
        if (*numSides < 1 || *numSides > MAX_SIDES) {
            printf("CRASH! Invalid number of sides! Try again...\n");
            continue;
        }

        break; // Input is valid, we can exit the while loop
    }
}

// Function to roll the dice
void rollDice(int *results, int numDice, int numSides) {
    srand(time(0));  // Seeding the random number generator with the current time
    for (int i = 0; i < numDice; i++) {
        results[i] = (rand() % numSides) + 1; // Random number between 1 and numSides
    }
}

// Function to display the results of the dice rolls
void displayResult(int *results, int count) {
    printf("\n--- SHOCKING Results ---\n");
    for (int i = 0; i < count; i++) {
        printf("Dice %d: %d\n", i + 1, results[i]);
    }
    printf("------------------------\n");
}