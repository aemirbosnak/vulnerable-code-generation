//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rollDice(int numDice, int sides);
int getChance(); 
void displayResults(int *results, int size);
void printSummary(int *results, int size);
int calculateAverage(int *results, int size);
void errorMessage(const char *message);

int main() {
    srand(time(NULL)); // Seed random number generator
    int numDice, sides;

    printf("Welcome to the Recursive Dice Roller!\n");
    printf("Please enter the number of dice to roll: ");
    if (scanf("%d", &numDice) != 1 || numDice < 1) {
        errorMessage("Invalid number of dice. Please enter a positive integer.");
    }

    printf("Please enter the number of sides on the dice: ");
    if (scanf("%d", &sides) != 1 || sides < 1) {
        errorMessage("Invalid number of sides. Please enter a positive integer.");
    }

    rollDice(numDice, sides);

    return 0;
}

void rollDice(int numDice, int sides) {
    if (numDice == 0) {
        return; // Base case: no more dice to roll
    }

    int roll = (rand() % sides) + 1; // Roll the dice (1 to sides)
    printf("Rolling dice... You rolled a %d\n", roll);
    rollDice(numDice - 1, sides); // Recursive call to roll the next die
}

int getChance() {
    int chance = rand() % 100; // Generate a random chance (0 to 99)
    return chance;
}

void displayResults(int *results, int size) {
    printf("Rolling results:\n");
    for (int i = 0; i < size; i++) {
        printf("Roll %d: %d\n", i + 1, results[i]);
    }
}

void printSummary(int *results, int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += results[i];
    }

    int average = calculateAverage(results, size);
    printf("Total: %d, Average: %d\n", total, average);
}

int calculateAverage(int *results, int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += results[i];
    }
    return total / size; // Calculate the average
}

void errorMessage(const char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1); // Exit the program with error
}