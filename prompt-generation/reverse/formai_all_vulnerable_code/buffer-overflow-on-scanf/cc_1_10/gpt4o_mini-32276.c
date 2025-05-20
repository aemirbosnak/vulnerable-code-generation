//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_HISTORY 100

typedef struct {
    int roll;
    int numDice;
    int numSides;
} RollHistory;

RollHistory history[MAX_HISTORY];
int historyCount = 0;

void clearHistory() {
    historyCount = 0;
    printf("Roll history cleared.\n");
}

void showHistory() {
    if (historyCount == 0) {
        printf("No history available.\n");
        return;
    }

    printf("\nRoll History:\n");
    for (int i = 0; i < historyCount; i++) {
        printf("Roll %d: %d (Dice: %d, Sides: %d)\n", 
               i + 1, history[i].roll, history[i].numDice, history[i].numSides);
    }
    printf("\n");
}

int rollDice(int numDice, int numSides) {
    int totalRoll = 0;

    for (int i = 0; i < numDice; i++) {
        totalRoll += (rand() % numSides) + 1; // Dice rolls are 1-indexed
    }

    // Store in history
    if (historyCount < MAX_HISTORY) {
        history[historyCount].roll = totalRoll;
        history[historyCount].numDice = numDice;
        history[historyCount].numSides = numSides;
        historyCount++;
    } else {
        // If history is full, overwrite the oldest entry
        for (int i = 1; i < MAX_HISTORY; i++) {
            history[i - 1] = history[i];
        }
        history[MAX_HISTORY - 1].roll = totalRoll;
        history[MAX_HISTORY - 1].numDice = numDice;
        history[MAX_HISTORY - 1].numSides = numSides;
    }

    return totalRoll;
}

void displayMenu() {
    printf("\n--- Dice Roller Menu ---\n");
    printf("1. Roll Dice\n");
    printf("2. Show Roll History\n");
    printf("3. Clear Roll History\n");
    printf("4. Exit\n");
    printf("------------------------\n");
}

int main() {
    int choice, numDice, numSides, result;

    // Seed the random number generator
    srand(time(NULL)); 

    do {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of dice to roll: ");
                scanf("%d", &numDice);
                printf("Enter the number of sides on each die: ");
                scanf("%d", &numSides);
                if (numDice < 1 || numSides < 1) {
                    printf("Please enter valid numbers for dice and sides.\n");
                } else {
                    result = rollDice(numDice, numSides);
                    printf("You rolled a total of: %d\n", result);
                }
                break;
            case 2:
                showHistory();
                break;
            case 3:
                clearHistory();
                break;
            case 4:
                printf("Exiting the Dice Roller. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    } while (choice != 4);

    return 0;
}