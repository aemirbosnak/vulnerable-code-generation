//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_sides, num_rolls, max_roll, total_rolls = 0;
    int roll, i;
    float avg_roll;
    char play_again;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Get the number of sides on the dice from the user
    printf("Enter the number of sides on the dice: ");
    scanf("%d", &num_sides);

    // Get the number of rolls from the user
    printf("Enter the number of rolls: ");
    scanf("%d", &num_rolls);

    // Initialize the maximum roll to 0
    max_roll = 0;

    // Roll the dice num_rolls times
    for (i = 0; i < num_rolls; i++) {
        // Roll the dice
        roll = rand() % num_sides + 1;

        // Update the total number of rolls
        total_rolls++;

        // Update the maximum roll if necessary
        if (roll > max_roll) {
            max_roll = roll;
        }
    }

    // Calculate the average roll
    avg_roll = (float) total_rolls / num_rolls;

    // Print the results
    printf("Total number of rolls: %d\n", total_rolls);
    printf("Maximum roll: %d\n", max_roll);
    printf("Average roll: %.2f\n", avg_roll);

    // Ask the user if they want to play again
    printf("Do you want to play again? (y/n): ");
    scanf(" %c", &play_again);

    // If the user wants to play again, start over
    if (play_again == 'y' || play_again == 'Y') {
        main();
    }

    return 0;
}