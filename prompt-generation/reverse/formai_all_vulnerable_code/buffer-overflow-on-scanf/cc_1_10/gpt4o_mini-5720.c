//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 10
#define MAX_SIDES 20
#define MAX_ROLLS 100

// Function prototypes
void rollDice(int diceCount, int sides, int *results);
void displayResults(int *results, int count);
void clearBuffer();
int getIntInput(const char *prompt, int min, int max);

int main() {
    srand(time(NULL));  // Seed the random number generator
    int diceCount, sides, results[MAX_ROLLS];
    char choice;

    printf("Welcome to the C Dice Roller Program!\n");
    printf("Roll up to %d dice, each with up to %d sides.\n", MAX_DICE, MAX_SIDES);

    do {
        // Get user input for dice count and sides
        diceCount = getIntInput("Enter the number of dice to roll (1-10): ", 1, MAX_DICE);
        sides = getIntInput("Enter the number of sides on each die (2-20): ", 2, MAX_SIDES);

        // Roll the dice and store results
        rollDice(diceCount, sides, results);
        
        // Display the results of the rolls
        displayResults(results, diceCount);

        // Ask user if they want to roll again
        printf("Do you want to roll again? (y/n): ");
        clearBuffer();  // Clear any newline characters from previous inputs
        choice = getchar();

    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the C Dice Roller Program! Goodbye!\n");
    return 0;
}

// Function to roll the dice and store the results
void rollDice(int diceCount, int sides, int *results) {
    for (int i = 0; i < diceCount; i++) {
        results[i] = (rand() % sides) + 1;  // Store the rolled value
    }
}

// Function to display the results of the dice rolls
void displayResults(int *results, int count) {
    printf("You rolled:\n");
    for (int i = 0; i < count; i++) {
        printf("Die %d: %d\n", i + 1, results[i]);
    }
    printf("Total: %d\n", count > 0 ? sumResults(results, count) : 0);
}

// Function to sum the results of the dice rolls
int sumResults(int *results, int count) {
    int total = 0;
    for (int i = 0; i < count; i++) {
        total += results[i];
    }
    return total;
}

// Function to safely read an integer input from the user
int getIntInput(const char *prompt, int min, int max) {
    int value;
    char term;

    while (1) {
        printf("%s", prompt);
        if (scanf("%d%c", &value, &term) != 2 || term != '\n' || value < min || value > max) {
            printf("Invalid input. Please try again.\n");
            clearBuffer(); // Clear any remaining characters in the buffer
        } else {
            return value;
        }
    }
}

// Function to clear the input buffer
void clearBuffer() {
    while (getchar() != '\n');  // Discard characters until a newline is found
}