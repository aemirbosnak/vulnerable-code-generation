//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void displayWelcomeMessage() {
    printf("Welcome to the Dice Roller Program!\n");
    printf("Roll as many dice as you wish with your choice of sides.\n");
    printf("Let's get rolling!\n");
}

int rollDice(int sides) {
    return (rand() % sides) + 1;
}

void rollMultipleDice(int numDice, int sides) {
    int total = 0;
    printf("Rolling %d dice with %d sides:\n", numDice, sides);

    for (int i = 0; i < numDice; i++) {
        int roll = rollDice(sides);
        printf("Dice %d: %d\n", i + 1, roll);
        total += roll;
    }

    printf("Total roll: %d\n", total);
}

void readConfiguration(int *numDice, int *sides) {
    printf("Enter the number of dice to roll: ");
    scanf("%d", numDice);
    printf("Enter the number of sides on the dice (e.g. 6 for a standard die): ");
    scanf("%d", sides);
}

void displayGoodbyeMessage() {
    printf("Thank you for using the Dice Roller Program! Goodbye!\n");
}

int main() {
    int numDice, sides;
    char choice;

    srand(time(NULL));  // Seed for random number generator
    displayWelcomeMessage();

    do {
        readConfiguration(&numDice, &sides);
        
        if (numDice <= 0 || sides <= 1) {
            printf("Please enter a valid number of dice and sides.\n");
            continue;
        }

        rollMultipleDice(numDice, sides);

        printf("Would you like to roll again? (y/n): ");
        scanf(" %c", &choice);  // Note the space before %c to consume any newline character

    } while (choice == 'y' || choice == 'Y');

    displayGoodbyeMessage();
    return 0;
}