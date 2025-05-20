//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIDES 20
#define MIN_SIDES 4

void printInstructions() {
    printf("Welcome to the C Dice Roller!\n");
    printf("----------------------------------\n");
    printf("This program simulates rolling a dice of various sides.\n");
    printf("You can choose the number of sides for your dice between %d and %d.\n", MIN_SIDES, MAX_SIDES);
    printf("To roll the dice, simply enter how many times you wish to roll it.\n");
    printf("Enter -1 to exit the program.\n");
    printf("----------------------------------\n");
}

int rollDice(int sides) {
    return (rand() % sides) + 1;
}

void rollMultipleDice(int sides, int rolls) {
    printf("Rolling a %d-sided dice %d times:\n", sides, rolls);
    for (int i = 0; i < rolls; i++) {
        int roll = rollDice(sides);
        printf("Roll %d: %d\n", i + 1, roll);
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    int sides, rolls;

    printInstructions();

    while (1) {
        printf("\nEnter the number of sides for your dice (between %d and %d): ", MIN_SIDES, MAX_SIDES);
        scanf("%d", &sides);

        if (sides == -1) {
            printf("Exiting the program. Thank you for playing!\n");
            break;
        }

        if (sides < MIN_SIDES || sides > MAX_SIDES) {
            printf("Invalid number of sides. Please try again.\n");
            continue;
        }

        printf("How many times would you like to roll the %d-sided dice? (Enter -1 to exit): ", sides);
        scanf("%d", &rolls);

        if (rolls == -1) {
            printf("Exiting the program. Thank you for playing!\n");
            break;
        }

        if (rolls <= 0) {
            printf("Please enter a positive number of rolls.\n");
            continue;
        }

        rollMultipleDice(sides, rolls);
    }

    return 0;
}