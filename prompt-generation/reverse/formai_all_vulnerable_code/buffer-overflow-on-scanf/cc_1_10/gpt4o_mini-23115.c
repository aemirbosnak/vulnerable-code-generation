//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROLLS 100

typedef struct {
    int number;
    int frequency;
} DiceRoll;

void initializeDiceRolls(DiceRoll rolls[]) {
    for (int i = 0; i < 6; i++) {
        rolls[i].number = i + 1;
        rolls[i].frequency = 0;
    }
}

int rollDice() {
    return (rand() % 6) + 1;
}

void updateFrequency(DiceRoll rolls[], int result) {
    if (result >= 1 && result <= 6) {
        rolls[result - 1].frequency++;
    }
}

void displayFrequencies(DiceRoll rolls[]) {
    printf("\nDice Roll Frequencies:\n");
    for (int i = 0; i < 6; i++) {
        printf("Number %d: %d times\n", rolls[i].number, rolls[i].frequency);
    }
}

void displayHistogram(DiceRoll rolls[]) {
    printf("\nHistogram of Rolls:\n");
    for (int i = 0; i < 6; i++) {
        printf("%d: ", rolls[i].number);
        for (int j = 0; j < rolls[i].frequency; j++) {
            printf("#");
        }
        printf("\n");
    }
}

void displayMenu() {
    printf("\nDice Roller Menu:\n");
    printf("1. Roll the dice\n");
    printf("2. View roll statistics\n");
    printf("3. View histogram of rolls\n");
    printf("4. Exit\n");
    printf("Select an option: ");
}

int main() {
    srand(time(NULL));
    DiceRoll rolls[6];
    initializeDiceRolls(rolls);
    
    int rollsCount = 0;
    int option;
    
    while (1) {
        displayMenu();
        scanf("%d", &option);

        switch (option) {
            case 1: {
                if (rollsCount >= MAX_ROLLS) {
                    printf("Maximum rolls reached. Please view statistics or reset.\n");
                    break;
                }
                
                int result = rollDice();
                printf("You rolled a %d!\n", result);
                updateFrequency(rolls, result);
                rollsCount++;
                break;
            }
            case 2:
                displayFrequencies(rolls);
                break;
            case 3:
                displayHistogram(rolls);
                break;
            case 4:
                printf("Exiting Dice Roller. Thank you for playing!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}