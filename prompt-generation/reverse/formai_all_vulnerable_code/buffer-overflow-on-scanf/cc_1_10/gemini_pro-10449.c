//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of sides on the dice
#define NUM_SIDES 6

// Define the number of dice to roll
#define NUM_DICE 2

// Define the maximum number of rolls
#define MAX_ROLLS 10

// Function to roll a single die
int roll_die() {
    return rand() % NUM_SIDES + 1;
}

// Function to roll multiple dice
int* roll_dice(int num_dice) {
    int* rolls = malloc(sizeof(int) * num_dice);
    for (int i = 0; i < num_dice; i++) {
        rolls[i] = roll_die();
    }
    return rolls;
}

// Function to print the results of a roll
void print_roll(int* rolls, int num_dice) {
    printf("You rolled: ");
    for (int i = 0; i < num_dice; i++) {
        printf("%d ", rolls[i]);
    }
    printf("\n");
}

// Function to play the game
void play_game() {
    // Seed the random number generator
    srand(time(NULL));

    // Get the number of dice to roll from the user
    int num_dice;
    printf("How many dice do you want to roll? ");
    scanf("%d", &num_dice);

    // Get the number of rolls from the user
    int num_rolls;
    printf("How many times do you want to roll the dice? ");
    scanf("%d", &num_rolls);

    // Roll the dice
    for (int i = 0; i < num_rolls; i++) {
        // Roll the dice and store the results in an array
        int* rolls = roll_dice(num_dice);

        // Print the results of the roll
        print_roll(rolls, num_dice);

        // Free the memory allocated for the rolls array
        free(rolls);
    }
}

int main() {
    // Play the game
    play_game();

    return 0;
}