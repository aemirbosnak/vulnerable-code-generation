//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll a die with a specified number of sides
int roll_die(int sides) {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Generate a random number between 1 and the number of sides
    int roll = rand() % sides + 1;

    return roll;
}

// Function to play a game of dice rolling
void play_game(int num_dice, int sides) {
    // Roll the dice and store the results in an array
    int rolls[num_dice];
    for (int i = 0; i < num_dice; i++) {
        rolls[i] = roll_die(sides);
    }

    // Calculate the sum of the rolls
    int sum = 0;
    for (int i = 0; i < num_dice; i++) {
        sum += rolls[i];
    }

    // Print the results of the roll
    printf("You rolled: ");
    for (int i = 0; i < num_dice; i++) {
        printf("%d ", rolls[i]);
    }
    printf("\n");
    printf("The sum of the rolls is: %d\n", sum);
}

int main() {
    // Get the number of dice and sides from the user
    int num_dice, sides;
    printf("How many dice do you want to roll? ");
    scanf("%d", &num_dice);
    printf("How many sides do you want each die to have? ");
    scanf("%d", &sides);

    // Play the game
    play_game(num_dice, sides);

    return 0;
}