//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numDice, numSides, i, j, roll, total = 0;
    char playAgain;

    srand(time(NULL));

    do {
        printf("Enter the number of dice: ");
        scanf("%d", &numDice);

        if (numDice <= 0) {
            printf("Invalid input. Please enter a positive integer.\n");
        }
    } while (numDice <= 0);

    do {
        printf("Enter the number of sides on each die: ");
        scanf("%d", &numSides);

        if (numSides <= 0) {
            printf("Invalid input. Please enter a positive integer.\n");
        }
    } while (numSides <= 0);

    printf("Rolling %d %d-sided dice...\n", numDice, numSides);

    for (i = 0; i < numDice; i++) {
        roll = rand() % numSides + 1;
        printf("Dice %d rolled a %d.\n", i+1, roll);
        total += roll;
    }

    printf("Total: %d\n", total);

    printf("Play again? (y/n): ");
    scanf(" %c", &playAgain);

    while (playAgain!= 'y' && playAgain!= 'n') {
        printf("Invalid input. Please enter 'y' or 'n': ");
        scanf(" %c", &playAgain);
    }

    if (playAgain == 'y') {
        main();
    } else {
        printf("Exiting program...\n");
    }

    return 0;
}