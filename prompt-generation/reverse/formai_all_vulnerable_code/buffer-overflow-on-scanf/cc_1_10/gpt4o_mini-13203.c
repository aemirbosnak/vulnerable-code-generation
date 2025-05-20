//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void printMenu();
int rollDice(int sides);
void playGame(int numDice, int sides);
void displayResults(int* rolls, int numDice);
void logRollsToFile(int* rolls, int numDice);
int getValidInput(const char* prompt, int min, int max);

int main() {
    srand(time(0)); // Seed the random number generator
    int numDice = 0, sides = 0;

    // User input for number of dice and sides
    printf("Welcome to the C Dice Roller!\n");
    numDice = getValidInput("Enter the number of dice (1-10): ", 1, 10);
    sides = getValidInput("Enter the number of sides on the dice (4, 6, 8, 10, 12, 20): ", 4, 20);

    // Start the game
    playGame(numDice, sides);

    return 0;
}

// Function to display the menu of options
void printMenu() {
    printf("Dice Roller Menu:\n");
    printf("1. Roll Dice\n");
    printf("2. View Last Rolls\n");
    printf("3. Exit\n");
}

// Function to roll a die with a given number of sides
int rollDice(int sides) {
    return (rand() % sides) + 1;
}

// Function to manage the gameplay
void playGame(int numDice, int sides) {
    int choice = 0;
    int* rolls = (int*)malloc(numDice * sizeof(int));
    if (rolls == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    do {
        printMenu();
        choice = getValidInput("Choose an option (1-3): ", 1, 3);
        
        switch (choice) {
            case 1: // Roll the dice
                for (int i = 0; i < numDice; i++) {
                    rolls[i] = rollDice(sides);
                }
                displayResults(rolls, numDice);
                logRollsToFile(rolls, numDice);
                break;
            case 2: // View last rolls (this will only show the most recent if rolled)
                displayResults(rolls, numDice);
                break;
            case 3: // Exit
                printf("Thank you for using the C Dice Roller!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (choice != 3);

    free(rolls);
}

// Function to display the results of the rolls
void displayResults(int* rolls, int numDice) {
    printf("You rolled:\n");
    for (int i = 0; i < numDice; i++) {
        printf("Die %d: %d\n", i + 1, rolls[i]);
    }
}

// Function to log the rolls to a file
void logRollsToFile(int* rolls, int numDice) {
    FILE* file = fopen("dice_rolls.log", "a"); // Open log file in append mode
    if (file != NULL) {
        for (int i = 0; i < numDice; i++) {
            fprintf(file, "Die %d: %d\n", i + 1, rolls[i]);
        }
        fprintf(file, "--------------------\n");
        fclose(file);
    } else {
        printf("Could not open log file!\n");
    }
}

// Function to get valid input for number of dice or sides
int getValidInput(const char* prompt, int min, int max) {
    int input = 0;
    int valid = 0;

    while (!valid) {
        printf("%s", prompt);
        if (scanf("%d", &input) == 1 && input >= min && input <= max) {
            valid = 1;
        } else {
            printf("Invalid input, please enter a number between %d and %d.\n", min, max);
            while (getchar() != '\n'); // clear the input buffer
        }
    }
    
    return input;
}