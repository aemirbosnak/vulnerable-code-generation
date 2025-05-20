//Code Llama-13B DATASET v1.0 Category: Dice Roller ; Style: paranoid
// Dice Roller (Paranoid Style)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Function to generate a random number between 1 and 6
int roll_dice() {
    srand(time(NULL));
    int dice_roll = (rand() % 6) + 1;
    return dice_roll;
}

// Function to check if the dice roll is paranoid
bool is_paranoid(int dice_roll) {
    if (dice_roll == 6) {
        return true;
    }
    return false;
}

int main() {
    // Initialize variables
    int dice_roll = 0;
    int paranoid_rolls = 0;

    // Loop until the user enters "quit"
    while (true) {
        // Generate a random number between 1 and 6
        dice_roll = roll_dice();

        // Check if the dice roll is paranoid
        if (is_paranoid(dice_roll)) {
            // If the dice roll is paranoid, increment the paranoid rolls counter
            paranoid_rolls++;
            printf("Paranoid roll! Roll again.\n");
        } else {
            // If the dice roll is not paranoid, print the result and ask the user to roll again
            printf("Dice roll: %d\n", dice_roll);
            printf("Roll again? (y/n) ");
            char answer;
            scanf("%c", &answer);

            // Check if the user wants to quit
            if (answer == 'q' || answer == 'Q') {
                printf("Quitting...\n");
                break;
            }
        }
    }

    // Print the number of paranoid rolls
    printf("Paranoid rolls: %d\n", paranoid_rolls);

    return 0;
}