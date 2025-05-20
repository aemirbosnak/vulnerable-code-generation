//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 10
#define MAX_FACES 20

void displayHeader() {
    printf("===================================\n");
    printf("         DICE ROLLER v1.0         \n");
    printf("       A Visionary Experience      \n");
    printf("===================================\n");
}

void rollDice(int numDice, int numFaces) {
    int total = 0;
    printf("Rolling %d dice with %d faces each...\n", numDice, numFaces);
    
    for(int i = 0; i < numDice; i++) {
        int roll = (rand() % numFaces) + 1;  // Roll the dice
        total += roll;  // Sum the result
        printf("Dice %d: Rolled a %d\n", i + 1, roll);
    }
    
    printf("Total roll: %d\n", total);
}

void displayMenu() {
    printf("Choose the number of dice to roll (1-%d): ", MAX_DICE);
}

int getValidInput(int min, int max) {
    int input;
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &input);
        if(input >= min && input <= max) {
            break;
        }
        printf("Invalid input. Please enter a number between %d and %d.\n", min, max);
    }
    return input;
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    int numDice, numFaces;

    displayHeader();
    
    // Get the number of dice
    displayMenu();
    numDice = getValidInput(1, MAX_DICE);

    // Get the number of faces
    printf("Enter the number of faces on the dice (2-%d): ", MAX_FACES);
    numFaces = getValidInput(2, MAX_FACES);

    // Perform the dice rolling
    rollDice(numDice, numFaces);

    printf("Thank you for using the Dice Roller!\n");
    return 0;
}