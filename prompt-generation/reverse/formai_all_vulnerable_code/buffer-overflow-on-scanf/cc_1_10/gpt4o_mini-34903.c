//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE    10
#define MAX_SIDES   20

void clearConsole() {
    printf("\033[H\033[J");
}

void displayWelcomeMessage() {
    clearConsole();
    printf("Welcome to the C Dice Roller!\n");
    printf("Roll up to %d dice with up to %d sides each.\n", MAX_DICE, MAX_SIDES);
    printf("Type 'exit' to quit the program.\n\n");
}

void displayMenu() {
    printf("Menu:\n");
    printf("1. Roll Dice\n");
    printf("2. Roll Multiple Dice\n");
    printf("3. Exit\n");
    printf("Choose an option (1-3): ");
}

int rollDie(int sides) {
    return (rand() % sides) + 1; // returns a value between 1 and sides
}

void rollSingleDie() {
    int sides;
    printf("Enter the number of sides on the die (2-%d): ", MAX_SIDES);
    scanf("%d", &sides);

    if(sides < 2 || sides > MAX_SIDES) {
        printf("Invalid number of sides! Please choose between 2 and %d.\n", MAX_SIDES);
        return;
    }

    int result = rollDie(sides);
    printf("You rolled a %d on a %d-sided die!\n", result, sides);
}

void rollMultipleDice() {
    int numDice, sides;

    printf("Enter the number of dice to roll (1-%d): ", MAX_DICE);
    scanf("%d", &numDice);
    if (numDice < 1 || numDice > MAX_DICE) {
        printf("Invalid number of dice! Please choose between 1 and %d.\n", MAX_DICE);
        return;
    }

    printf("Enter the number of sides on each die (2-%d): ", MAX_SIDES);
    scanf("%d", &sides);
    if(sides < 2 || sides > MAX_SIDES) {
        printf("Invalid number of sides! Please choose between 2 and %d.\n", MAX_SIDES);
        return;
    }

    printf("You rolled:\n");
    for(int i = 0; i < numDice; i++) {
        int result = rollDie(sides);
        printf("Die %d: %d\n", i + 1, result);
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    int choice;

    displayWelcomeMessage();

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                rollSingleDie();
                break;
            case 2:
                rollMultipleDice();
                break;
            case 3:
                printf("Thank you for using the C Dice Roller. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please select an option from the menu.\n");
        }
        printf("\nPress Enter to continue...\n");
        while(getchar() != '\n'); // Wait for the user to press Enter
        getchar(); // Additionally get the Enter key
    }

    return 0;
}