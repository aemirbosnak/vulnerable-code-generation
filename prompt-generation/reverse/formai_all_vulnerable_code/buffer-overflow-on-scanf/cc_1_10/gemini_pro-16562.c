//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll a die with a given number of sides
int roll_die(int sides) {
    // Check if the number of sides is valid
    if (sides <= 0) {
        printf("Error: Invalid number of sides for dice.\n");
        exit(1);
    }

    // Generate a random number between 1 and the number of sides
    int result = rand() % sides + 1;

    // Return the result
    return result;
}

// Function to roll multiple dice and print the results
void roll_multiple_dice(int num_dice, int sides) {
    // Check if the number of dice or sides is valid
    if (num_dice <= 0 || sides <= 0) {
        printf("Error: Invalid number of dice or sides for dice.\n");
        exit(1);
    }

    // Roll the dice and print the results
    for (int i = 0; i < num_dice; i++) {
        int result = roll_die(sides);
        printf("Dice %d: %d\n", i + 1, result);
    }
}

// Function to play a dice-rolling game
void play_dice_game() {
    // Get the number of dice and sides from the user
    int num_dice, sides;
    printf("Enter the number of dice: ");
    scanf("%d", &num_dice);
    printf("Enter the number of sides per die: ");
    scanf("%d", &sides);

    // Roll the dice and print the results
    roll_multiple_dice(num_dice, sides);

    // Calculate the total score
    int total_score = 0;
    for (int i = 0; i < num_dice; i++) {
        int result = roll_die(sides);
        total_score += result;
    }

    // Print the total score
    printf("Total score: %d\n", total_score);
}

// Main function
int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Play the dice-rolling game
    play_dice_game();

    return 0;
}