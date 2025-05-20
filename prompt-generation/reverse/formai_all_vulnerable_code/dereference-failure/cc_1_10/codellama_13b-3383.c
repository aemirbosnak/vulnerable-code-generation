//Code Llama-13B DATASET v1.0 Category: Dice Roller ; Style: protected
/*
 * dice_roller.c
 *
 * A simple dice roller program in a protected style.
 *
 * Usage:
 * 1. Compile the program using a C compiler.
 * 2. Run the program with the desired number of dice and number of sides as arguments.
 * 3. The program will output the sum of the dice rolls.
 *
 * Example:
 * $ ./dice_roller 2 6
 * 10
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random number between 1 and n
int generate_random_number(int n) {
    return (rand() % n) + 1;
}

int main(int argc, char *argv[]) {
    // Check if the number of arguments is correct
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <number of dice> <number of sides>\n", argv[0]);
        return 1;
    }

    // Get the number of dice and number of sides from the command line arguments
    int num_dice = atoi(argv[1]);
    int num_sides = atoi(argv[2]);

    // Check if the number of dice and number of sides is valid
    if (num_dice < 1 || num_sides < 2) {
        fprintf(stderr, "Invalid number of dice or sides\n");
        return 1;
    }

    // Initialize the random number generator
    srand(time(NULL));

    // Roll the dice
    int sum = 0;
    for (int i = 0; i < num_dice; i++) {
        sum += generate_random_number(num_sides);
    }

    // Print the sum of the dice rolls
    printf("%d\n", sum);

    return 0;
}