//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll a die
int rollDie(int sides) {
    return (rand() % sides) + 1;
}

// Function to display the result of the dice rolls
void displayResults(int rolls[], int numRolls, int sides) {
    printf("Rolling a %d-sided die:\n", sides);
    for (int i = 0; i < numRolls; i++) {
        printf("Roll %d: %d\n", i + 1, rolls[i]);
    }
}

// Function to calculate the average of the rolls
double calculateAverage(int rolls[], int numRolls) {
    int sum = 0;
    for (int i = 0; i < numRolls; i++) {
        sum += rolls[i];
    }
    return (double)sum / numRolls;
}

// Function to run the dice rolling game
void diceRollingGame() {
    int numRolls, sides;

    printf("Welcome to the Dice Rolling Game!\n");
    printf("Enter the number of sides on the die: ");
    scanf("%d", &sides);
    printf("Enter the number of rolls: ");
    scanf("%d", &numRolls);

    if (sides <= 0 || numRolls <= 0) {
        printf("Both number of sides and number of rolls must be positive integers!\n");
        return;
    }

    int *rolls = (int *)malloc(numRolls * sizeof(int));
    if (rolls == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    srand(time(0)); // Seed for random number generator

    for (int i = 0; i < numRolls; i++) {
        rolls[i] = rollDie(sides);
    }

    displayResults(rolls, numRolls, sides);
    double average = calculateAverage(rolls, numRolls);
    printf("Average roll: %.2f\n", average);

    free(rolls);
}

int main() {
    char choice;

    do {
        diceRollingGame();
        printf("Would you like to roll again? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("Thanks for playing!\n");
    return 0;
}