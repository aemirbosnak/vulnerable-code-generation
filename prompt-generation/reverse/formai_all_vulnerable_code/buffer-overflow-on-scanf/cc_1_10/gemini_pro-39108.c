//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of sides for the dice
#define NUM_SIDES 6

// Function to roll a single die
int roll_die() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random number between 1 and NUM_SIDES
    int roll = (rand() % NUM_SIDES) + 1;

    // Return the result
    return roll;
}

// Function to roll multiple dice
int* roll_dice(int num_dice) {
    // Allocate memory for the array of dice rolls
    int* rolls = malloc(sizeof(int) * num_dice);

    // Roll each die and store the result in the array
    for (int i = 0; i < num_dice; i++) {
        rolls[i] = roll_die();
    }

    // Return the array of dice rolls
    return rolls;
}

// Function to print the results of rolling dice
void print_rolls(int* rolls, int num_dice) {
    // Print the header
    printf("Dice Rolls:\n");

    // Print each die roll
    for (int i = 0; i < num_dice; i++) {
        printf("%d ", rolls[i]);
    }

    // Print a newline
    printf("\n");
}

// Main function
int main() {
    // Get the number of dice to roll from the user
    int num_dice;
    printf("How many dice would you like to roll? ");
    scanf("%d", &num_dice);

    // Roll the dice
    int* rolls = roll_dice(num_dice);

    // Print the results
    print_rolls(rolls, num_dice);

    // Free the memory allocated for the array of dice rolls
    free(rolls);

    return 0;
}