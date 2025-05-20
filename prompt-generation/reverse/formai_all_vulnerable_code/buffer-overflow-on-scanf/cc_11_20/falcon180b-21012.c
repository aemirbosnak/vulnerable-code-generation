//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numDice, sides, i, j, maxRoll = 0;
    char again;

    do {
        printf("Enter the number of dice: ");
        scanf("%d", &numDice);
        if (numDice <= 0) {
            printf("Invalid input. Please enter a positive integer.\n");
        }
    } while (numDice <= 0);

    do {
        printf("Enter the number of sides on each dice: ");
        scanf("%d", &sides);
        if (sides <= 0) {
            printf("Invalid input. Please enter a positive integer.\n");
        }
    } while (sides <= 0);

    srand(time(NULL));
    int diceArray[numDice];

    for (i = 0; i < numDice; i++) {
        diceArray[i] = rand() % sides + 1;
        if (diceArray[i] > maxRoll) {
            maxRoll = diceArray[i];
        }
    }

    printf("You rolled: ");
    for (i = 0; i < numDice; i++) {
        printf("%d ", diceArray[i]);
    }
    printf("\n");

    if (maxRoll == sides) {
        printf("Congratulations! You rolled a %d with all the dice.\n", sides);
    } else {
        printf("The highest roll was %d.\n", maxRoll);
    }

    printf("Do you want to roll again? (y/n): ");
    scanf(" %c", &again);

    if (again == 'y' || again == 'Y') {
        main();
    } else {
        return 0;
    }
}