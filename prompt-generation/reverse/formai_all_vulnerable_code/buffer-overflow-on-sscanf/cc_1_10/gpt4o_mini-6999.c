//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 10

void printInstructions() {
    printf("Welcome to the Ultimate Dice Roller!\n");
    printf("You can roll up to %d dice.\n", MAX_DICE);
    printf("Enter the number of dice to roll (1-%d) and the type of dice (e.g., 6 for a d6):\n", MAX_DICE);
    printf("Type 'exit' to quit the program.\n");
}

void rollDice(int numberOfDice, int diceType) {
    int i;
    int total = 0;
    printf("Rolling %d d%d:\n", numberOfDice, diceType);
    for (i = 0; i < numberOfDice; i++) {
        int roll = (rand() % diceType) + 1; // Rolling a dice
        printf("Roll %d: %d\n", i + 1, roll);
        total += roll;
    }
    printf("Total: %d\n", total);
}

int main() {
    char input[50];
    int numberOfDice, diceType;

    // Seed the random number generator
    srand(time(NULL));

    printInstructions();

    while (1) {
        printf("\nEnter your request (e.g., '2 6' for two d6 rolls): ");
        fgets(input, sizeof(input), stdin);

        // Check for exit command
        if (strncmp(input, "exit", 4) == 0) {
            printf("Thank you for using the Ultimate Dice Roller! Goodbye!\n");
            break;
        }
        
        // Parse input
        if (sscanf(input, "%d %d", &numberOfDice, &diceType) != 2) {
            printf("Invalid input! Please enter a valid command.\n");
            continue;
        }

        // Input validation
        if (numberOfDice < 1 || numberOfDice > MAX_DICE) {
            printf("Please enter a number of dice between 1 and %d.\n", MAX_DICE);
            continue;
        }
        
        if (diceType < 2) {
            printf("Please enter a valid dice type (minimum 2).\n");
            continue;
        }
        
        rollDice(numberOfDice, diceType);
    }

    return 0;
}