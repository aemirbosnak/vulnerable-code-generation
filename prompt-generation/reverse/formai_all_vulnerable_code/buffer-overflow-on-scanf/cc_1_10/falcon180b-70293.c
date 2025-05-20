//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIDES 6
#define NUM_DICE 2

void rollDice(int numDice, int sides) {
    int i, j, diceValue[NUM_DICE], total = 0;
    srand(time(NULL));

    for (i = 0; i < numDice; i++) {
        diceValue[i] = rand() % sides + 1;
        printf("Dice %d rolled %d\n", i+1, diceValue[i]);
        total += diceValue[i];
    }

    printf("Total: %d\n", total);
}

int main() {
    int choice, numDice, sides;

    printf("Welcome to the Dice Roller!\n");

    while (1) {
        printf("\n");
        printf("1. Roll dice with %d sides\n", SIDES);
        printf("2. Customize dice\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                rollDice(NUM_DICE, SIDES);
                break;
            case 2:
                printf("Enter number of dice: ");
                scanf("%d", &numDice);
                printf("Enter number of sides per dice: ");
                scanf("%d", &sides);

                if (numDice > 0 && sides > 0) {
                    rollDice(numDice, sides);
                } else {
                    printf("Invalid input.\n");
                }
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}