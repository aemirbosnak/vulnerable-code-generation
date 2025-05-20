//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll a dice
int rollDice() {
    int dice = rand() % 6 + 1;
    return dice;
}

// Function to display the result of the dice roll
void displayResult(int dice) {
    if (dice == 1) {
        printf("You rolled a 1!\n");
    }
    else if (dice == 2) {
        printf("You rolled a 2!\n");
    }
    else if (dice == 3) {
        printf("You rolled a 3!\n");
    }
    else if (dice == 4) {
        printf("You rolled a 4!\n");
    }
    else if (dice == 5) {
        printf("You rolled a 5!\n");
    }
    else {
        printf("You rolled a 6!\n");
    }
}

int main() {
    int numRolls, i;
    char choice;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Get the number of rolls from the user
    printf("How many times do you want to roll the dice? ");
    scanf("%d", &numRolls);

    // Roll the dice numRolls times and display the results
    for (i = 1; i <= numRolls; i++) {
        int dice = rollDice();
        displayResult(dice);

        // Ask the user if they want to roll again
        printf("Do you want to roll again? (y/n) ");
        scanf(" %c", &choice);

        // If the user doesn't want to roll again, exit the loop
        if (choice == 'n' || choice == 'N') {
            break;
        }
    }

    return 0;
}