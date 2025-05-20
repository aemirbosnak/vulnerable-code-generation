//FormAI DATASET v1.0 Category: Dice Roller ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice() {
    return (rand() % 6) + 1;  // Returns a random number between 1 and 6
}

void displayRoll(int dice, int total, int turnTotal) {
    printf("Dice Roll: %d\n", dice);
    printf("Turn Total: %d\n", turnTotal);
    printf("Current Total: %d\n\n", total + turnTotal);
}

int main() {
    int total = 0;
    int turnTotal = 0;
    char choice;

    srand(time(NULL));  // Seed the random number generator with the current time

    printf("***********************************************************\n");
    printf("*                                                         *\n");
    printf("*                  Welcome to Dice Roller                 *\n");
    printf("*                                                         *\n");
    printf("***********************************************************\n\n");

    do {
        int dice = rollDice();  // Roll the dice
        turnTotal += dice;  // Add the roll to the turn total
        displayRoll(dice, total, turnTotal);  // Display the result of the roll

        if (dice == 1) {  // If the roll is a 1, end the turn and reset the turn total
            printf("You rolled a 1! Turn over.\n\n");
            turnTotal = 0;
            continue;
        }

        printf("Do you want to roll again? (Y/N)\n");
        scanf(" %c", &choice);

        while (choice != 'y' && choice != 'n' && choice != 'Y' && choice != 'N') {  // Force user to input a valid choice
            printf("Invalid choice. Please try again\n");
            printf("Do you want to roll again? (Y/N)\n");
            scanf(" %c", &choice);
        }

        if (choice == 'n' || choice == 'N') {  // End turn and add turn total to total score
            total += turnTotal;
            printf("Current Score: %d\n\n", total);
            turnTotal = 0;
        }

    } while (total < 100);  // End game when total score reaches 100 or more

    printf("Congratulations, you win!\n");
    printf("Final Score: %d\n", total);

    return 0;
}