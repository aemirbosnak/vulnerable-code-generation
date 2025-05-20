//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 100
#define MAX_SIDES 100

// Function to roll a single dice
void roll_dice(int num_sides, int *result) {
    *result = rand() % num_sides + 1;
}

// Recursive function to roll multiple dice
void roll_dice_recursive(int num_dice, int num_sides, int *results) {
    if (num_dice == 1) {
        roll_dice(num_sides, &results[0]);
    } else {
        int i;
        for (i = 0; i < num_dice; i++) {
            roll_dice(num_sides, &results[i]);
        }
    }
}

// Function to print the results of rolling multiple dice
void print_results(int num_dice, int num_sides, int *results) {
    int i;
    printf("Rolled %d dice with %d sides:\n", num_dice, num_sides);
    for (i = 0; i < num_dice; i++) {
        printf("%d\n", results[i]);
    }
}

int main() {
    int num_dice, num_sides, i;
    int *results;

    // Seed the random number generator
    srand(time(NULL));

    // Prompt user for number of dice and sides
    printf("Enter the number of dice: ");
    scanf("%d", &num_dice);
    printf("Enter the number of sides: ");
    scanf("%d", &num_sides);

    // Allocate memory for the results array
    results = (int *) malloc(num_dice * sizeof(int));

    // Roll the dice
    roll_dice_recursive(num_dice, num_sides, results);

    // Print the results
    print_results(num_dice, num_sides, results);

    // Free the memory allocated for the results array
    free(results);

    return 0;
}