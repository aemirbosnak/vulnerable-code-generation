//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rollDice(int numDice, int sides) {
    int total = 0;

    printf("Rolling %d dice with %d sides each...\n", numDice, sides);
    for (int i = 1; i <= numDice; i++) {
        int roll = (rand() % sides) + 1; // Calculates the roll between 1 and sides
        printf("Dice %d rolled: %d\n", i, roll);
        total += roll;
    }

    printf("Total value from rolling %d dice: %d\n", numDice, total);
}

int main() {
    srand(time(0)); // Seed the random number generator

    int numDice = 0;
    int sides = 0;
    char choice;

    do {
        printf("Welcome to the C Dice Roller! 🎲\n");
        
        // Ask the user how many dice they wish to roll
        printf("How many dice do you want to roll? ");
        scanf("%d", &numDice);
        
        // Ask the user how many sides each dice should have
        printf("How many sides should each dice have? ");
        scanf("%d", &sides);

        if (numDice < 1 || sides < 1) {
            printf("Please enter positive integers for dice and sides.\n");
            continue;
        }

        rollDice(numDice, sides);

        // Ask if the user wants to roll again
        printf("Do you want to roll again? (y/n): ");
        scanf(" %c", &choice);
        
    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the C Dice Roller! Goodbye! 🎉\n");
    return 0;
}