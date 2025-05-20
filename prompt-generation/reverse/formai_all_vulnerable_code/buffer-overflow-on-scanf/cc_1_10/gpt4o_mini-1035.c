//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void displayMenu() {
    printf("======= Dice Roller =======\n");
    printf("1. Roll a single die\n");
    printf("2. Roll multiple dice\n");
    printf("3. Roll custom dice\n");
    printf("4. Exit\n");
    printf("==========================\n");
}

int rollSingleDie() {
    return rand() % 6 + 1;
}

int rollMultipleDice(int numDice) {
    int total = 0;
    for (int i = 0; i < numDice; i++) {
        total += rollSingleDie();
    }
    return total;
}

int rollCustomDie(int sides) {
    return rand() % sides + 1;
}

int rollCustomDice(int numDice, int sides) {
    int total = 0;
    for (int i = 0; i < numDice; i++) {
        total += rollCustomDie(sides);
    }
    return total;
}

void handleSingleDie() {
    printf("Rolling a single six-sided die...\n");
    int result = rollSingleDie();
    printf("You rolled: %d\n", result);
}

void handleMultipleDice() {
    int numDice;
    printf("Enter the number of dice to roll: ");
    scanf("%d", &numDice);
    if(numDice <= 0) {
        printf("Invalid number of dice. Must be at least 1.\n");
        return;
    }
    printf("Rolling %d six-sided dice...\n", numDice);
    int result = rollMultipleDice(numDice);
    printf("Total roll: %d\n", result);
}

void handleCustomDice() {
    int numDice, sides;
    printf("Enter the number of dice to roll: ");
    scanf("%d", &numDice);
    printf("Enter the number of sides on each die: ");
    scanf("%d", &sides);
    
    if(numDice <= 0 || sides <= 0) {
        printf("Invalid input. Must have at least 1 die and 1 side.\n");
        return;
    }
    
    printf("Rolling %d %d-sided dice...\n", numDice, sides);
    int result = rollCustomDice(numDice, sides);
    printf("Total roll: %d\n", result);
}

int main() {
    srand(time(NULL));  // Seed the random number generator
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                handleSingleDie();
                break;
            case 2:
                handleMultipleDice();
                break;
            case 3:
                handleCustomDice();
                break;
            case 4:
                printf("Exiting the Dice Roller. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        printf("\n");
    }

    return 0;
}