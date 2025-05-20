//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 6

// Function prototypes
void rollDice(int numDice, int diceSides);
void displayResults(int *results, int numDice);
int getIntegerInput(const char *prompt);
char getContinueInput();
void clearBuffer();

int main() {
    srand(time(NULL)); // Seed the random number generator
    int numDice, diceSides;
    char continueRolling;

    printf("Welcome to the C Dice Roller!\n");
    
    // Main loop for rolling dice
    do {
        numDice = getIntegerInput("Enter the number of dice to roll: ");
        diceSides = getIntegerInput("Enter the number of sides on the dice: ");
        
        if (diceSides < 1 || diceSides > MAX_DICE) {
            printf("Please enter a valid number of sides (1 to %d).\n", MAX_DICE);
            continue;
        }

        rollDice(numDice, diceSides);
        
        continueRolling = getContinueInput();
    } while (continueRolling == 'y' || continueRolling == 'Y');

    printf("Thank you for using the C Dice Roller. Goodbye!\n");
    return 0;
}

// Function to roll dice and display the results
void rollDice(int numDice, int diceSides) {
    int *results = (int *)malloc(numDice * sizeof(int));
    if (results == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < numDice; i++) {
        results[i] = (rand() % diceSides) + 1; // Generate a random number from 1 to diceSides
    }
    
    displayResults(results, numDice);
    
    free(results); // Free allocated memory
}

// Function to display the results of the dice roll
void displayResults(int *results, int numDice) {
    printf("You rolled: ");
    for (int i = 0; i < numDice; i++) {
        printf("%d ", results[i]);
    }
    printf("\n");
}

// Function to get valid integer input from the user
int getIntegerInput(const char *prompt) {
    int value;
    printf("%s", prompt);
    while (scanf("%d", &value) != 1 || value <= 0) {
        printf("Invalid input. Please enter a positive integer: ");
        clearBuffer(); // Clear invalid input from the buffer
    }
    clearBuffer(); // Clear the buffer after valid input
    return value;
}

// Function to prompt the user whether they want to continue rolling
char getContinueInput() {
    char input;
    printf("Would you like to roll again? (y/n): ");
    while (1) {
        input = getchar();
        clearBuffer();
        if (input == 'y' || input == 'Y' || input == 'n' || input == 'N')
            break;
        printf("Invalid input. Please enter 'y' or 'n': ");
    }
    return input;
}

// Function to clear the input buffer
void clearBuffer() {
    while (getchar() != '\n'); // Discard characters until the end of the line
}