//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIDES 6
#define MIN_VALUE 1
#define MAX_VALUE SIDES

// Function to generate a random number between min and max
int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to roll the dice
void rollDice(int numDice, int numSides) {
    int i, j;
    for (i = 0; i < numDice; i++) {
        for (j = 0; j < numSides; j++) {
            printf("%d ", generateRandomNumber(MIN_VALUE, MAX_VALUE));
        }
        printf("\n");
    }
}

// Function to handle invalid input
void handleInvalidInput() {
    printf("Invalid input. Please enter a positive integer.\n");
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    int numDice, numSides;

    // Prompt the user for the number of dice to roll
    printf("Enter the number of dice to roll: ");
    if (scanf("%d", &numDice)!= 1 || numDice <= 0) {
        handleInvalidInput();
        return 1;
    }

    // Prompt the user for the number of sides on each die
    printf("Enter the number of sides on each die: ");
    if (scanf("%d", &numSides)!= 1 || numSides <= 0 || numSides > SIDES) {
        handleInvalidInput();
        return 1;
    }

    // Roll the dice
    rollDice(numDice, numSides);

    return 0;
}