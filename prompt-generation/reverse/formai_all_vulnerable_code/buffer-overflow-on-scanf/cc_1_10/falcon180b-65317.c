//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SIDES 6
#define NUM_DICE 2

void rollDice(int numDice, int numSides) {
    int i, j;
    srand(time(0));
    for (i = 0; i < numDice; i++) {
        for (j = 0; j < numSides; j++) {
            printf("%d ", rand() % numSides + 1);
        }
        printf("\n");
    }
}

int main() {
    int choice;

    do {
        printf("Welcome to the Dice Roller!\n");
        printf("Please choose an option:\n");
        printf("1. Roll 2 six-sided dice\n");
        printf("2. Roll 3 eight-sided dice\n");
        printf("3. Roll 4 ten-sided dice\n");
        printf("4. Roll 5 twelve-sided dice\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                rollDice(NUM_DICE, NUM_SIDES);
                break;
            case 2:
                rollDice(NUM_DICE, 8);
                break;
            case 3:
                rollDice(NUM_DICE, 10);
                break;
            case 4:
                rollDice(NUM_DICE, 12);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 5);

    return 0;
}