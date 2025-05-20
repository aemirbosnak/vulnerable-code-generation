//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 6

// Function prototypes
void displayMenu();
int rollDice(int sides);
void simulateRolling(int diceCount, int sides);
void displayResults(int* rolls, int diceCount);
void calculateStatistics(int* rolls, int diceCount);

// Main function
int main() {
    int diceCount, sides, choice;

    // Seed random number generator
    srand(time(NULL));

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of dice you want to roll: ");
                scanf("%d", &diceCount);
                printf("Enter the number of sides on each die (2 to %d): ", MAX_DICE);
                scanf("%d", &sides);
                
                if (sides < 2 || sides > MAX_DICE) {
                    printf("Invalid number of sides! Please choose between 2 and %d.\n", MAX_DICE);
                } else {
                    simulateRolling(diceCount, sides);
                }
                break;
            case 2:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 2);

    return 0;
}

// Function to display the menu
void displayMenu() {
    printf("\n--- Dice Roller Menu ---\n");
    printf("1. Roll Dice\n");
    printf("2. Exit\n");
    printf("Choose an option: ");
}

// Function to roll a die with a given number of sides
int rollDice(int sides) {
    return (rand() % sides) + 1;
}

// Function to simulate rolling multiple dice
void simulateRolling(int diceCount, int sides) {
    int* rolls = (int*)malloc(diceCount * sizeof(int));
    if (rolls == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    printf("\nRolling %d dice with %d sides...\n", diceCount, sides);

    for (int i = 0; i < diceCount; i++) {
        rolls[i] = rollDice(sides);
    }

    displayResults(rolls, diceCount);
    calculateStatistics(rolls, diceCount);

    free(rolls);
}

// Function to display the results of the rolls
void displayResults(int* rolls, int diceCount) {
    printf("You rolled: ");
    for (int i = 0; i < diceCount; i++) {
        printf("%d ", rolls[i]);
    }
    printf("\n");
}

// Function to calculate and display statistics
void calculateStatistics(int* rolls, int diceCount) {
    int sum = 0;
    int max = rolls[0];
    int min = rolls[0];

    for (int i = 0; i < diceCount; i++) {
        sum += rolls[i];
        if (rolls[i] > max) {
            max = rolls[i];
        }
        if (rolls[i] < min) {
            min = rolls[i];
        }
    }

    double average = (double)sum / diceCount;

    printf("Statistics:\n");
    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", average);
    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);
}