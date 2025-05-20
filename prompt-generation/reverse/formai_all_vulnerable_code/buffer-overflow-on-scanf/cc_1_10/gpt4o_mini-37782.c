//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DICE_SIDES 6
#define NUMBER_OF_DICE 2

void rollDice(int *dice) {
    for (int i = 0; i < NUMBER_OF_DICE; i++) {
        dice[i] = (rand() % DICE_SIDES) + 1;  // Roll the dice (1 to DICE_SIDES)
    }
}

void displayResult(int *dice) {
    printf("You rolled: ");
    for (int i = 0; i < NUMBER_OF_DICE; i++) {
        printf("%d ", dice[i]);
    }
    printf("\n");
    
    int total = 0;
    for (int i = 0; i < NUMBER_OF_DICE; i++) {
        total += dice[i];
    }
    printf("Total: %d\n", total);
}

char getUserChoice() {
    char choice;
    printf("Do you want to roll the dice? (y/n): ");
    while (1) {
        scanf(" %c", &choice);
        if (choice == 'y' || choice == 'n') {
            break;
        }
        printf("Invalid choice! Please enter 'y' or 'n': ");
    }
    return choice;
}

void displayShockMessage() {
    printf("Oh my goodness! Did that just happen? ");
    printf("These are the wild rolls of fate!\n");
}

int main() {
    srand(time(NULL));  // Initialize random seed
    int dice[NUMBER_OF_DICE];
    char choice;

    printf("Welcome to the Shock Dice Roller!\n");

    while (1) {
        displayShockMessage();
        rollDice(dice);
        displayResult(dice);
        
        choice = getUserChoice();
        if (choice == 'n') {
            printf("Thanks for playing! Until next time, may fortune favor you!\n");
            break;
        } else {
            printf("Rolling again... Prepare for the unexpected!\n");
        }
    }

    return 0;
}