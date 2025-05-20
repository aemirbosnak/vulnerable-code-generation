//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numDice, numSides, numRolls, i, j, temp;
    int roll[100], count[7];
    char playAgain;

    srand(time(NULL));

    do {
        printf("How many dice do you want to roll? ");
        scanf("%d", &numDice);
        if (numDice <= 0) {
            printf("Invalid input. Please enter a positive integer.\n");
        }
    } while (numDice <= 0);

    do {
        printf("How many sides do you want on the dice? ");
        scanf("%d", &numSides);
        if (numSides <= 0) {
            printf("Invalid input. Please enter a positive integer.\n");
        }
    } while (numSides <= 0);

    do {
        printf("How many times do you want to roll the dice? ");
        scanf("%d", &numRolls);
        if (numRolls <= 0) {
            printf("Invalid input. Please enter a positive integer.\n");
        }
    } while (numRolls <= 0);

    for (i = 0; i < numDice; i++) {
        roll[i] = rand() % numSides + 1;
        count[roll[i]]++;
    }

    printf("Rolling the dice...\n");

    for (i = 0; i < numRolls; i++) {
        for (j = 0; j < numDice; j++) {
            temp = rand() % numSides + 1;
            roll[j] = temp;
            printf("%d ", temp);
        }
        printf("\n");
    }

    printf("Results:\n");
    for (i = 1; i <= numSides; i++) {
        printf("%d: %d\n", i, count[i]);
    }

    printf("Do you want to play again? (y/n): ");
    scanf(" %c", &playAgain);

    if (playAgain == 'y' || playAgain == 'Y') {
        main();
    } else {
        return 0;
    }
}