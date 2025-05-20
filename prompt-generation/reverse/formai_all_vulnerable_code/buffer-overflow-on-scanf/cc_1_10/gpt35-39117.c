//FormAI DATASET v1.0 Category: Dice Roller ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice(int diceSides) {
    return rand() % diceSides + 1;
}

int main() {
    int diceSides, numDice, sum = 0, i;

    // Seed the random number generator with current time
    srand(time(NULL));

    printf("Dice Roller Program\n");

    while(1) {
        printf("\nEnter the number of sides on the dice[2-12]\n");
        scanf("%d", &diceSides);

        if(diceSides < 2 || diceSides > 12) {
            printf("Invalid input! Please enter an integer between 2 and 12.\n");
            continue;
        }

        printf("Enter the number of dice to roll:\n");
        scanf("%d", &numDice);

        printf("Rolling %d dice with %d sides each...\n", numDice, diceSides);

        for(i = 0; i < numDice; i++) {
            int roll = rollDice(diceSides);
            printf("Dice %d: %d\n", i+1, roll);
            sum += roll;
        }

        printf("Total: %d\n", sum);

        char answer;

        while (1) {
            printf("Do you want to roll again? [y/n] ");
            scanf(" %c", &answer);
            if(answer == 'y' || answer == 'Y') {
                sum = 0;
                break;
            }
            else if(answer == 'n' || answer == 'N') {
                return 0;
            }
            else {
                printf("Invalid input! Please enter either y or n.\n");
                continue;
            }
        }
    }

    return 0;
}