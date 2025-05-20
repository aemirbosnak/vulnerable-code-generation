//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_DICE 5

void rollDice(int dice[], int numDice);
void printRoll(int dice[], int numDice);
int getValidInput();
void displayInstructions();

int main() {
    int dice[MAX_DICE];
    int numDice;
    char choice;

    // Initializing random seed
    srand(time(NULL));

    printf("***************************************************\n");
    printf("Welcome to the Post-Apocalyptic Dice Roller!\n");
    printf("In the wasteland, you’ll need luck to survive.\n");
    printf("***************************************************\n");
    
    displayInstructions();

    do {
        // Get the number of dice to roll
        printf("Enter the number of dice to roll (1-%d): ", MAX_DICE);
        numDice = getValidInput();

        // Roll the dice and print the results
        rollDice(dice, numDice);
        printRoll(dice, numDice);

        // Ask if the player wants to roll again
        printf("Do you wish to roll again? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
    
    printf("Survive the wasteland. Until next time!\n");
    return 0;
}

void rollDice(int dice[], int numDice) {
    for (int i = 0; i < numDice; i++) {
        dice[i] = (rand() % 6) + 1; // Roll a die (1-6)
    }
}

void printRoll(int dice[], int numDice) {
    printf("You rolled: ");
    for (int i = 0; i < numDice; i++) {
        printf("%d ", dice[i]);
    }
    printf("\n");
}

int getValidInput() {
    int num;
    while (1) {
        scanf("%d", &num);
        if (num >= 1 && num <= MAX_DICE) {
            return num;
        } else {
            printf("Invalid input. Please enter a number between 1 and %d: ", MAX_DICE);
        }
    }
}

void displayInstructions() {
    printf("Instructions:\n");
    printf("1. Enter the number of dice you want to roll.\n");
    printf("2. Each die will yield a number between 1 and 6, reflecting your fate.\n");
    printf("3. Roll as many times as you wish, but be wary of the unknown dangers of the wasteland.\n");
    printf("***************************************************\n");
}