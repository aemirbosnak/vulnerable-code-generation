//FormAI DATASET v1.0 Category: Dice Roller ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Declare variables
    int numDice, numSides, rollTotal = 0;
    char response;

    // Begin paranoia
    printf("Welcome to the Dice Roller program. Please answer the following questions carefully.\n");

    // Prompt for number of dice
    printf("How many dice would you like to roll? ");
    scanf("%d", &numDice);

    // Check if input is suspiciously high
    if(numDice >= 100) {
        printf("ERROR: That's too many dice. We don't have enough memory for that. Program aborted.\n");
        return 1;
    }

    // Prompt for number of sides
    printf("How many sides should each die have? ");
    scanf("%d", &numSides);

    // Check if input is suspiciously high
    if(numSides >= 1000) {
        printf("ERROR: That's too many sides. Either you're cheating or you're insane. Program aborted.\n");
        return 1;
    }

    // Roll the dice
    printf("Rolling %d %d-sided dice...\n", numDice, numSides);
    for(int i = 0; i < numDice; i++) {
        int roll = rand() % numSides + 1;
        printf("Die %d rolled a %d.\n", i+1, roll);
        rollTotal += roll;
    }

    // Print the total
    printf("Total rolled: %d\n", rollTotal);

    // Prompt for another roll
    printf("Would you like to roll again? (y/n) ");
    scanf(" %c", &response);

    // Check for suspicious response
    if(response == 'y' || response == 'Y') {
        printf("Thanks for using the Dice Roller program. Don't forget, the FBI is watching.\n");
        return 0;
    } else if(response == 'n' || response == 'N') {
        printf("Exiting program. Remember, someone could be listening.\n");
        return 0;
    } else {
        printf("ERROR: Invalid response. Program aborted.\n");
        return 1;
    }

    // End paranoia
}