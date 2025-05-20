//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIDES 1000

int main() {
    int numSides;
    int numRolls;
    int rollResult;
    int total = 0;
    int maxRoll = 0;
    int minRoll = MAX_SIDES;
    int numMaxRolls = 0;
    int numMinRolls = 0;
    int freq[MAX_SIDES] = {0};

    srand(time(NULL));
    printf("Enter the number of sides on the dice: ");
    scanf("%d", &numSides);

    printf("Enter the number of rolls: ");
    scanf("%d", &numRolls);

    for (int i = 0; i < numRolls; i++) {
        rollResult = rand() % numSides + 1;
        total += rollResult;
        if (rollResult > maxRoll) {
            maxRoll = rollResult;
        }
        if (rollResult < minRoll) {
            minRoll = rollResult;
        }
        if (rollResult == maxRoll) {
            numMaxRolls++;
        }
        if (rollResult == minRoll) {
            numMinRolls++;
        }
        freq[rollResult - 1]++;
    }

    printf("Total: %d\n", total);
    printf("Average: %.2f\n", (float)total / numRolls);
    printf("Max roll: %d\n", maxRoll);
    printf("Min roll: %d\n", minRoll);
    printf("Number of max rolls: %d\n", numMaxRolls);
    printf("Number of min rolls: %d\n", numMinRolls);

    for (int i = 0; i < numSides; i++) {
        printf("%d: %d\n", i + 1, freq[i]);
    }

    return 0;
}