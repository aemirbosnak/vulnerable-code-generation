//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void rollDice(int numDice);
void displayDice(int *dice, int numDice);
char getUserChoice();
void playGame();
void printRules();

int main() {
    srand(time(NULL));  // Seed for random number generation
    printf("Welcome to the Dice Roller Game!\n");
    printRules();
    
    char choice;
    do {
        playGame();
        printf("\nDo you want to play again? (y/n): ");
        choice = getUserChoice();
    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for playing the Dice Roller Game! Goodbye.\n");
    return 0;
}

// Function to display rules
void printRules() {
    printf("Rules:\n");
    printf("1. You can roll a specified number of dice (1-6).\n");
    printf("2. The game will display the result of each die rolled.\n");
    printf("3. You can choose to roll again or exit the game.\n");
}

// Function to roll the dice
void rollDice(int numDice) {
    int *dice = (int *)malloc(numDice * sizeof(int));
    if (dice == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    printf("Rolling %d dice...\n", numDice);
    for (int i = 0; i < numDice; i++) {
        dice[i] = (rand() % 6) + 1; // Random number between 1 and 6
    }
    displayDice(dice, numDice);
    free(dice);
}

// Function to display the rolled dice
void displayDice(int *dice, int numDice) {
    printf("You rolled: ");
    for (int i = 0; i < numDice; i++) {
        printf("%d ", dice[i]);
    }
    printf("\n");
}

// Function to get user choice for rolling dice
char getUserChoice() {
    char choice;
    scanf(" %c", &choice);
    return choice;
}

// Function to play the game
void playGame() {
    int numDice;
    
    // Get the number of dice to roll
    printf("Enter the number of dice (1-6) you want to roll: ");
    while (1) {
        scanf("%d", &numDice);
        if (numDice >= 1 && numDice <= 6) {
            break;
        } else {
            printf("Invalid input. Please enter a number between 1 and 6: ");
        }
    }
    
    rollDice(numDice);
}