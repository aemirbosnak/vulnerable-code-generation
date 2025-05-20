//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printInstructions() {
    printf("Welcome to the Dice Roller!\n");
    printf("You can roll dice in the format 'XdY' where:\n");
    printf("X = number of dice to roll\n");
    printf("Y = number of sides on each die\n");
    printf("For example, to roll 3 six-sided dice, type '3d6'.\n");
    printf("Type 'exit' to quit.\n");
}

int rollDice(int numberOfDice, int sides) {
    int total = 0;
    for (int i = 0; i < numberOfDice; i++) {
        total += (rand() % sides) + 1; // Roll the dice
    }
    return total;
}

int parseInput(const char *input, int *numberOfDice, int *sides) {
    if (sscanf(input, "%dd%d", numberOfDice, sides) != 2) {
        return 0; // Failed to parse input
    }
    return 1; // Succeeded in parsing input
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    char input[20];
    int numberOfDice, sides;

    printInstructions();

    while (1) {
        printf("Enter your roll (or type 'exit' to quit): ");
        fgets(input, sizeof(input), stdin);
        
        // Remove newline character from input
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }

        if (strcmp(input, "exit") == 0) {
            printf("Thank you for using the Dice Roller! Goodbye.\n");
            break;
        }

        if (parseInput(input, &numberOfDice, &sides)) {
            if (numberOfDice > 0 && sides > 0) {
                int result = rollDice(numberOfDice, sides);
                printf("You rolled %d %d-sided dice. Total: %d\n", numberOfDice, sides, result);
            } else {
                printf("Please enter positive integers for the number of dice and sides.\n");
            }
        } else {
            printf("Invalid input format. Please use the format 'XdY'.\n");
        }
    }

    return 0;
}