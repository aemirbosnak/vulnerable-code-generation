//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants representing the types of dice
#define D4 4
#define D6 6
#define D8 8
#define D10 10
#define D12 12
#define D20 20

// Function to roll a die of a given type
int roll_die(int type) {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random number between 1 and the number of sides on the die
    return rand() % type + 1;
}

// Function to roll a set of dice and sum their results
int roll_dice(int type, int num_dice) {
    int total = 0;

    // Roll each die and add its result to the total
    for (int i = 0; i < num_dice; i++) {
        total += roll_die(type);
    }

    // Return the total
    return total;
}

// Function to print the results of a dice roll
void print_roll(int type, int num_dice, int total) {
    printf("Rolled %d %d-sided dice: ", num_dice, type);

    // Print each die result
    for (int i = 0; i < num_dice; i++) {
        printf("%d ", roll_die(type));
    }

    // Print the total
    printf("Total: %d\n", total);
}

// Main function
int main() {
    // Get the type of die to roll from the user
    int type;
    printf("Enter the type of die to roll (D4, D6, D8, D10, D12, D20): ");
    scanf("%d", &type);

    // Get the number of dice to roll from the user
    int num_dice;
    printf("Enter the number of dice to roll: ");
    scanf("%d", &num_dice);

    // Roll the dice and sum their results
    int total = roll_dice(type, num_dice);

    // Print the results of the roll
    print_roll(type, num_dice, total);

    return 0;
}