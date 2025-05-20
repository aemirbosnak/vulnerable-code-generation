//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 100
#define MAX_SIDES 1000

// Function prototypes
void roll_dice(int num_dice, int num_sides);
void paranoid_check(int result);

int main() {
    int num_dice, num_sides;
    int i, valid_input = 0;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Get the number of dice and sides from the user
    while (!valid_input) {
        printf("Enter the number of dice (1-100): ");
        scanf("%d", &num_dice);
        if (num_dice < 1 || num_dice > MAX_DICE) {
            printf("Invalid input. Please enter a number between 1 and %d.\n", MAX_DICE);
        } else {
            valid_input = 1;
        }
    }

    valid_input = 0;
    while (!valid_input) {
        printf("Enter the number of sides per dice (1-1000): ");
        scanf("%d", &num_sides);
        if (num_sides < 1 || num_sides > MAX_SIDES) {
            printf("Invalid input. Please enter a number between 1 and %d.\n", MAX_SIDES);
        } else {
            valid_input = 1;
        }
    }

    // Roll the dice
    for (i = 0; i < num_dice; i++) {
        roll_dice(1, num_sides);
        printf("\n");
    }

    return 0;
}

// Function to roll a dice and print the result
void roll_dice(int num_dice, int num_sides) {
    int i, result;

    // Roll the dice
    for (i = 0; i < num_dice; i++) {
        result = rand() % num_sides + 1;
        printf("Dice %d rolled a %d\n", i+1, result);

        // Paranoid check to ensure the result is within the valid range
        paranoid_check(result);
    }
}

// Function to check if the result is within the valid range
void paranoid_check(int result) {
    if (result < 1 || result > MAX_SIDES) {
        printf("Error: Invalid result. Please try again.\n");
        exit(1);
    }
}