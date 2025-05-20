//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_DICE 10
#define MAX_SIDES 20

typedef struct {
    int sides;
    int count;
} Dice;

void initializeDice(Dice *dice, int count, int sides) {
    dice->sides = sides;
    dice->count = count;
}

void rollDice(Dice *dice, int results[]) {
    for (int i = 0; i < dice->count; i++) {
        results[i] = (rand() % dice->sides) + 1;
    }
}

void printResults(Dice *dice, int results[]) {
    printf("Rolling %d D%d...\n", dice->count, dice->sides);
    for (int i = 0; i < dice->count; i++) {
        printf("Roll %d: %d\n", i + 1, results[i]);
    }
}

void calculateTotal(Dice *dice, int results[]) {
    int total = 0;
    for (int i = 0; i < dice->count; i++) {
        total += results[i];
    }
    printf("Total: %d\n", total);
}

void futuristicTheme() {
    printf("===================================\n");
    printf("    Welcome to the Quantum Dice    \n");
    printf("         Roller Interface          \n");
    printf("           Version 2099            \n");
    printf("===================================\n");
}

void showInstructions() {
    printf("Instructions:\n");
    printf("1. Enter the number of dice to roll (1 to %d).\n", MAX_DICE);
    printf("2. Enter the number of sides for the dice (1 to %d).\n", MAX_SIDES);
    printf("3. Press ENTER to roll the dice.\n");
}

int main() {
    srand(time(NULL));
    futuristicTheme();
    showInstructions();

    int diceCount, diceSides, continueRolling = 1;
    Dice dice;
    int results[MAX_DICE];

    while (continueRolling) {
        printf("Enter number of dice (1-%d): ", MAX_DICE);
        scanf("%d", &diceCount);
        if (diceCount < 1 || diceCount > MAX_DICE) {
            printf("Invalid number of dice! Please try again.\n");
            continue;
        }

        printf("Enter the number of sides on the dice (1-%d): ", MAX_SIDES);
        scanf("%d", &diceSides);
        if (diceSides < 1 || diceSides > MAX_SIDES) {
            printf("Invalid number of sides! Please try again.\n");
            continue;
        }

        initializeDice(&dice, diceCount, diceSides);
        rollDice(&dice, results);
        printResults(&dice, results);
        calculateTotal(&dice, results);

        char continueChoice[3];
        printf("Do you wish to roll again? (yes/no): ");
        scanf("%s", continueChoice);
        if (strcasecmp(continueChoice, "no") == 0) {
            continueRolling = 0;
        }
    }

    printf("Thank you for using the Quantum Dice Roller!\n");
    printf("Have a wonderful day in the cosmos!\n");
    return 0;
}