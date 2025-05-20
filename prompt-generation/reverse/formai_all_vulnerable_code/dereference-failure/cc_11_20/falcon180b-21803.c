//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 1000
#define MIN_DICE 1
#define MAX_SIDES 1000
#define MIN_SIDES 1

int main() {
    int num_dice = 0, num_sides = 0, total_sides = 0, max_roll = 0, min_roll = 1000;
    int *rolls = NULL;
    int i, j, k;

    // Initialize random seed
    srand(time(NULL));

    // Get number of dice from user
    printf("Enter the number of dice to roll (1 to %d): ", MAX_DICE);
    scanf("%d", &num_dice);

    // Validate input
    while (num_dice < MIN_DICE || num_dice > MAX_DICE) {
        printf("Invalid input. Please enter a number between %d and %d: ", MIN_DICE, MAX_DICE);
        scanf("%d", &num_dice);
    }

    // Get number of sides from user
    printf("Enter the number of sides on each die (1 to %d): ", MAX_SIDES);
    scanf("%d", &num_sides);

    // Validate input
    while (num_sides < MIN_SIDES || num_sides > MAX_SIDES) {
        printf("Invalid input. Please enter a number between %d and %d: ", MIN_SIDES, MAX_SIDES);
        scanf("%d", &num_sides);
    }

    // Allocate memory for rolls array
    rolls = (int *)malloc(num_dice * sizeof(int));

    // Initialize rolls array to 0
    for (i = 0; i < num_dice; i++) {
        rolls[i] = 0;
    }

    // Roll the dice
    for (i = 0; i < num_dice; i++) {
        for (j = 0; j < num_sides; j++) {
            // Roll the die
            int roll = rand() % num_sides + 1;

            // Update total number of sides rolled
            total_sides += num_sides;

            // Update maximum and minimum rolls
            if (roll > max_roll) {
                max_roll = roll;
            }
            if (roll < min_roll) {
                min_roll = roll;
            }

            // Add roll to array
            rolls[i] += roll;
        }
    }

    // Print results
    printf("You rolled %d dice with %d sides each.\n", num_dice, num_sides);
    printf("The total number of sides rolled was %d.\n", total_sides);
    printf("The maximum roll was %d.\n", max_roll);
    printf("The minimum roll was %d.\n", min_roll);

    // Print rolls array
    printf("The rolls were: ");
    for (i = 0; i < num_dice; i++) {
        printf("%d ", rolls[i]);
    }
    printf("\n");

    // Free memory for rolls array
    free(rolls);

    return 0;
}