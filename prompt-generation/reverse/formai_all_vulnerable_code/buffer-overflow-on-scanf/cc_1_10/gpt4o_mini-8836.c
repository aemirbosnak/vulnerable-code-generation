//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 10
#define DEFAULT_ROLLS 1

void clearBuffer() {
    while (getchar() != '\n');
}

int rollDice(int sides) {
    return (rand() % sides) + 1;
}

void displayRolls(int rolls[], int numRolls, int sides) {
    printf("You rolled:\n");
    for (int i = 0; i < numRolls; i++) {
        printf("Roll %d: %d\n", i + 1, rolls[i]);
    }
}

void printStatistics(int rolls[], int numRolls, int sides) {
    int counts[sides + 1];
    for (int i = 0; i <= sides; i++) {
        counts[i] = 0;
    }

    for (int i = 0; i < numRolls; i++) {
        counts[rolls[i]]++;
    }

    printf("\nStatistics:\n");
    for (int i = 1; i <= sides; i++) {
        printf("Side %d: %d times (%.2f%%)\n", i, counts[i], (counts[i] / (float)numRolls) * 100);
    }
}

void interactiveDiceRoller() {
    int sides, rolls, numRolls, *rollsArray;

    printf("Welcome to the Interactive Dice Roller!\n");

    while (1) {
        printf("\nEnter the number of sides on the die (4, 6, 8, 10, 12, 20): ");
        scanf("%d", &sides);
        if (sides == 4 || sides == 6 || sides == 8 || sides == 10 || sides == 12 || sides == 20) {
            break;
        }
        printf("Invalid input. Please try again.\n");
    }

    while (1) {
        printf("\nEnter the number of rolls (1 to %d, or 0 to exit): ", MAX_DICE);
        scanf("%d", &numRolls);
        if (numRolls >= 1 && numRolls <= MAX_DICE) {
            rollsArray = malloc(numRolls * sizeof(int));
            break;
        } else if (numRolls == 0) {
            printf("Exiting the dice roller. Goodbye!\n");
            return;
        }
        printf("Invalid input. Please try again.\n");
    }

    srand(time(NULL));

    for (rolls = 0; rolls < numRolls; rolls++) {
        rollsArray[rolls] = rollDice(sides);
    }

    displayRolls(rollsArray, numRolls, sides);
    printStatistics(rollsArray, numRolls, sides);

    free(rollsArray);
}

int main() {
    interactiveDiceRoller();
    return 0;
}