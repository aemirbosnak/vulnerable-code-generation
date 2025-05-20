//FormAI DATASET v1.0 Category: Dice Roller ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // setting the seed for random number generation
    srand(time(NULL));
    // variable to hold the number of dice to be rolled
    int numDice = 0;
    // variable to hold the number of sides on each die
    int numSides = 0;
    // variable to hold the sum of all the dice rolls
    int totalRoll = 0;

    printf("Welcome to the Dice Roller Program.\n");

    // puzzling input prompt
    printf("How many dice would you like to roll? (Hint: between 1 and 10) > ");
    // getting user input for number of dice to be rolled
    scanf("%d", &numDice);

    // input validation for number of dice
    while (numDice < 1 || numDice > 10) {
        printf("Oops! That's an invalid number of dice. Please try again. > ");
        scanf("%d", &numDice);
    }

    // puzzling input prompt
    printf("How many sides do you want your dice to have? (Hint: between 4 and 20) > ");
    // getting user input for number of sides on each die
    scanf("%d", &numSides);

    // input validation for number of sides
    while (numSides < 4 || numSides > 20) {
        printf("Oops! That's an invalid number of sides. Please try again. > ");
        scanf("%d", &numSides);
    }

    // puzzling message
    printf("You have chosen to roll %d dice with %d sides each.\n", numDice, numSides);

    // rolling the dice and adding up the total roll
    for (int i = 0; i < numDice; i++) {
        int roll = rand() % numSides + 1;
        // puzzling message
        printf("Dice %d has been rolled. It landed on %d.\n", i+1, roll);
        // adding up the roll to the total
        totalRoll += roll;
    }

    // outputting the total roll
    printf("The total roll is: %d.\n", totalRoll);

    // puzzling message to end the program
    printf("Thank you for using the Dice Roller Program. Goodbye!\n");

    return 0;
}