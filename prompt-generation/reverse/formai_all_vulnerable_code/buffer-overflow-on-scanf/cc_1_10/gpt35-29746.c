//FormAI DATASET v1.0 Category: Dice Roller ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));  // seed for random number generator

    int diceRolls[6] = {0, 0, 0, 0, 0, 0};  // array to keep track of number of times each number is rolled

    int numRolls;
    int rollResult;

    printf("Welcome to the Cyberpunk Dice Roller.\n");
    printf("How many times do you want to roll the dice?\n");
    scanf("%d", &numRolls);

    for (int i = 0; i < numRolls; i++) {
        rollResult = rand() % 6 + 1;  // generate a random number between 1 and 6

        switch(rollResult) {
            case 1:
                diceRolls[0]++;
                printf("Die Roll %d: 1\n", i+1);
                break;
            case 2:
                diceRolls[1]++;
                printf("Die Roll %d: 2\n", i+1);
                break;
            case 3:
                diceRolls[2]++;
                printf("Die Roll %d: 3\n", i+1);
                break;
            case 4:
                diceRolls[3]++;
                printf("Die Roll %d: 4\n", i+1);
                break;
            case 5:
                diceRolls[4]++;
                printf("Die Roll %d: 5\n", i+1);
                break;
            case 6:
                diceRolls[5]++;
                printf("Die Roll %d: 6\n", i+1);
                break;
        }
    }

    printf("\nDice Roll Statistics:\n");
    for (int j = 0; j < 6; j++) {
        printf("%d's: %d\n", j+1, diceRolls[j]);
    }

    return 0;
}