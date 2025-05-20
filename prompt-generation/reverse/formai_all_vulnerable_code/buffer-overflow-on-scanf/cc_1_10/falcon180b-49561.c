//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 100
#define MIN_VALUE 1
#define MAX_VALUE 6

typedef struct {
    int value;
    int count;
} Die;

int main() {
    int numDice, i;
    Die dice[MAX_DICE];
    srand(time(NULL));

    // Prompt user for number of dice
    printf("Enter the number of dice to roll (1 to %d): ", MAX_DICE);
    scanf("%d", &numDice);

    // Initialize dice values and counts
    for (i = 0; i < numDice; i++) {
        dice[i].value = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
        dice[i].count = 0;
    }

    // Roll dice and display results
    printf("Rolling %d dice...\n", numDice);
    for (i = 0; i < numDice; i++) {
        printf("Dice %d: ", i+1);
        for (int j = 0; j < 5; j++) {
            int roll = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
            if (roll == dice[i].value) {
                dice[i].count++;
            }
            printf("%d ", roll);
        }
        printf("\n");
    }

    // Display results
    printf("\nRoll results:\n");
    for (i = 0; i < numDice; i++) {
        printf("Dice %d: %d (rolled %d times)\n", i+1, dice[i].value, dice[i].count);
    }

    return 0;
}