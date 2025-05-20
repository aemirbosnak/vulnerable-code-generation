//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIDES 20
#define MIN_SIDES 4

// Function declarations
void printWelcomeMessage();
int rollDice(int sides);
void displayStatistics(int* rolls, int numRolls, int sides);
void clearBuffer();
int getValidInteger(int min, int max);

int main() {
    srand(time(NULL));

    int sides;
    int numRolls;
    char continueRolling;

    // Welcome message
    printWelcomeMessage();

    do {
        printf("Enter the number of sides on the die (between %d and %d): ", MIN_SIDES, MAX_SIDES);
        sides = getValidInteger(MIN_SIDES, MAX_SIDES);

        printf("How many times would you like to roll the dice? ");
        numRolls = getValidInteger(1, 100); // limit rolls to a reasonable number

        int* rolls = (int*)malloc(numRolls * sizeof(int));
        if (rolls == NULL) {
            fprintf(stderr, "Memory allocation failed.");
            return 1;
        }

        // Rolling the dice
        for (int i = 0; i < numRolls; i++) {
            rolls[i] = rollDice(sides);
        }

        // Display results
        printf("\nResults of rolling a %d-sided die %d times:\n", sides, numRolls);
        for (int i = 0; i < numRolls; i++) {
            printf("Roll %d: %d\n", i + 1, rolls[i]);
        }

        // Display statistics
        displayStatistics(rolls, numRolls, sides);

        free(rolls);

        printf("\nWould you like to roll the dice again? (y/n): ");
        clearBuffer();
        continueRolling = getchar();

    } while (continueRolling == 'y' || continueRolling == 'Y');

    printf("Thank you for using the Dice Roller. Goodbye!\n");
    return 0;
}

void printWelcomeMessage() {
    printf("=====================================\n");
    printf("           DICE ROLLER              \n");
    printf("-------------------------------------\n");
    printf(" Welcome to the Ultimate Dice Roller!\n");
    printf(" Roll different kinds of dice and see\n");
    printf(" your results instantly!\n");
    printf("=====================================\n");
}

int rollDice(int sides) {
    return (rand() % sides) + 1;
}

void displayStatistics(int* rolls, int numRolls, int sides) {
    printf("\nStatistics (for a %d-sided die):\n", sides);
    int sum = 0;
    int min = sides + 1;
    int max = 0;

    for (int i = 0; i < numRolls; i++) {
        sum += rolls[i];
        if (rolls[i] < min) min = rolls[i];
        if (rolls[i] > max) max = rolls[i];
    }

    double average = (double)sum / numRolls;

    printf("Total Rolls: %d\n", numRolls);
    printf("Sum of Rolls: %d\n", sum);
    printf("Average Roll: %.2f\n", average);
    printf("Minimum Roll: %d\n", min);
    printf("Maximum Roll: %d\n", max);
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int getValidInteger(int min, int max) {
    int input;
    while (1) {
        scanf("%d", &input);
        if (input >= min && input <= max) {
            return input;
        } else {
            printf("Invalid input. Please enter a number between %d and %d: ", min, max);
            clearBuffer();
        }
    }
}