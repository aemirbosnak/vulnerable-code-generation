//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void displayWelcome() {
    printf("Welcome to the Dice Roller Program!\n");
    printf("You can roll multiple dice with different number of sides.\n");
    printf("Let's have some fun!\n\n");
}

int rollDice(int sides) {
    return rand() % sides + 1; // Generates a number between 1 and 'sides'
}

void rollMultipleDice(int numDice, int sides) {
    int i;
    printf("Rolling %d dice with %d sides each:\n", numDice, sides);
    for(i = 0; i < numDice; i++) {
        int result = rollDice(sides);
        printf("Dice %d: %d\n", i + 1, result);
    }
    printf("\n");
}

void getUserInput(int *numDice, int *sides) {
    printf("Enter the number of dice you want to roll (1 - 5): ");
    while (scanf("%d", numDice) != 1 || *numDice < 1 || *numDice > 5) {
        printf("Invalid input! Please enter a number between 1 and 5: ");
        while(getchar() != '\n'); // Clear the input buffer
    }

    printf("Enter the number of sides on the dice (4, 6, 8, 10, 12, 20): ");
    while (scanf("%d", sides) != 1 || (*sides != 4 && *sides != 6 && *sides != 8 && *sides != 10 && *sides != 12 && *sides != 20)) {
        printf("Invalid input! Please choose from 4, 6, 8, 10, 12, or 20: ");
        while(getchar() != '\n'); // Clear the input buffer
    }

    printf("\n");
}

int askToPlayAgain() {
    char choice;
    printf("Do you want to roll again? (y/n): ");
    while (scanf(" %c", &choice) != 1 || (choice != 'y' && choice != 'n')) {
        printf("Invalid input! Please enter 'y' to roll again or 'n' to quit: ");
        while(getchar() != '\n'); // Clear the input buffer
    }
    return choice == 'y';
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    displayWelcome();

    int numDice, sides;
    do {
        getUserInput(&numDice, &sides);
        rollMultipleDice(numDice, sides);
    } while (askToPlayAgain());

    printf("Thank you for playing! Goodbye!\n");
    return 0;
}