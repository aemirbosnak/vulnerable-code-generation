//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 1000
#define MAX_SIDES 1000

int main(int argc, char *argv[]) {
    int num_dice;
    int num_sides;
    int *dice_results;

    printf("Welcome to the Dice Roller!\n");
    printf("How many dice do you want to roll? ");
    scanf("%d", &num_dice);

    if (num_dice > MAX_DICE || num_dice <= 0) {
        printf("Invalid number of dice.\n");
        return 1;
    }

    printf("How many sides do you want on each die? ");
    scanf("%d", &num_sides);

    if (num_sides > MAX_SIDES || num_sides <= 0) {
        printf("Invalid number of sides.\n");
        return 1;
    }

    dice_results = (int *) malloc(num_dice * sizeof(int));

    if (dice_results == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    srand(time(NULL));

    for (int i = 0; i < num_dice; i++) {
        dice_results[i] = rand() % num_sides + 1;
    }

    printf("Here are your results:\n");

    for (int i = 0; i < num_dice; i++) {
        printf("%d-sided die %d rolled a %d.\n", num_sides, i + 1, dice_results[i]);
    }

    free(dice_results);

    return 0;
}