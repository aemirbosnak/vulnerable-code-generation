//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll a dice
int roll_dice(int sides) {
    // If the number of sides is not valid, return -1
    if (sides < 1) {
        return -1;
    }

    // Generate a random number between 1 and the number of sides
    int roll = rand() % sides + 1;

    // Return the roll
    return roll;
}

// Function to play a dice game
void play_dice_game(int sides, int num_rolls) {
    // If either the number of sides or the number of rolls is not valid, return
    if (sides < 1 || num_rolls < 1) {
        return;
    }

    // Initialize the total roll to 0
    int total_roll = 0;

    // Roll the dice the specified number of times
    for (int i = 0; i < num_rolls; i++) {
        // Roll the dice and add the roll to the total
        total_roll += roll_dice(sides);
    }

    // Print the total roll
    printf("Total roll: %d\n", total_roll);
}

// Main function
int main() {
    // Set the random seed
    srand(time(NULL));

    // Get the number of sides of the dice from the user
    int sides;
    printf("Enter the number of sides of the dice: ");
    scanf("%d", &sides);

    // Get the number of rolls from the user
    int num_rolls;
    printf("Enter the number of rolls: ");
    scanf("%d", &num_rolls);

    // Play the dice game
    play_dice_game(sides, num_rolls);

    return 0;
}