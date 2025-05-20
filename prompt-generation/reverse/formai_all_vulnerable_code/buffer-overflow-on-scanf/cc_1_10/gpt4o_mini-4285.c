//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void displayInstructions() {
    printf("Welcome to the Calm Dice Roller!\n");
    printf("You can roll various dice and see the results.\n");
    printf("Instructions:\n");
    printf("1. Choose the number of sides on the dice (4, 6, 8, 10, 12, 20)\n");
    printf("2. Choose the number of dice to roll.\n");
    printf("3. Type 'exit' to quit at any time.\n\n");
}

int rollDice(int sides) {
    return (rand() % sides) + 1;
}

void rollMultipleDice(int sides, int count) {
    int total = 0;
    printf("Rolling %d %d-sided dice...\n", count, sides);
    for (int i = 0; i < count; i++) {
        int roll = rollDice(sides);
        printf("Roll %d: %d\n", i + 1, roll);
        total += roll;
    }
    printf("Total: %d\n", total);
}

void selectDiceType() {
    while (1) {
        int sides, count;
        printf("\nChoose the number of sides on the dice (4, 6, 8, 10, 12, 20): ");
        scanf("%d", &sides);
        
        if (sides != 4 && sides != 6 && sides != 8 && sides != 10 && sides != 12 && sides != 20) {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        printf("How many dice would you like to roll? ");
        scanf("%d", &count);
        
        if (count <= 0) {
            printf("Please enter a positive number for the count of dice.\n");
            continue;
        }

        rollMultipleDice(sides, count);
    }
}

int main() {
    srand(time(NULL));
    displayInstructions();

    char command[10];
    while (1) {
        printf("Type 'roll' to start rolling dice or 'exit' to quit: ");
        scanf("%s", command);

        if (strcmp(command, "exit") == 0) {
            printf("Thank you for using the Calm Dice Roller. Goodbye!\n");
            break;
        } else if (strcmp(command, "roll") == 0) {
            selectDiceType();
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }

    return 0;
}