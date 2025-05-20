//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function Prototypes
void printWelcome();
int rollDice(int sides);
void displayRolls(int diceCount, int sides);
void rollMultipleDice();
void exitProgram();

int main() {
    printWelcome();
    
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Roll Dice\n");
        printf("2. Roll Multiple Dice\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayRolls(1, 6); // Default to 1d6
                break;
            case 2:
                rollMultipleDice();
                break;
            case 3:
                exitProgram();
                break;
            default:
                printf("Invalid choice! Please select again.\n");
                break;
        }
    } while (choice != 3);
    
    return 0;
}

// Function Definitions

void printWelcome() {
    printf("**********************************\n");
    printf("*          Dice Roller           *\n");
    printf("**********************************\n");
    printf("Welcome to the Dice Roller Program!\n");
    printf("Let's have some fun rolling dice!\n");
}

int rollDice(int sides) {
    return (rand() % sides) + 1;
}

void displayRolls(int diceCount, int sides) {
    printf("\nRolling %d D%d...\n", diceCount, sides);
    
    int total = 0;
    for (int i = 0; i < diceCount; i++) {
        int roll = rollDice(sides);
        total += roll;
        printf("Roll %d: %d\n", i + 1, roll);
    }
    
    printf("Total: %d\n", total);
}

void rollMultipleDice() {
    int diceCount, sides;

    printf("Enter the number of dice to roll (e.g., 3 for 3d6): ");
    scanf("%d", &diceCount);
    
    if (diceCount <= 0) {
        printf("Number of dice must be greater than zero.\n");
        return;
    }
    
    printf("Enter the number of sides on the dice (e.g., 6 for D6): ");
    scanf("%d", &sides);
    
    if (sides <= 0) {
        printf("Number of sides must be greater than zero.\n");
        return;
    }
    
    displayRolls(diceCount, sides);
}

void exitProgram() {
    printf("Thank you for using the Dice Roller program!\n");
    printf("Goodbye!\n");
    exit(0);
}

// Random number seeding
void initializeRandom() {
    srand(time(NULL));
}