//MISTRAL-7B DATASET v1.0 Category: Dice Roller ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_DIE_SIDE 4
#define MAX_DIE_SIDE 20
#define NUM_DICE 6

int main() {
    int die_sides, die_num, rolled_value;
    int *dice;

    // Ask user for number of sides and dice
    printf("Enter the number of sides for each die: ");
    scanf("%d", &die_sides);
    printf("Enter the number of dice: ");
    scanf("%d", &die_num);

    // Validate user input
    if (die_sides < MIN_DIE_SIDE || die_sides > MAX_DIE_SIDE) {
        printf("Invalid number of sides for die. Defaulting to 6.\n");
        die_sides = 6;
    }

    if (die_num < 1) {
        printf("Invalid number of dice. Defaulting to 6.\n");
        die_num = 6;
    }

    // Allocate memory for dice array
    dice = (int *)calloc(die_num, sizeof(int));

    if (dice == NULL) {
        perror("Failed to allocate memory for dice array.\n");
        return EXIT_FAILURE;
    }

    // Seed random number generator
    srand(time(NULL));

    // Roll dice
    for (int i = 0; i < die_num; ++i) {
        rolled_value = rand() % die_sides + 1;
        dice[i] = rolled_value;
        printf("Die %d rolled: %d\n", i + 1, rolled_value);
    }

    // Free allocated memory
    free(dice);

    return EXIT_SUCCESS;
}