//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_dice = 0;
    int num_sides = 0;
    int max_roll = 0;
    int min_roll = 0;
    int total_rolls = 0;
    int total_sum = 0;
    int roll;
    int i;
    int j;
    int k;
    char choice;
    srand(time(NULL));

    printf("Welcome to the Dice Roller!\n");

    // Get number of dice
    printf("How many dice would you like to roll? ");
    scanf("%d", &num_dice);

    // Get number of sides per dice
    printf("How many sides would you like on each dice? ");
    scanf("%d", &num_sides);

    // Get maximum roll limit
    printf("What is the maximum roll limit? ");
    scanf("%d", &max_roll);

    // Get minimum roll limit
    printf("What is the minimum roll limit? ");
    scanf("%d", &min_roll);

    // Get number of rolls
    printf("How many times would you like to roll the dice? ");
    scanf("%d", &total_rolls);

    printf("\n");

    // Roll dice
    for (i = 0; i < total_rolls; i++) {
        for (j = 0; j < num_dice; j++) {
            roll = rand() % num_sides + 1;
            if (roll >= min_roll && roll <= max_roll) {
                total_sum += roll;
            }
        }
    }

    // Print results
    printf("You rolled the dice %d times.\n", total_rolls);
    printf("The minimum roll was %d.\n", min_roll);
    printf("The maximum roll was %d.\n", max_roll);
    printf("The total sum of all rolls was %d.\n", total_sum);

    return 0;
}