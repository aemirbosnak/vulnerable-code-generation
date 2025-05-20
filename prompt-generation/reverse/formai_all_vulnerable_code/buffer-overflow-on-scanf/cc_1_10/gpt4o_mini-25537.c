//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 10
#define MAX_SIDES 20

void printWelcomeMessage();
void rollDice(int numDice, int numSides);
void getDiceParameters(int* numDice, int* numSides);
void invalidInputMessage();

int main() {
    int numDice = 0, numSides = 0;
    char choice;

    printWelcomeMessage();

    do {
        getDiceParameters(&numDice, &numSides);
        rollDice(numDice, numSides);

        printf("\nWould you like to roll again? (y/n): ");
        scanf(" %c", &choice);
    } while(choice == 'y' || choice == 'Y');

    printf("Thank you for using the Dice Roller! Goodbye!\n");
    return 0;
}

void printWelcomeMessage() {
    printf("************************************\n");
    printf("        Welcome to the Dice Roller  \n");
    printf("************************************\n");
    printf("This program allows you to roll multiple dice of various types.\n");
    printf("You can choose how many dice to roll and how many sides they have.\n");
}

void getDiceParameters(int* numDice, int* numSides) {
    while(1) {
        printf("\nEnter number of dice to roll (1-%d): ", MAX_DICE);
        scanf("%d", numDice);
        if (*numDice < 1 || *numDice > MAX_DICE) {
            invalidInputMessage();
            continue;
        }

        printf("Enter number of sides on each die (4, 6, 8, 10, 12, 20): ");
        scanf("%d", numSides);
        if (*numSides != 4 && *numSides != 6 && *numSides != 8 &&
            *numSides != 10 && *numSides != 12 && *numSides != 20) {
            invalidInputMessage();
            continue;
        }
        
        break;  // Valid input, exit loop
    }
}

void rollDice(int numDice, int numSides) {
    int total = 0;
    int results[MAX_DICE];

    srand(time(NULL));  // Seed random number generator
    printf("\nRolling %d %d-sided dice:\n", numDice, numSides);

    for (int i = 0; i < numDice; i++) {
        results[i] = (rand() % numSides) + 1;  // Random value between 1 and numSides
        total += results[i];
        printf("Die %d: %d\n", i + 1, results[i]);
    }
    
    printf("Total: %d\n", total);
}

void invalidInputMessage() {
    printf("Invalid input! Please try again.\n");
}