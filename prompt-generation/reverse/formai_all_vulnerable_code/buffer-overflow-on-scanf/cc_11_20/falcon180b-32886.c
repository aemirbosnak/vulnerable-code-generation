//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIDES 6
#define NUM_DICE 3

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time
    int dice[NUM_DICE][SIDES]; // Create an array to store the dice rolls
    int i, j, k;
    char play_again;

    // Initialize the dice array with a value of 0
    for (i = 0; i < NUM_DICE; i++) {
        for (j = 0; j < SIDES; j++) {
            dice[i][j] = 0;
        }
    }

    // Roll the dice and store the results in the array
    for (i = 0; i < NUM_DICE; i++) {
        for (j = 0; j < SIDES; j++) {
            dice[i][j] = rand() % SIDES + 1;
        }
    }

    // Print the results
    printf("Rolling %d dice with %d sides:\n", NUM_DICE, SIDES);
    for (i = 0; i < NUM_DICE; i++) {
        printf("Dice %d: ", i + 1);
        for (j = 0; j < SIDES; j++) {
            printf("%d ", dice[i][j]);
        }
        printf("\n");
    }

    // Calculate the total score
    int score = 0;
    for (i = 0; i < NUM_DICE; i++) {
        for (j = 0; j < SIDES; j++) {
            if (dice[i][j] == 1) {
                score++;
            }
        }
    }

    // Print the total score
    printf("Total score: %d\n", score);

    // Ask the user if they want to play again
    printf("Do you want to play again? (y/n) ");
    scanf("%c", &play_again);

    if (play_again == 'y') {
        main();
    } else {
        return 0;
    }
}