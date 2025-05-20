//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max (inclusive)
int randInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to roll a dice with n sides
int rollDice(int n) {
    return randInt(1, n);
}

// Function to simulate a game of craps
void craps() {
    int point, roll, comeOut;
    char playAgain = 'y';

    // Roll the come out roll
    comeOut = rollDice(6) + rollDice(6);
    printf("Come out roll: %d\n", comeOut);

    // Determine the point
    point = comeOut;
    printf("Point is: %d\n", point);

    while (playAgain == 'y') {
        // Roll the dice
        roll = rollDice(6);
        printf("Roll: %d\n", roll);

        // Check if the roll is a win or a loss
        if (roll == point) {
            printf("You win!\n");
        } else if (roll == 7) {
            printf("You lose.\n");
        } else {
            printf("Keep rolling...\n");
        }

        // Ask the player if they want to play again
        printf("Do you want to play again? (y/n): ");
        scanf("%c", &playAgain);
    }
}

int main() {
    srand(time(NULL));
    craps();
    return 0;
}