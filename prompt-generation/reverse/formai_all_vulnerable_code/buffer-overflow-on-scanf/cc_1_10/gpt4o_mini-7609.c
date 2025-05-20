//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROLL_HISTORY_SIZE 10

// Function declarations
void rollDice(int *roll);
void displayRollHistory(int rollHistory[], int count);
void clearScreen();
void displayMenu();
void logRoll(int rollHistory[], int *historyIndex, int roll);
int getChoice();
void handleRoll(int rollHistory[], int *historyIndex);

// Main function
int main() {
    srand(time(NULL)); // Seed the random number generator 

    int rollHistory[ROLL_HISTORY_SIZE] = {0};
    int historyIndex = 0;
    int choice;

    do {
        clearScreen();
        displayMenu();
        choice = getChoice();

        switch (choice) {
            case 1:
                handleRoll(rollHistory, &historyIndex);
                break;
            case 2:
                displayRollHistory(rollHistory, historyIndex);
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
        if (choice != 3) {
            printf("\nPress Enter to continue...");
            while(getchar() != '\n'); // Wait for user to press Enter
        }
    } while (choice != 3);

    return 0;
}

// Function to roll the dice
void rollDice(int *roll) {
    *roll = (rand() % 6) + 1; // Generate a random number between 1 and 6
}

// Function to display the roll history
void displayRollHistory(int rollHistory[], int count) {
    printf("\nRoll History:\n");
    if (count == 0) {
        printf("No rolls yet.\n");
    } else {
        for (int i = 0; i < count; i++) {
            printf("Roll %d: %d\n", i + 1, rollHistory[i]);
        }
    }
}

// Function to clear the screen
void clearScreen() {
    printf("\033[H\033[J"); // ANSI escape code to clear the screen
}

// Function to display the menu
void displayMenu() {
    printf("\n====== Dice Roller ======\n");
    printf("1. Roll the Dice\n");
    printf("2. View Roll History\n");
    printf("3. Exit\n");
    printf("=========================\n");
}

// Function to get user choice
int getChoice() {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Function to log the roll
void logRoll(int rollHistory[], int *historyIndex, int roll) {
    if (*historyIndex < ROLL_HISTORY_SIZE) {
        rollHistory[*historyIndex] = roll;
        (*historyIndex)++;
    } else {
        // Shift history to make space for new rolls
        for (int i = 1; i < ROLL_HISTORY_SIZE; i++) {
            rollHistory[i - 1] = rollHistory[i];
        }
        rollHistory[ROLL_HISTORY_SIZE - 1] = roll; // Add new roll at the end
    }
}

// Function to handle the rolling process
void handleRoll(int rollHistory[], int *historyIndex) {
    int roll;
    rollDice(&roll);
    printf("You rolled a %d!\n", roll);
    logRoll(rollHistory, historyIndex, roll);
}