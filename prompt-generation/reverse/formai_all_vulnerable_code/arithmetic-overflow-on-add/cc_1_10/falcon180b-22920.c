//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 1000
#define MAX_SIDES 1000
#define MAX_ROLLS 1000

int rollDice(int numDice, int numSides) {
    int result = 0;
    for (int i = 0; i < numDice; i++) {
        result += rand() % numSides + 1;
    }
    return result;
}

void printRolls(int numDice, int numSides, int numRolls, int *rolls) {
    printf("Rolling %d dice with %d sides %d times:\n", numDice, numSides, numRolls);
    for (int i = 0; i < numRolls; i++) {
        printf("%d ", rolls[i]);
    }
    printf("\n");
}

void generateRolls(int numDice, int numSides, int numRolls, int *rolls) {
    srand(time(NULL));
    for (int i = 0; i < numRolls; i++) {
        rolls[i] = rollDice(numDice, numSides);
    }
}

void diceRoller(int numDice, int numSides, int numRolls) {
    int rolls[MAX_ROLLS] = {0};
    generateRolls(numDice, numSides, numRolls, rolls);
    printRolls(numDice, numSides, numRolls, rolls);
}

int main() {
    int numDice, numSides, numRolls;
    printf("Enter number of dice: ");
    scanf("%d", &numDice);
    printf("Enter number of sides: ");
    scanf("%d", &numSides);
    printf("Enter number of rolls: ");
    scanf("%d", &numRolls);
    if (numDice > MAX_DICE || numSides > MAX_SIDES || numRolls > MAX_ROLLS) {
        printf("Invalid input.\n");
        return 1;
    }
    diceRoller(numDice, numSides, numRolls);
    return 0;
}