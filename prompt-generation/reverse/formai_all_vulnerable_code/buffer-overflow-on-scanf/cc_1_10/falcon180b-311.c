//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 1000
#define MIN_VALUE 1
#define MAX_VALUE 6

// Function to generate random numbers
void generateRandomNumbers(int dice[], int numDice) {
    int i;
    for (i = 0; i < numDice; i++) {
        dice[i] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
    }
}

// Function to print the dice rolls
void printDiceRolls(int dice[], int numDice) {
    int i;
    for (i = 0; i < numDice; i++) {
        printf("%d ", dice[i]);
    }
    printf("\n");
}

// Function to roll the dice
void rollDice(int dice[], int numDice) {
    int i;
    for (i = 0; i < numDice; i++) {
        dice[i] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
    }
}

// Function to sort the dice rolls
void sortDiceRolls(int dice[], int numDice) {
    int i, j;
    for (i = 0; i < numDice - 1; i++) {
        for (j = i + 1; j < numDice; j++) {
            if (dice[i] > dice[j]) {
                int temp = dice[i];
                dice[i] = dice[j];
                dice[j] = temp;
            }
        }
    }
}

// Function to count the number of dice rolls
int countDiceRolls(int dice[], int numDice, int target) {
    int i, count = 0;
    for (i = 0; i < numDice; i++) {
        if (dice[i] == target) {
            count++;
        }
    }
    return count;
}

int main() {
    int numDice, target, i, count;
    srand(time(NULL));
    printf("Enter the number of dice to roll: ");
    scanf("%d", &numDice);
    printf("Enter the target value: ");
    scanf("%d", &target);
    int dice[MAX_DICE];
    generateRandomNumbers(dice, numDice);
    printf("Initial dice rolls:\n");
    printDiceRolls(dice, numDice);
    printf("Number of dice rolls with value %d: %d\n", target, countDiceRolls(dice, numDice, target));
    sortDiceRolls(dice, numDice);
    printf("Sorted dice rolls:\n");
    printDiceRolls(dice, numDice);
    return 0;
}