//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_DICE 6
#define NUM_SIDES 6

// Function to roll dice and return the sum
int rollDice() {
    int dice[NUM_DICE];
    int sum = 0;
    for (int i = 0; i < NUM_DICE; i++) {
        dice[i] = rand() % NUM_SIDES + 1;
        sum += dice[i];
    }
    return sum;
}

// Function to simulate dice rolling and return statistics
void simulateDiceRolling(int numRolls) {
    int minSum = NUM_SIDES * NUM_DICE;
    int maxSum = 0;
    int sum = 0;
    int numRollsWithSum[NUM_DICE * NUM_SIDES];
    memset(numRollsWithSum, 0, sizeof(numRollsWithSum));

    for (int i = 0; i < numRolls; i++) {
        int rollSum = rollDice();
        sum += rollSum;
        if (rollSum < minSum)
            minSum = rollSum;
        if (rollSum > maxSum)
            maxSum = rollSum;
        numRollsWithSum[rollSum - 1]++;
    }

    printf("Number of rolls: %d\n", numRolls);
    printf("Minimum sum: %d\n", minSum);
    printf("Maximum sum: %d\n", maxSum);
    printf("Average sum: %.2f\n", (double)sum / numRolls);
    printf("Sum distribution:\n");
    for (int i = 0; i < NUM_DICE * NUM_SIDES; i++) {
        printf("%d: %d\n", i + 1, numRollsWithSum[i]);
    }
}

int main() {
    int numRolls;
    printf("Enter the number of rolls: ");
    scanf("%d", &numRolls);

    srand(time(NULL));
    simulateDiceRolling(numRolls);

    return 0;
}