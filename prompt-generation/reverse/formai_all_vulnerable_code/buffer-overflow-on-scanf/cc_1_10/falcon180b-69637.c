//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIDES 6

int main() {
    srand(time(NULL));
    int numDice = 1;
    int numRolls = 1;
    int totalRolls = 0;
    int maxValue = 0;
    int minValue = SIDES;
    int sum = 0;
    int count[SIDES] = {0};

    printf("Welcome to the Dice Roller!\n");
    printf("How many dice do you want to roll? ");
    scanf("%d", &numDice);

    printf("How many times do you want to roll the dice? ");
    scanf("%d", &numRolls);

    for (int i = 0; i < numRolls; i++) {
        int diceValue = rand() % SIDES + 1;
        printf("Roll %d: %d\n", i + 1, diceValue);
        totalRolls++;
        sum += diceValue;

        if (diceValue > maxValue) {
            maxValue = diceValue;
        }

        if (diceValue < minValue) {
            minValue = diceValue;
        }

        count[diceValue - 1]++;
    }

    printf("\nTotal rolls: %d\n", totalRolls);
    printf("Average roll: %.2f\n", (double)sum / totalRolls);
    printf("Highest roll: %d\n", maxValue);
    printf("Lowest roll: %d\n", minValue);

    for (int i = 0; i < SIDES; i++) {
        printf("Number of times %d was rolled: %d\n", i + 1, count[i]);
    }

    return 0;
}