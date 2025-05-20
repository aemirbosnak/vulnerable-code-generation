//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_DICE 1000
#define MAX_ROUNDS 100000

int main() {
    int numDice, numSides, numRounds, i, j, roll, total = 0;
    int dice[MAX_DICE];
    char choice;

    printf("Welcome to the Cheerful Dice Roller!\n");
    printf("How many dice do you want to roll? (1-1000): ");
    scanf("%d", &numDice);

    printf("How many sides do you want on each die? (1-100): ");
    scanf("%d", &numSides);

    printf("How many rounds do you want to play? (1-100000): ");
    scanf("%d", &numRounds);

    srand(time(NULL));

    for (i = 0; i < numDice; i++) {
        dice[i] = rand() % numSides + 1;
    }

    for (j = 0; j < numRounds; j++) {
        total = 0;
        printf("\nRound %d:\n", j + 1);

        for (i = 0; i < numDice; i++) {
            roll = rand() % numSides + 1;
            printf("Die %d rolled a %d. ", i + 1, roll);
            total += roll;
        }

        printf("\nTotal: %d\n", total);
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &choice);

        if (tolower(choice)!= 'y') {
            break;
        }
    }

    printf("\nThanks for playing the Cheerful Dice Roller!\n");

    return 0;
}