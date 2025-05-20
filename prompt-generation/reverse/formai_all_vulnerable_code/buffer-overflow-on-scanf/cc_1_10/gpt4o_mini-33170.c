//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void displayMenu() {
    printf("\n=== Welcome to the Dice Roller ===\n");
    printf("1. Roll a single die\n");
    printf("2. Roll multiple dice\n");
    printf("3. Exit\n");
    printf("Choose an option (1-3): ");
}

int rollDie(int sides) {
    return (rand() % sides) + 1; 
}

void rollSingleDie() {
    int sides = 6;
    printf("\nRolling a %d-sided die...\n", sides);
    int result = rollDie(sides);
    printf("You rolled a: %d\n", result);
}

void rollMultipleDice() {
    int numDice, sides;
    printf("\nHow many dice do you want to roll? ");
    scanf("%d", &numDice);
    printf("How many sides do you want on each die? ");
    scanf("%d", &sides);
    
    printf("\nRolling %d %d-sided dice...\n", numDice, sides);
    for (int i = 0; i < numDice; i++) {
        int result = rollDie(sides);
        printf("Die %d rolled: %d\n", i + 1, result);
    }
}

void rollUntilExit() {
    char choice;
    do {
        displayMenu();
        scanf(" %c", &choice);
        switch (choice) {
            case '1':
                rollSingleDie();
                break;
            case '2':
                rollMultipleDice();
                break;
            case '3':
                printf("Thank you for using the Dice Roller!\n");
                break;
            default:
                printf("Invalid option! Please choose again.\n");
        }
    } while (choice != '3');
}

int main() {
    srand(time(NULL));
    rollUntilExit();
    return 0;
}