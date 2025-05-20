//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max (inclusive)
int randInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to roll a virtual dice and return the result
int rollDice() {
    int result;
    srand(time(NULL));
    result = randInt(1, 6);
    printf("You rolled a %d!\n", result);
    return result;
}

// Function to simulate a game of craps
void playCraps() {
    int point, result, rollCount = 0;
    char playAgain;

    do {
        printf("Welcome to the game of craps!\n");
        printf("Please place your bets...\n");
        printf("Press enter to roll the dice:\n");
        scanf("%c", &playAgain);
        result = rollDice();

        // Determine the point based on the result of the first roll
        if (result == 7 || result == 11) {
            printf("You win!\n");
        } else if (result == 2 || result == 3 || result == 12) {
            printf("You lose.\n");
        } else {
            point = result;
            printf("The point is %d.\n", point);
        }

        while (rollCount < 2 && result!= point && result!= 7) {
            printf("Press enter to roll the dice:\n");
            scanf("%c", &playAgain);
            result = rollDice();
            rollCount++;
        }

        if (result == point) {
            printf("You win!\n");
        } else if (result == 7) {
            printf("You lose.\n");
        }

    } while (playAgain == 'y' || playAgain == 'Y');
}

// Main function
int main() {
    playCraps();
    return 0;
}