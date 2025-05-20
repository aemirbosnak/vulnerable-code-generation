//FormAI DATASET v1.0 Category: Dice Roller ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// This program simulates a dice roller game.

// Function to randomly generate a number between 1 and 6.
int generate_random_number() {
    int number = (rand() % 6) + 1;
    return number;
}

int main() {

    // Seed the random number generator with the current time.
    srand(time(NULL));

    int total_score = 0;
    int current_roll = 0;

    // Loop until the user decides to stop playing.
    while(1) {

        // Ask the user if they want to roll the dice.
        printf("Do you want to roll the dice? (y/n): ");

        // Get the user's input.
        char input;
        scanf(" %c", &input);

        // If the user types 'n', exit the loop.
        if (input == 'n') {
            break;
        }

        // Roll the dice.
        current_roll = generate_random_number();
        printf("You rolled a %d.\n", current_roll);

        // If the user rolls a 1, reset their score to 0.
        if (current_roll == 1) {
            printf("You lose all your points!\n");
            total_score = 0;
        } else {
            total_score += current_roll;
            printf("Your current score is %d.\n", total_score);
        }
    }

    printf("Your final score is %d. Thanks for playing!\n", total_score);

    return 0;
}