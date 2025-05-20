//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 1000
#define MIN_VALUE 1
#define MAX_VALUE 6

int main(int argc, char **argv) {
    int num_dice;
    int *dice_values;
    int total_value = 0;
    int i;

    // Get number of dice from user
    printf("Enter the number of dice to roll (1-1000): ");
    scanf("%d", &num_dice);

    // Check if number of dice is within valid range
    if (num_dice < 1 || num_dice > MAX_DICE) {
        printf("Invalid number of dice.\n");
        return 1;
    }

    // Allocate memory for dice values array
    dice_values = (int *) malloc(num_dice * sizeof(int));

    // Check if memory allocation was successful
    if (dice_values == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Roll dice and store values in array
    srand(time(NULL));
    for (i = 0; i < num_dice; i++) {
        dice_values[i] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
        printf("Dice %d rolled a %d.\n", i+1, dice_values[i]);
    }

    // Calculate total value of all dice
    for (i = 0; i < num_dice; i++) {
        total_value += dice_values[i];
    }

    // Print total value of all dice
    printf("The total value of all dice is: %d\n", total_value);

    // Free memory allocated for dice values array
    free(dice_values);

    return 0;
}