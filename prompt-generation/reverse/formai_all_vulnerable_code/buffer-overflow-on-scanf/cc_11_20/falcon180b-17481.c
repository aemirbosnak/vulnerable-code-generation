//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_DICE 100
#define MAX_SIDES 1000

int main() {
    int num_dice;
    int max_sides;
    int num_rolls;
    int *dice_sides;
    int *rolls;
    int i;
    int j;
    int k;
    int total;
    srand(time(NULL));

    printf("Enter the number of dice: ");
    scanf("%d", &num_dice);

    printf("Enter the maximum number of sides for each die: ");
    scanf("%d", &max_sides);

    if (max_sides <= 0 || max_sides > MAX_SIDES) {
        printf("Invalid maximum number of sides.\n");
        return 1;
    }

    dice_sides = (int *) malloc(num_dice * sizeof(int));
    rolls = (int *) malloc(num_dice * sizeof(int));

    if (dice_sides == NULL || rolls == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the number of sides for each die: ");

    for (i = 0; i < num_dice; i++) {
        scanf("%d", &dice_sides[i]);

        if (dice_sides[i] <= 0 || dice_sides[i] > max_sides) {
            printf("Invalid number of sides for die %d.\n", i + 1);
            return 1;
        }
    }

    printf("Enter the number of rolls: ");
    scanf("%d", &num_rolls);

    if (num_rolls <= 0) {
        printf("Invalid number of rolls.\n");
        return 1;
    }

    for (i = 0; i < num_rolls; i++) {
        for (j = 0; j < num_dice; j++) {
            rolls[j] = rand() % dice_sides[j];
        }

        total = 0;

        for (j = 0; j < num_dice; j++) {
            total += rolls[j];
        }

        printf("Roll %d: ", i + 1);

        for (j = 0; j < num_dice; j++) {
            printf("%d ", rolls[j]);
        }

        printf("Total: %d\n", total);
    }

    free(dice_sides);
    free(rolls);

    return 0;
}