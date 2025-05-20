//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 100

int main() {
    int num_dice;
    int num_sides;
    int total_rolls;
    int *dice_values;
    int i;
    int max_value = 0;
    int min_value = 9999;
    int sum = 0;
    char play_again = 'y';

    srand(time(NULL));

    do {
        printf("How many dice do you want to roll? (1-100): ");
        scanf("%d", &num_dice);
        if (num_dice < 1 || num_dice > MAX_DICE) {
            printf("Invalid number of dice. Please try again.\n");
        }
    } while (num_dice < 1 || num_dice > MAX_DICE);

    do {
        printf("How many sides do you want on each die? (2-1000): ");
        scanf("%d", &num_sides);
        if (num_sides < 2 || num_sides > 1000) {
            printf("Invalid number of sides. Please try again.\n");
        }
    } while (num_sides < 2 || num_sides > 1000);

    dice_values = (int *) malloc(num_dice * sizeof(int));

    for (i = 0; i < num_dice; i++) {
        dice_values[i] = rand() % num_sides + 1;
        if (dice_values[i] > max_value) {
            max_value = dice_values[i];
        }
        if (dice_values[i] < min_value) {
            min_value = dice_values[i];
        }
        sum += dice_values[i];
    }

    printf("Rolling %d dice with %d sides:\n", num_dice, num_sides);
    for (i = 0; i < num_dice; i++) {
        printf("%d ", dice_values[i]);
    }
    printf("\n");

    printf("Total rolls: %d\n", total_rolls);
    printf("Average roll: %.2f\n", (float) sum / total_rolls);
    printf("Highest roll: %d\n", max_value);
    printf("Lowest roll: %d\n", min_value);

    printf("Play again? (y/n): ");
    scanf(" %c", &play_again);

    free(dice_values);

    return 0;
}