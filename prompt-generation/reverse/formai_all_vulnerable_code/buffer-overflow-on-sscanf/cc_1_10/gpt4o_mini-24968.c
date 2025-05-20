//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printInstructions() {
    printf("Welcome to the Dice Roller!\n");
    printf("You can roll dice in the following format:\n");
    printf("1. Roll a single die (e.g., 1d6)\n");
    printf("2. Roll multiple dice (e.g., 3d10)\n");
    printf("3. To exit the program, type 'exit'.\n");
    printf("4. To view past rolls, type 'history'.\n");
}

int rollDice(int sides) {
    return (rand() % sides) + 1;
}

void addRollToHistory(char *history, int roll) {
    char buffer[50];
    snprintf(buffer, sizeof(buffer), "%d ", roll);
    strncat(history, buffer, sizeof(history) - strlen(history) - 1);
}

void displayHistory(char *history) {
    printf("Roll History: %s\n", history[0] ? history : "No rolls yet.");
}

int main() {
    srand(time(0));
    char input[100];
    char history[500] = "";

    printInstructions();

    while (1) {
        printf("Enter your roll: ");
        fgets(input, sizeof(input), stdin);
        
        // Remove newline character if present
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "exit") == 0) {
            printf("Thanks for using the Dice Roller! Goodbye!\n");
            break;
        } else if (strcmp(input, "history") == 0) {
            displayHistory(history);
            continue;
        }

        int numDice = 0, numSides = 0;
        if (sscanf(input, "%dd%d", &numDice, &numSides) == 2 && numDice > 0 && numSides > 0) {
            printf("Rolling %d dice with %d sides:\n", numDice, numSides);
            for (int i = 0; i < numDice; i++) {
                int roll = rollDice(numSides);
                printf("Roll %d: %d\n", i + 1, roll);
                addRollToHistory(history, roll);
            }
        } else {
            printf("Invalid input format. Please use the format 'XdY' to roll dice (e.g., 2d6).\n");
        }
    }
    
    return 0;
}