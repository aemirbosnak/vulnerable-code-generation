//FormAI DATASET v1.0 Category: Dice Roller ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll the dice
int rollDice() {
    return (rand() % 6) + 1;
}

// Function to play the game
void playGame() {
    int sum = 0; // To keep track of the sum of the dice
    int rolls = 0; // To keep track of the number of rolls
    char choice; // To ask the user if they want to roll again

    do {
        int roll = rollDice();
        printf("\nYou rolled a %d.", roll);

        if (roll == 1) { // If the player rolls a 1, they lose and the game ends
            printf("\nSorry, you lose!");
            return;
        } else { // If the player does not roll a 1, their score increases and they can choose to roll again
            sum += roll;
            printf("\nYour current score is %d.\n", sum);
            printf("\nDo you want to roll again? (y/n): ");
            scanf(" %c", &choice);
            rolls++;
        }

    } while (sum < 100 && choice == 'y'); // The game ends if the player reaches 100 or chooses not to roll again

    printf("\nYou scored %d in %d rolls. Congratulations!\n", sum, rolls);
}

// Main method
int main() {
    srand(time(0)); // To seed the random number generator

    char playAgain = 'Y'; // To ask the user if they want to play again

    printf("\nWelcome to the Dice Roll Game!\n");

    do {
        playGame();
        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &playAgain);

    } while (playAgain == 'y' || playAgain == 'Y'); // The game restarts if the player chooses to play again

    printf("\nThank you for playing the Dice Roll Game!\n");

    return 0;
}