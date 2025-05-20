//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice() {
    int dice = rand() % 6 + 1;
    return dice;
}

int main() {
    int numRolls;
    int total = 0;
    int highestRoll = 0;
    int lowestRoll = 0;
    int numHighestRolls = 0;
    int numLowestRolls = 0;
    int i;
    int playerChoice;
    char playAgain = 'y';

    srand(time(NULL));

    while(playAgain == 'y' || playAgain == 'Y') {
        printf("Enter the number of rolls: ");
        scanf("%d", &numRolls);
        total = 0;
        highestRoll = 0;
        lowestRoll = 0;
        numHighestRolls = 0;
        numLowestRolls = 0;

        for(i = 0; i < numRolls; i++) {
            int roll = rollDice();
            total += roll;

            if(roll > highestRoll) {
                highestRoll = roll;
                numHighestRolls = 1;
            } else if(roll == highestRoll) {
                numHighestRolls++;
            }

            if(roll < lowestRoll || i == 0) {
                lowestRoll = roll;
            }
        }

        printf("Total: %d\n", total);
        printf("Highest roll: %d (occurred %d times)\n", highestRoll, numHighestRolls);
        printf("Lowest roll: %d\n", lowestRoll);

        printf("Play again? (y/n): ");
        scanf(" %c", &playAgain);
    }

    return 0;
}