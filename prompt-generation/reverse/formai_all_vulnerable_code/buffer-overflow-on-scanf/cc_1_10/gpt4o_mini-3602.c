//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 10
#define MAX_SIDES 20

void printWelcomeMessage() {
    printf("Welcome to the Intelligent Dice Roller!\n");
    printf("You can roll up to %d dice with %d sides each.\n", MAX_DICE, MAX_SIDES);
    printf("Let's get started!\n\n");
}

void displayInstructions() {
    printf("Instructions:\n");
    printf("1. Enter the number of dice to roll (1 to %d).\n", MAX_DICE);
    printf("2. Enter the number of sides on each die (2 to %d).\n", MAX_SIDES);
    printf("3. Press Enter to roll the dice!\n\n");
}

int getUserInput(const char *prompt, int min, int max) {
    int input;

    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &input) != 1 || input < min || input > max) {
            printf("Invalid input. Please enter a value between %d and %d.\n", min, max);
            while (getchar() != '\n'); // Clear the buffer
        } else {
            break;
        }
    }

    return input;
}

int rollDie(int sides) {
    return (rand() % sides) + 1; // Random number between 1 and 'sides'
}

void rollDice(int numDice, int sides) {
    printf("\nRolling %d dice with %d sides...\n", numDice, sides);
    for (int i = 0; i < numDice; i++) {
        int result = rollDie(sides);
        printf("Die %d: %d\n", i + 1, result);
    }
}

void menu() {
    int numDice, sides;

    while (1) {
        numDice = getUserInput("\nEnter the number of dice to roll: ", 1, MAX_DICE);
        sides = getUserInput("Enter the number of sides on each die: ", 2, MAX_SIDES);
        
        rollDice(numDice, sides);
        
        printf("\nDo you want to roll again? (1 for Yes, 0 for No): ");
        int again;
        scanf("%d", &again);
        if (again != 1) {
            printf("Thank you for using the Intelligent Dice Roller. Goodbye!\n");
            break;
        }
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    printWelcomeMessage();
    displayInstructions();
    menu();

    return 0;
}