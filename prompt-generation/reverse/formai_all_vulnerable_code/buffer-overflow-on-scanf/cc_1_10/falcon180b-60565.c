//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIDES 6
#define MAX_DICE 100
#define MIN_VALUE 1
#define MAX_VALUE SIDES

// Function to generate a random number between min and max
int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to roll a single die
void roll_die(int *value) {
    *value = rand_int(1, SIDES);
}

// Function to roll multiple dice and calculate the total value
int roll_dice(int num_dice, int *values) {
    int total_value = 0;
    for (int i = 0; i < num_dice; i++) {
        roll_die(&values[i]);
        total_value += values[i];
    }
    return total_value;
}

// Function to print the result of a dice roll
void print_result(int total_value, int num_dice) {
    printf("You rolled %d dice and got a total value of %d.\n", num_dice, total_value);
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    // Get the number of dice to roll from the user
    int num_dice;
    printf("How many dice do you want to roll? ");
    scanf("%d", &num_dice);

    // Make sure the number of dice is within the allowed range
    if (num_dice < 1 || num_dice > MAX_DICE) {
        printf("Invalid number of dice.\n");
        return 1;
    }

    // Roll the dice and print the result
    int values[MAX_DICE];
    int total_value = roll_dice(num_dice, values);
    print_result(total_value, num_dice);

    return 0;
}