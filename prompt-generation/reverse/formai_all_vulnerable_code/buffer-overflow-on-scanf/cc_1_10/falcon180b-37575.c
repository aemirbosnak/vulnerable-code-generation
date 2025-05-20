//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIDES 6
#define MAX_ROLLS 1000

// Function to roll the dice
int rollDice() {
    return rand() % SIDES + 1;
}

// Function to simulate a game of dice
void playGame() {
    int rolls[MAX_ROLLS];
    int i, numRolls;

    // Seed the random number generator
    srand(time(NULL));

    // Ask the user how many rolls they want to make
    printf("How many rolls do you want to make? ");
    scanf("%d", &numRolls);

    // Roll the dice numRolls times and store the results in an array
    for (i = 0; i < numRolls; i++) {
        rolls[i] = rollDice();
    }

    // Print the results
    printf("You rolled the following numbers:\n");
    for (i = 0; i < numRolls; i++) {
        printf("%d ", rolls[i]);
    }
    printf("\n");
}

int main() {
    char playAgain;

    // Loop until the user decides to quit
    do {
        // Play a game of dice
        playGame();

        // Ask the user if they want to play again
        printf("Do you want to play again? (y/n) ");
        scanf(" %c", &playAgain);
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}