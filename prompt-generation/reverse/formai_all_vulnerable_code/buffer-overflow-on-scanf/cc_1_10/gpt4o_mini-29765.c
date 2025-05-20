//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 10

// Function prototypes
void welcomeMessage();
void rollDice(int numDice);
int getNumOfDice();

int main() {
    int numDice;
    
    // Seed the random number generator
    srand(time(NULL));

    // Show welcome message to user
    welcomeMessage();

    // Get the number of dice to roll from user
    numDice = getNumOfDice();
    
    // Roll the dice the specified number of times
    rollDice(numDice);

    return 0;
}

void welcomeMessage() {
    printf("===================================================\n");
    printf("              Welcome to the Dice Roller!       \n");
    printf("===================================================\n");
    printf("         Roll up to %d dice at a time.           \n", MAX_DICE);
    printf("          Let's get started with some randomness! \n");
    printf("===================================================\n");
}

int getNumOfDice() {
    int numDice;
    while (1) {
        printf("How many dice would you like to roll (1 to %d)? ", MAX_DICE);
        scanf("%d", &numDice);

        if (numDice >= 1 && numDice <= MAX_DICE) {
            return numDice;
        } else {
            printf("Invalid input. Please enter a number between 1 and %d.\n", MAX_DICE);
        }
    }
}

void rollDice(int numDice) {
    int rollResults[MAX_DICE];
    
    printf("Rolling %d dice...\n", numDice);
    
    for (int i = 0; i < numDice; i++) {
        rollResults[i] = (rand() % 6) + 1; // Generate a random number between 1 and 6
    }

    printf("You rolled: ");
    
    for (int i = 0; i < numDice; i++) {
        printf("%d ", rollResults[i]);
    }
    printf("\n");

    // Calculate total
    int total = 0;
    for (int i = 0; i < numDice; i++) {
        total += rollResults[i];
    }
    printf("Total of rolls: %d\n", total);
    
    printf("===================================================\n");
    printf("Thank you for using the Dice Roller!              \n");
    printf("===================================================\n");
}