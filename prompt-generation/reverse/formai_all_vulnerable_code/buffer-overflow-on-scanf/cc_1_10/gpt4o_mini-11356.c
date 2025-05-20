//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shapeRoll(int rollResult);
void displayBoundaries(int sides);
int getUserInput();

int main() {
    int rolls; // Number of times to roll the die
    int sides = 6; // Number of sides on the die
    char repeat = 'y';

    // Seed the random number generator
    srand(time(0));

    printf("Welcome to the Shape-Shift Dice Roller!\n");
    printf("A world where every roll transforms!\n");

    while (repeat == 'y' || repeat == 'Y') {
        rolls = getUserInput();

        // Perform the rolls
        for (int i = 1; i <= rolls; i++) {
            int rollResult = (rand() % sides) + 1; // Roll the die
            shapeRoll(rollResult); // Display the rolled shape
        }

        // Ask user if they want to roll again
        printf("\nDo you want to roll again? (y/n): ");
        scanf(" %c", &repeat);
    }

    printf("Thank you for using the Shape-Shift Dice Roller. Goodbye!\n");
    return 0;
}

int getUserInput() {
    int rolls;
    printf("How many times would you like to roll the dice? ");
    scanf("%d", &rolls);

    while (rolls <= 0) {
        printf("Please enter a positive integer: ");
        scanf("%d", &rolls);
    }
    return rolls;
}

void shapeRoll(int rollResult) {
    // Display boundaries based on sides of the die
    displayBoundaries(rollResult);

    // Display the result in shape-shifting style
    switch (rollResult) {
        case 1:
            printf("    *\n");
            printf("   * *\n");
            printf("    *\n");
            break;
        case 2:
            printf(" *     *\n");
            printf("   * *\n");
            printf(" *     *\n");
            break;
        case 3:
            printf(" *     *\n");
            printf("    *\n");
            printf(" * * * * *\n");
            break;
        case 4:
            printf(" * *   * *\n");
            printf(" *     *\n");
            printf(" * *   * *\n");
            break;
        case 5:
            printf(" * * * * *\n");
            printf("    *\n");
            printf(" *     *\n");
            break;
        case 6:
            printf(" * * * * *\n");
            printf(" * *   * *\n");
            printf(" * * * * *\n");
            break;
        default:
            printf("An unexpected number appeared!\n");
            break;
    }
    printf("You rolled: %d\n", rollResult);
}

void displayBoundaries(int sides) {
    printf("\n===================\n");
    printf(" Rolling a %d-sided die!\n", sides);
    printf("===================\n");
}