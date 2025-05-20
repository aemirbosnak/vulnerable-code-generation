//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define SIDES 6
#define MAX_DICE 1000
#define MAX_ROLLS 1000000

int main() {
    srand(time(NULL));

    int num_dice, num_rolls, total_rolls = 0;
    int *dice_values = NULL;

    printf("Welcome to the C Dice Roller!\n");
    printf("How many dice would you like to roll? (1-%d): ", MAX_DICE);
    scanf("%d", &num_dice);

    if (num_dice < 1 || num_dice > MAX_DICE) {
        printf("Invalid number of dice.\n");
        return 1;
    }

    dice_values = (int *) malloc(num_dice * sizeof(int));
    if (dice_values == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("How many times would you like to roll the dice? (1-%d): ", MAX_ROLLS);
    scanf("%d", &num_rolls);

    if (num_rolls < 1 || num_rolls > MAX_ROLLS) {
        printf("Invalid number of rolls.\n");
        free(dice_values);
        return 1;
    }

    printf("Rolling the dice...\n");
    for (int i = 0; i < num_rolls; i++) {
        for (int j = 0; j < num_dice; j++) {
            dice_values[j] = rand() % SIDES + 1;
        }

        printf("Roll %d:\n", i + 1);
        for (int j = 0; j < num_dice; j++) {
            printf("%d ", dice_values[j]);
        }

        printf("\n");

        total_rolls++;
    }

    printf("Finished rolling the dice.\n");
    printf("Total number of rolls: %d\n", total_rolls);

    free(dice_values);
    return 0;
}