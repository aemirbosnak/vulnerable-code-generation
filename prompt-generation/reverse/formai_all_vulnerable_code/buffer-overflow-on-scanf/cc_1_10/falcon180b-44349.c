//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numDices, numRolls, result, i, j;
    char again;

    printf("Welcome to the Automated Dice Roller!\n");
    printf("How many dice do you want to roll? ");
    scanf("%d", &numDices);

    while(1) {
        printf("How many times do you want to roll the dice? ");
        scanf("%d", &numRolls);

        if(numRolls <= 0) {
            printf("Invalid input. Please enter a positive integer.\n");
            continue;
        }

        break;
    }

    srand(time(NULL));

    for(i = 0; i < numRolls; i++) {
        printf("\nRoll #%d:\n", i+1);

        for(j = 0; j < numDices; j++) {
            result = rand() % 6 + 1;

            printf("Dice #%d rolled a %d\n", j+1, result);
        }

        printf("\n");
    }

    printf("Do you want to roll again? (y/n) ");
    scanf(" %c", &again);

    if(again == 'y' || again == 'Y') {
        main();
    } else {
        printf("Thank you for using the Automated Dice Roller!\n");
        return 0;
    }

    return 0;
}