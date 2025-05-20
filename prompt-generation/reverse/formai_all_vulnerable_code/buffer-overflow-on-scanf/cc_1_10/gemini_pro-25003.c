//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll a single die
int roll_die(void) {
    return (rand() % 6) + 1;
}

// Function to roll a pair of dice
int roll_pair_of_dice(void) {
    int die1, die2;

    die1 = roll_die();
    die2 = roll_die();

    return die1 + die2;
}

// Function to roll a set of dice
int roll_set_of_dice(int num_dice) {
    int i, total;

    total = 0;
    for (i = 0; i < num_dice; i++) {
        total += roll_die();
    }

    return total;
}

// Function to print a set of dice rolls
void print_dice_rolls(int num_dice, int rolls[]) {
    int i;

    printf("Dice Rolls: ");
    for (i = 0; i < num_dice; i++) {
        printf("%d ", rolls[i]);
    }
    printf("\n");
}

// Main function
int main(void) {
    int num_dice, num_rolls, i, j;
    int rolls[100];

    // Seed the random number generator
    srand(time(NULL));

    // Get the number of dice to roll
    printf("Enter the number of dice to roll: ");
    scanf("%d", &num_dice);

    // Get the number of times to roll the dice
    printf("Enter the number of times to roll the dice: ");
    scanf("%d", &num_rolls);

    // Roll the dice
    for (i = 0; i < num_rolls; i++) {
        rolls[i] = roll_set_of_dice(num_dice);
    }

    // Print the dice rolls
    print_dice_rolls(num_dice, rolls);

    return 0;
}