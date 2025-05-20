//MISTRAL-7B DATASET v1.0 Category: Dice Roller ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define custom dice roll structure
typedef struct {
    int sides;
    int roll[6];
} dice_t;

// Function to roll a dice
void roll_dice(dice_t *dice) {
    int i;

    // Seed random number generator
    srand(time(NULL));

    // Roll each side of the dice
    for (i = 0; i < dice->sides; i++) {
        dice->roll[i] = rand() % dice->sides + 1;
    }
}

// Function to print the result of a dice roll
void print_roll(dice_t dice) {
    int i;

    printf("Rolled %d sided dice and got:\n", dice.sides);

    // Print each roll result
    for (i = 0; i < dice.sides; i++) {
        printf("Roll %d: %d\n", i + 1, dice.roll[i]);
    }
}

// Function to simulate multiple dice rolls
void simulate_rolls(int num_rolls, int num_sides) {
    dice_t dice;
    int i;

    dice.sides = num_sides;

    // Roll dice and print results for each roll
    for (i = 0; i < num_rolls; i++) {
        roll_dice(&dice);
        print_roll(dice);
    }
}

// Main function
int main() {
    int num_rolls, num_sides;

    // Get user input for number of rolls and sides
    printf("Enter number of rolls: ");
    scanf("%d", &num_rolls);
    printf("Enter number of sides: ");
    scanf("%d", &num_sides);

    // Simulate dice rolls
    simulate_rolls(num_rolls, num_sides);

    return 0;
}