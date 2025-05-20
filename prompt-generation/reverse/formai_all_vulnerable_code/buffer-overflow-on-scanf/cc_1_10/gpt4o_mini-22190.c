//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void welcomeMessage() {
    printf("=================================\n");
    printf("       Welcome to Dice Roller    \n");
    printf("=================================\n");
    printf("Let the rolling begin... \n");
    printf("You can roll multiple dice with various faces.\n");
    printf("May luck be on your side! \n\n");
}

void promptForDice() {
    printf("Please enter the number of dice you wish to roll: ");
}

void promptForFaces() {
    printf("Now, please enter the number of faces on each die (e.g., 6 for a standard die): ");
}

int rollDie(int faces) {
    return (rand() % faces) + 1; // Generates a number between 1 and faces
}

void rollDice(int numDice, int numFaces) {
    int results[numDice];
    printf("\nRolling %d dice with %d faces each... \n", numDice, numFaces);
    for (int i = 0; i < numDice; i++) {
        results[i] = rollDie(numFaces);
        printf("Die %d: %d\n", i + 1, results[i]);
    }
    printf("\nThank you for rolling! \n");
}

void displayOutro() {
    printf("=================================\n");
    printf("        Thank you for playing!   \n");
    printf("=================================\n");
    printf("May your days be filled with joy and good fortune.\n");
}

int main() {
    int numDice, numFaces;

    // Initialize random number generator
    srand(time(NULL));

    welcomeMessage();
    promptForDice();
    scanf("%d", &numDice);
    
    promptForFaces();
    scanf("%d", &numFaces);
    
    if (numDice <= 0 || numFaces <= 0) {
        printf("Both the number of dice and number of faces must be positive integers.\n");
    } else {
        rollDice(numDice, numFaces);
    }

    displayOutro();

    return 0;
}