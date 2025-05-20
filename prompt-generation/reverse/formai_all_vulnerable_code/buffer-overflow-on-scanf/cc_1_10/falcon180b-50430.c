//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 1000
#define MAX_SIDES 1000

typedef struct {
    int num_dice;
    int num_sides;
    int *dice_values;
} dice_roll_t;

void roll_dice(dice_roll_t *roll) {
    int i;
    for (i = 0; i < roll->num_dice; i++) {
        roll->dice_values[i] = rand() % roll->num_sides + 1;
    }
}

int main() {
    int num_dice, num_sides;
    int *dice_values;
    dice_roll_t roll;

    // Get user input for number of dice and number of sides
    printf("Enter the number of dice: ");
    scanf("%d", &num_dice);
    printf("Enter the number of sides: ");
    scanf("%d", &num_sides);

    // Allocate memory for dice_values array
    dice_values = malloc(num_dice * sizeof(int));
    if (dice_values == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }

    // Initialize dice_roll_t struct
    roll.num_dice = num_dice;
    roll.num_sides = num_sides;
    roll.dice_values = dice_values;

    // Roll the dice
    roll_dice(&roll);

    // Print the results
    printf("You rolled %d dice with %d sides each:\n", num_dice, num_sides);
    for (int i = 0; i < num_dice; i++) {
        printf("%d ", dice_values[i]);
    }
    printf("\n");

    // Free memory
    free(dice_values);

    return 0;
}