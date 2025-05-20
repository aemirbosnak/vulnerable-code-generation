//FormAI DATASET v1.0 Category: Table Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll 2 dice and return their sum
int rollDice() {
    int dice1 = rand() % 6 + 1;
    int dice2 = rand() % 6 + 1;
    return dice1 + dice2;
}

int main() {
    srand(time(NULL)); // Set the seed for the random number generator

    // Display welcome message
    printf("Welcome to the Confetti Dice Game!\n");
    printf("The objective of the game is to roll a 7 or 11 on your first turn to win.\n");
    printf("If you don't win on your first turn, you can keep rolling until you get a 7 or the same number as your first roll.\n");
    printf("But if you roll a 2, 3, or 12 on your first turn, you lose.\n\n");

    // Initialize variables for game
    int point = 0;
    int rollNum = 1;
    char rollAgain = ' ';

    // Loop for playing multiple games
    while (1) {
        printf("===== Game %d =====\n", rollNum);

        // Roll the dice for the first turn
        int firstRoll = rollDice();
        printf("You rolled a %d.\n", firstRoll);

        // Check if player wins, loses, or needs to roll again
        if (firstRoll == 7 || firstRoll == 11) {
            printf("Congratulations! You win!\n\n");
        } else if (firstRoll == 2 || firstRoll == 3 || firstRoll == 12) {
            printf("Sorry, you lose.\n\n");
        } else {
            point = firstRoll;
            printf("You need to roll a %d to win.\n", point);
            printf("Press 'r' to roll again: ");
            scanf(" %c", &rollAgain);

            // Loop for rolling again
            while (rollAgain == 'r') {
                int roll = rollDice();
                printf("You rolled a %d.\n", roll);
                if (roll == point) {
                    printf("Congratulations! You win!\n\n");
                    break;
                } else if (roll == 7) {
                    printf("Sorry, you lose.\n\n");
                    break;
                } else {
                    printf("You need to roll a %d to win.\n", point);
                    printf("Press 'r' to roll again or any other key to quit: ");
                    scanf(" %c", &rollAgain);
                }
            }
        }

        // Ask if player wants to play again
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &rollAgain);
        if (rollAgain == 'n') {
            break;
        } else {
            rollNum++;
            point = 0;
            printf("\n");
        }
    }

    return 0;
}