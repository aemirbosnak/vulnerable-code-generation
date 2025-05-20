//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROLLS 100

typedef struct {
    int rollNumber;
    int rolledValue;
} RollHistory;

void rollDice(int diceCount, RollHistory *history, int *index);
void displayHistory(RollHistory *history, int count);
void displayMenu();
void clearInputBuffer();

int main() {
    int diceCount, rollAgain, index = 0;
    RollHistory history[MAX_ROLLS];
    
    // Seed the random number generator
    srand(time(NULL));

    printf("Welcome to the Brave Dice Roller!\n");
    printf("You will be able to roll multiple dice and keep track of your rolls.\n");

    do {
        displayMenu();
        printf("Enter the number of dice to roll (1 to 6): ");
        scanf("%d", &diceCount);
        
        while (diceCount < 1 || diceCount > 6) {
            printf("Invalid number of dice. Please enter a number between 1 and 6: ");
            scanf("%d", &diceCount);
        }

        rollDice(diceCount, history, &index);
        
        printf("Would you like to roll again? (1 for Yes, 0 for No): ");
        scanf("%d", &rollAgain);
        
        clearInputBuffer();
        
    } while (rollAgain == 1 && index < MAX_ROLLS);
    
    printf("Thank you for using the Brave Dice Roller! Here is your rolling history:\n");
    displayHistory(history, index);
    
    return 0;
}

void rollDice(int diceCount, RollHistory *history, int *index) {
    int totalValue = 0;
    printf("Rolling %d dice...\n", diceCount);
    
    for (int i = 0; i < diceCount; i++) {
        int rolledValue = (rand() % 6) + 1; // Roll a die
        totalValue += rolledValue;
        printf("Die %d rolled a %d\n", i + 1, rolledValue);
        
        // Save the roll history
        if (*index < MAX_ROLLS) {
            history[*index].rollNumber = *index + 1;
            history[*index].rolledValue = rolledValue;
            (*index)++;
        }
    }
    
    printf("Total value rolled: %d\n\n", totalValue);
}

void displayHistory(RollHistory *history, int count) {
    if (count == 0) {
        printf("No rolls to display.\n");
        return;
    }
    
    printf("Rolling History:\n");
    for (int i = 0; i < count; i++) {
        printf("Roll %d: Rolled Value = %d\n", history[i].rollNumber, history[i].rolledValue);
    }
}

void displayMenu() {
    printf("\n**** Dice Roller Menu ****\n");
    printf("1. Roll Dice\n");
    printf("2. View Roll History\n");
    printf("3. Exit\n");
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}