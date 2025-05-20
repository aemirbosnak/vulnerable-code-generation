//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIDES 1000
#define MIN_SIDES 1

// Function to generate a random number between 1 and n
int rand_between(int n) {
    return rand() % n + 1;
}

// Function to print a dice roll
void print_roll(int num_sides, int num_dice, int dice_rolls[MAX_SIDES]) {
    printf("Rolling %d %d-sided dice...\n", num_dice, num_sides);
    for (int i = 0; i < num_dice; i++) {
        printf("Dice %d rolled a %d\n", i + 1, dice_rolls[i]);
    }
    printf("Total: %d\n\n", sum_array(dice_rolls, num_dice));
}

// Function to sum an array of integers
int sum_array(int arr[MAX_SIDES], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

// Function to get user input for number of dice and number of sides
void get_input(int *num_dice, int *num_sides) {
    printf("Enter number of dice: ");
    scanf("%d", num_dice);
    printf("Enter number of sides per dice: ");
    scanf("%d", num_sides);
}

// Main function
int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    // Get user input
    int num_dice, num_sides;
    get_input(&num_dice, &num_sides);

    // Validate user input
    if (num_dice < MIN_SIDES || num_dice > MAX_SIDES) {
        printf("Invalid number of dice\n");
        return 1;
    }
    if (num_sides < MIN_SIDES || num_sides > MAX_SIDES) {
        printf("Invalid number of sides\n");
        return 1;
    }

    // Roll the dice
    int dice_rolls[MAX_SIDES];
    for (int i = 0; i < num_dice; i++) {
        dice_rolls[i] = rand_between(num_sides);
    }

    // Print the results
    print_roll(num_sides, num_dice, dice_rolls);

    return 0;
}