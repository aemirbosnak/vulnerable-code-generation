//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number between 1 and 6
int rollDice() {
    return rand() % 6 + 1;
}

int main() {
    int numDice;
    int numRolls;
    int i, j;
    int total = 0;
    int maxTotal = 0;
    int minTotal = 999;
    int count = 0;

    // Get number of dice and number of rolls from user
    printf("Enter the number of dice: ");
    scanf("%d", &numDice);
    printf("Enter the number of rolls: ");
    scanf("%d", &numRolls);

    // Roll dice and calculate total for each roll
    for (i = 0; i < numRolls; i++) {
        total = 0;
        for (j = 0; j < numDice; j++) {
            total += rollDice();
        }

        // Update max and min totals if necessary
        if (total > maxTotal) {
            maxTotal = total;
        }
        if (total < minTotal) {
            minTotal = total;
        }

        // Print results for each roll
        printf("Roll %d: ", i + 1);
        for (j = 0; j < numDice; j++) {
            printf("%d ", rollDice());
        }
        printf("Total: %d\n", total);

        // Update count of rolls with same total
        count = 0;
        for (j = 0; j < numDice; j++) {
            if (rollDice() == total) {
                count++;
            }
        }
        printf("Number of dice showing %d: %d\n", total, count);

        // Reset total for next roll
        total = 0;
    }

    // Print overall max and min totals
    printf("Max total: %d\n", maxTotal);
    printf("Min total: %d\n", minTotal);

    return 0;
}