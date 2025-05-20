//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants for the number of sides on the dice
#define NUM_SIDES_D4 4
#define NUM_SIDES_D6 6
#define NUM_SIDES_D8 8
#define NUM_SIDES_D10 10
#define NUM_SIDES_D12 12
#define NUM_SIDES_D20 20

// Function to generate a random number between 1 and the specified number of sides
int roll_die(int num_sides) {
    return rand() % num_sides + 1;
}

// Function to simulate rolling multiple dice
void roll_multiple_dice(int num_dice, int num_sides) {
    int i;
    int roll;

    for (i = 0; i < num_dice; i++) {
        roll = roll_die(num_sides);
        printf("Die %d: %d\n", i + 1, roll);
    }
}

// Function to get the sum of the rolls from multiple dice
int get_sum_of_rolls(int num_dice, int num_sides) {
    int i;
    int roll;
    int sum = 0;

    for (i = 0; i < num_dice; i++) {
        roll = roll_die(num_sides);
        sum += roll;
    }

    return sum;
}

// Function to get the average roll from multiple dice
float get_average_roll(int num_dice, int num_sides) {
    float sum = get_sum_of_rolls(num_dice, num_sides);
    return sum / num_dice;
}

// Function to print the results of a dice roll
void print_results(int num_dice, int num_sides, int sum, float average) {
    printf("You rolled %d %d-sided dice.\n", num_dice, num_sides);
    printf("The sum of the rolls is %d.\n", sum);
    printf("The average roll is %.2f.\n", average);
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Get the number of dice and the number of sides from the user
    int num_dice;
    int num_sides;
    printf("How many dice would you like to roll? ");
    scanf("%d", &num_dice);
    printf("How many sides should each die have? ");
    scanf("%d", &num_sides);

    // Roll the dice and get the sum and average of the rolls
    int sum = get_sum_of_rolls(num_dice, num_sides);
    float average = get_average_roll(num_dice, num_sides);

    // Print the results of the dice roll
    print_results(num_dice, num_sides, sum, average);

    return 0;
}