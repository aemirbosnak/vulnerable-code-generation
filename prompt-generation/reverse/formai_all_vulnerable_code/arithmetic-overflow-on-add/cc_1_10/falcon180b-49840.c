//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 1000

int main() {
    int num_dice;
    int num_sides;
    int num_rolls;
    int total_rolls = 0;
    int *dice_rolls = NULL;
    int i, j;

    printf("Welcome to the Dice Roller!\n");
    printf("How many dice would you like to roll? ");
    scanf("%d", &num_dice);

    dice_rolls = (int *) malloc(num_dice * sizeof(int));

    if (dice_rolls == NULL) {
        printf("Error: Could not allocate memory.\n");
        exit(1);
    }

    printf("How many sides should each dice have? ");
    scanf("%d", &num_sides);

    printf("How many times would you like to roll the dice? ");
    scanf("%d", &num_rolls);

    srand(time(NULL));

    for (i = 0; i < num_rolls; i++) {
        for (j = 0; j < num_dice; j++) {
            dice_rolls[j] = rand() % num_sides + 1;
            total_rolls += dice_rolls[j];
        }

        printf("Roll %d:\n", i + 1);
        for (j = 0; j < num_dice; j++) {
            printf("Dice %d: %d\n", j + 1, dice_rolls[j]);
        }
        printf("\n");
    }

    printf("Total rolls: %d\n", total_rolls);

    free(dice_rolls);
    return 0;
}