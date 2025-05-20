//FormAI DATASET v1.0 Category: Dice Roller ; Style: Donald Knuth
/*
 * This program simulates the rolling of a set number of dice, with a specified number of sides each.
 * It then computes the sum of the rolled values and prints it to the console.
 * This program can also be used as a gambling simulator.
 * 
 * Written in a Donald Knuth style by [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 20     // maximum number of dice to roll
#define MAX_SIDES 100   // maximum number of sides each die can have

int roll_dice(int num_dice, int num_sides);

int main(void) {
    int num_dice, num_sides, total;

    srand(time(0));     // seed the random number generator

    printf("Enter the number of dice to roll (1-%d): ", MAX_DICE);
    scanf("%d", &num_dice);
    if (num_dice < 1 || num_dice > MAX_DICE) {
        fprintf(stderr, "*** Invalid number of dice specified! ***\n");
        return 1;
    }

    printf("Enter the number of sides for each die (2-%d): ", MAX_SIDES);
    scanf("%d", &num_sides);
    if (num_sides < 2 || num_sides > MAX_SIDES) {
        fprintf(stderr, "*** Invalid number of sides specified! ***\n");
        return 1;
    }

    total = roll_dice(num_dice, num_sides);
    printf("\nThe total value of the rolled dice is: %d", total);

    return 0;
}

/* This function returns the sum of a specified number of dice rolls, with a specified number of sides each. */
int roll_dice(int num_dice, int num_sides) {
    int i, total = 0;

    printf("\nRolling %d dice with %d sides each...", num_dice, num_sides);
    for (i = 1; i <= num_dice; i++) {
        int roll = rand() % num_sides + 1;
        printf("\nDie %d roll: %d", i, roll);
        total += roll;
    }

    return total;
}