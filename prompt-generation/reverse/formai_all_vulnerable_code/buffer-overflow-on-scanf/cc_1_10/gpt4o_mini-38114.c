//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 10

// Function prototypes
void rollDice(int diceCount);
void displayResults(int results[], int diceCount);
void enterDiceCount(int *diceCount);
void clearScreen();

int main() {
    int diceCount = 0;
    char playAgain;

    // Seed the random number generator
    srand(time(NULL));

    do {
        clearScreen();
        enterDiceCount(&diceCount);
        if(diceCount > MAX_DICE) {
            printf("The maximum number of dice you can roll is %d.\n", MAX_DICE);
            continue;
        }

        rollDice(diceCount); // Roll the dice
        printf("Do you want to roll again (y/n)? ");
        scanf(" %c", &playAgain);
    } while(playAgain == 'y' || playAgain == 'Y');

    printf("Thank you for using the Dice Roller!\n");
    return 0;
}

// Function to roll dice
void rollDice(int diceCount) {
    int results[MAX_DICE] = {0};

    // Roll the dice and store the results
    for (int i = 0; i < diceCount; ++i) {
        results[i] = (rand() % 6) + 1; // Dice roll generates a number between 1 and 6
    }

    // Display the rolled results
    displayResults(results, diceCount);
}

// Function to display the rolled results
void displayResults(int results[], int diceCount) {
    printf("You rolled %d dice:\n", diceCount);
    for (int i = 0; i < diceCount; ++i) {
        printf("Dice %d: %d\n", i + 1, results[i]);
    }

    int sum = 0;
    for (int i = 0; i < diceCount; ++i) {
        sum += results[i];
    }
    printf("Total rolled: %d\n", sum);
}

// Function to enter the number of dice to roll
void enterDiceCount(int *diceCount) {
    printf("Enter the number of dice to roll (1 to %d): ", MAX_DICE);
    scanf("%d", diceCount);
}

// Function to clear the screen
void clearScreen() {
    // ANSI escape code to clear the console screen
    printf("\033[H\033[J");
}