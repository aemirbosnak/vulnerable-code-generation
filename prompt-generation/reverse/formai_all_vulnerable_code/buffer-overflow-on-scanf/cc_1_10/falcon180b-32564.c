//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numSides;
    int numDice;
    int result;
    int total = 0;
    int i;
    int j;
    char choice;

    printf("Welcome to the Dice Roller!\n");
    printf("How many sides do you want on your dice? ");
    scanf("%d", &numSides);
    printf("How many dice do you want to roll? ");
    scanf("%d", &numDice);

    srand(time(NULL));

    for(i = 0; i < numDice; i++) {
        result = rand() % numSides + 1;
        printf("Roll #%d: %d\n", i+1, result);
        total += result;
    }

    printf("Total: %d\n", total);

    printf("Do you want to roll again? (y/n) ");
    scanf(" %c", &choice);

    while(choice == 'y' || choice == 'Y') {
        printf("How many sides do you want on your dice? ");
        scanf("%d", &numSides);
        printf("How many dice do you want to roll? ");
        scanf("%d", &numDice);

        srand(time(NULL));

        for(i = 0; i < numDice; i++) {
            result = rand() % numSides + 1;
            printf("Roll #%d: %d\n", i+1, result);
            total += result;
        }

        printf("Total: %d\n", total);

        printf("Do you want to roll again? (y/n) ");
        scanf(" %c", &choice);
    }

    printf("Thank you for using the Dice Roller!\n");

    return 0;
}