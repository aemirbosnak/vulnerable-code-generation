//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 10

void rollDice(int numDice, int sides);
void displayResults(int rolls[], int size);
int getUserInput(const char *prompt);

int main() {
    int numDice, sides;
    char choice;

    // Seed the random number generator
    srand(time(NULL));

    do {
        printf("\n======== Dice Roller ========\n");
        numDice = getUserInput("Enter the number of dice to roll (1-10): ");
        if (numDice < 1 || numDice > MAX_DICE) {
            printf("Please enter a valid number of dice (1-10).\n");
            continue;
        }

        sides = getUserInput("Enter the number of sides on the dice (4, 6, 8, 10, 12, 20): ");
        if (sides != 4 && sides != 6 && sides != 8 && sides != 10 && sides != 12 && sides != 20) {
            printf("Invalid number of sides. Please choose from 4, 6, 8, 10, 12, 20.\n");
            continue;
        }

        rollDice(numDice, sides);

        printf("Do you want to roll again? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("Thanks for using the Dice Roller!\n");

    return 0;
}

void rollDice(int numDice, int sides) {
    int rolls[MAX_DICE];
    
    printf("\nRolling %d %d-sided dice...\n", numDice, sides);

    for (int i = 0; i < numDice; i++) {
        rolls[i] = (rand() % sides) + 1; // Roll the dice (1 to sides)
    }

    displayResults(rolls, numDice);
}

void displayResults(int rolls[], int size) {
    printf("Results: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", rolls[i]);
    }
    printf("\n");
}

int getUserInput(const char *prompt) {
    int input;
    printf("%s", prompt);
    while (scanf("%d", &input) != 1) {
        while (getchar() != '\n'); // Clear invalid input
        printf("Invalid input. %s", prompt);
    }
    return input;
}