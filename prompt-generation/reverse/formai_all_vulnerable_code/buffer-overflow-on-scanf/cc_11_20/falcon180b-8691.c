//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 1000

int main() {
    int numDice, numSides, numRolls, i, j;
    int dice[MAX_DICE];
    int total = 0;
    char choice;

    srand(time(NULL));

    printf("Welcome to the Dice Roller!\n");
    printf("How many dice would you like to roll? (1-1000): ");
    scanf("%d", &numDice);

    if (numDice < 1 || numDice > MAX_DICE) {
        printf("Invalid input. Please enter a number between 1 and %d.\n", MAX_DICE);
        return 1;
    }

    for (i = 0; i < numDice; i++) {
        printf("How many sides does dice %d have? (1-1000): ", i+1);
        scanf("%d", &numSides);

        if (numSides < 1 || numSides > 1000) {
            printf("Invalid input. Please enter a number between 1 and %d.\n", 1000);
            return 1;
        }

        dice[i] = rand() % numSides + 1;
        total += dice[i];
    }

    printf("You rolled %d dice with a total of %d sides.\n", numDice, total);
    printf("The results are:\n");

    for (i = 0; i < numDice; i++) {
        printf("Dice %d: %d\n", i+1, dice[i]);
    }

    printf("Would you like to roll again? (y/n): ");
    scanf(" %c", &choice);

    while (choice == 'y' || choice == 'Y') {
        for (i = 0; i < numDice; i++) {
            dice[i] = rand() % numSides + 1;
            total += dice[i];
        }

        printf("\nYou rolled %d dice with a total of %d sides.\n", numDice, total);
        printf("The results are:\n");

        for (i = 0; i < numDice; i++) {
            printf("Dice %d: %d\n", i+1, dice[i]);
        }

        printf("Would you like to roll again? (y/n): ");
        scanf(" %c", &choice);
    }

    return 0;
}