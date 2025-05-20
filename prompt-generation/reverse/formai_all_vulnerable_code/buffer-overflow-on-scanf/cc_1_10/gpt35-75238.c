//FormAI DATASET v1.0 Category: Dice Roller ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to roll a single die
int rollDie() {
    int result = (rand() % 6) + 1;
    return result;
}

// function to display the roll results
void displayRoll(int *rolls, int numDice) {
    printf("\nYou rolled:\n");
    for (int i=0; i<numDice; i++) {
        printf("Die %d: %d\n", i+1, rolls[i]);
    }
}

// function to calculate and display the total roll result
void displayTotal(int *rolls, int numDice) {
    int total = 0;
    for (int i=0; i<numDice; i++) {
        total += rolls[i];
    }
    printf("\nTotal roll: %d\n", total);
}

int main() {
    // seed the random number generator
    srand(time(0));

    int numDice;
    printf("Enter number of dice to roll: ");
    scanf("%d", &numDice);

    // allocate memory for array to hold roll results
    int *rolls = (int*)malloc(numDice * sizeof(int));

    // roll each die and store the result in the array
    for (int i=0; i<numDice; i++) {
        rolls[i] = rollDie();
    }

    // display the roll results and the total roll
    displayRoll(rolls, numDice);
    displayTotal(rolls, numDice);

    // free dynamically allocated memory
    free(rolls);

    return 0;
}