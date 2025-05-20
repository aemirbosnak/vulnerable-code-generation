//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A function to generate a random number between min and max
int random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// A function to roll a die with a given number of sides
int roll_die(int sides) {
    return random_number(1, sides);
}

// A function to roll a set of dice with a given number of sides and print the results
void roll_dice(int num_dice, int sides) {
    for (int i = 0; i < num_dice; i++) {
        int roll = roll_die(sides);
        printf("Die %d: %d\n", i + 1, roll);
    }
}

// A function to play a simple dice game
void play_game(int num_dice, int sides) {
    // Roll the dice
    roll_dice(num_dice, sides);

    // Calculate the total score
    int total_score = 0;
    for (int i = 0; i < num_dice; i++) {
        total_score += roll_die(sides);
    }

    // Print the total score
    printf("Total score: %d\n", total_score);
}

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Get the number of dice and sides from the user
    int num_dice;
    printf("Enter the number of dice: ");
    scanf("%d", &num_dice);

    int sides;
    printf("Enter the number of sides per die: ");
    scanf("%d", &sides);

    // Play the game
    play_game(num_dice, sides);

    return 0;
}