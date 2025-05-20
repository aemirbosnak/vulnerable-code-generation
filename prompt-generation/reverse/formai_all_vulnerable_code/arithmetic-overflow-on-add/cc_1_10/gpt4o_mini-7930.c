//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void displayWelcomeMessage();
void rollDice(int numDice, int numSides);
void playAgain();
void displayGoodbyeMessage();

int main() {
    // Seed the random number generator
    srand(time(0));

    // Display a welcome message
    displayWelcomeMessage();

    // Game loop
    char choice;
    do {
        int numDice, numSides;

        // Ask the user for the number of dice
        printf("Enter the number of dice you want to roll: ");
        scanf("%d", &numDice);
        // Ask the user for the number of sides on each die
        printf("Enter the number of sides on each die: ");
        scanf("%d", &numSides);

        // Roll the dice
        rollDice(numDice, numSides);

        // Ask if the user wants to play again
        playAgain();
        choice = getchar();  // to consume newline character from buffer
        choice = getchar();  // read the actual choice

    } while (choice == 'y' || choice == 'Y');

    // Display a goodbye message
    displayGoodbyeMessage();

    return 0;
}

// Function to display a welcome message
void displayWelcomeMessage() {
    printf("************************************\n");
    printf("*          Welcome to the          *\n");
    printf("*           Magical Dice           *\n");
    printf("*             Roller!              *\n");
    printf("************************************\n");
    printf("Prepare yourself for an adventure where fate is determined by the roll of the dice!\n\n");
}

// Function to roll dice and display results
void rollDice(int numDice, int numSides) {
    int total = 0;
    printf("Rolling %d dice with %d sides...\n", numDice, numSides);
    for (int i = 0; i < numDice; i++) {
        int roll = (rand() % numSides) + 1;  // Generate a random roll
        printf("Die %d rolled: %d\n", i + 1, roll);
        total += roll;  // Sum up the rolls
    }
    printf("Total of all rolls: %d\n\n", total);
}

// Function to ask user if they want to play again
void playAgain() {
    printf("Do you want to roll again? (y/n): ");
}

// Function to display a goodbye message
void displayGoodbyeMessage() {
    printf("************************************\n");
    printf("*           Thank you for          *\n");
    printf("*           using the Magical       *\n");
    printf("*           Dice Roller!            *\n");
    printf("************************************\n");
    printf("May the odds be ever in your favor!\n");
}