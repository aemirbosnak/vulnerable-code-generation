//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_DICE 5
#define NUM_SIDES 6

void rollDice(int dice[], int numDice) {
    for (int i = 0; i < numDice; i++) {
        dice[i] = (rand() % NUM_SIDES) + 1; // Roll the die
    }
}

void displayDice(int dice[], int numDice) {
    printf("You rolled: ");
    for (int i = 0; i < numDice; i++) {
        printf("[%d] ", dice[i]);
    }
    printf("\n");
}

void calculateScore(int dice[], int numDice) {
    int score = 0;
    for (int i = 0; i < numDice; i++) {
        score += dice[i]; // Sum up the score of all dice
    }
    printf("Your total score is: %d\n", score);
}

void playRound() {
    int dice[NUM_DICE];
    rollDice(dice, NUM_DICE);
    displayDice(dice, NUM_DICE);
    calculateScore(dice, NUM_DICE);
}

char getMenuChoice() {
    char choice;
    printf("\n--- Dice Roller Menu ---\n");
    printf("1. Roll Dice\n");
    printf("2. Exit\n");
    printf("Choose an option (1-2): ");
    scanf(" %c", &choice);
    return choice;
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    char choice;

    while (1) {
        choice = getMenuChoice();
        switch (choice) {
            case '1':
                playRound();
                break;
            case '2':
                printf("Thank you for playing! Goodbye.\n");
                return 0;
            default:
                printf("Invalid option! Please enter 1 or 2.\n");
                break;
        }
    }
    
    return 0;
}