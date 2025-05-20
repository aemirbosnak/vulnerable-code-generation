//MISTRAL-7B DATASET v1.0 Category: Dice Roller ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a custom struct for a dice roll
typedef struct {
    int sides;
    int value;
} dice_t;

// Function to roll a dice with the given number of sides
void roll_dice(dice_t *dice) {
    if (dice->sides <= 0) {
        printf("Invalid number of sides for dice.\n");
        return;
    }

    // Seed the random number generator with current time
    srand(time(NULL));

    // Generate a random number between 1 and the number of sides
    dice->value = rand() % (dice->sides + 1);
}

// Function to print the result of rolling a dice
void print_roll(dice_t dice) {
    printf("Rolled a %d on a %d-sided dice.\n", dice.value, dice.sides);
}

// Main function to simulate rolling multiple dice
int main() {
    int num_dice, sides_per_die;

    // Get the number of dice and sides per die from user input
    printf("Enter the number of dice: ");
    scanf("%d", &num_dice);
    printf("Enter the number of sides per die: ");
    scanf("%d", &sides_per_die);

    // Allocate memory for an array of dice
    dice_t *dice = malloc(num_dice * sizeof(dice_t));

    // Initialize each dice with the given number of sides
    for (int i = 0; i < num_dice; i++) {
        dice[i].sides = sides_per_die;
    }

    // Roll each dice and print the result
    for (int i = 0; i < num_dice; i++) {
        roll_dice(&dice[i]);
        print_roll(dice[i]);
    }

    // Free the allocated memory
    free(dice);

    return 0;
}