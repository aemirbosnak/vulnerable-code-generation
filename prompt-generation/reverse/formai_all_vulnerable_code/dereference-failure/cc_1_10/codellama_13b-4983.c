//Code Llama-13B DATASET v1.0 Category: Dice Roller ; Style: modular
/*
 * dice_roller.c
 *
 * A simple dice rolling program in a modular style.
 *
 * Usage:
 *      dice_roller [number_of_dice] [number_of_sides]
 *
 * Example:
 *      dice_roller 3 6
 *
 * Author:
 *      [Your Name]
 *
 * Date:
 *      [Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Rolls a single die with the given number of sides.
 *
 * Parameters:
 *      sides: The number of sides on the die.
 *
 * Returns:
 *      The result of the roll.
 */
int roll_die(int sides) {
    return (rand() % sides) + 1;
}

/*
 * Rolls a number of dice with the given number of sides.
 *
 * Parameters:
 *      dice: The number of dice to roll.
 *      sides: The number of sides on each die.
 *
 * Returns:
 *      The sum of the rolls.
 */
int roll_dice(int dice, int sides) {
    int total = 0;
    for (int i = 0; i < dice; i++) {
        total += roll_die(sides);
    }
    return total;
}

/*
 * The main function.
 */
int main(int argc, char *argv[]) {
    // Check the number of arguments.
    if (argc != 3) {
        fprintf(stderr, "Usage: %s [number_of_dice] [number_of_sides]\n", argv[0]);
        return 1;
    }

    // Get the number of dice and sides from the command line arguments.
    int dice = atoi(argv[1]);
    int sides = atoi(argv[2]);

    // Roll the dice and print the results.
    srand(time(NULL));
    int total = roll_dice(dice, sides);
    printf("You rolled %d %d-sided dice and got a total of %d.\n", dice, sides, total);

    return 0;
}