//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIDES 1000
#define MAX_DICE 100

int main() {
    int num_dice, num_sides, i, j;
    int *dice_values;
    char roll_again;

    srand(time(NULL));

    do {
        printf("Enter the number of dice: ");
        scanf("%d", &num_dice);
        if (num_dice <= 0 || num_dice > MAX_DICE) {
            printf("Invalid number of dice. Please enter a number between 1 and %d.\n", MAX_DICE);
        }
    } while (num_dice <= 0 || num_dice > MAX_DICE);

    do {
        printf("Enter the number of sides per die: ");
        scanf("%d", &num_sides);
        if (num_sides < 1 || num_sides > MAX_SIDES) {
            printf("Invalid number of sides. Please enter a number between 1 and %d.\n", MAX_SIDES);
        }
    } while (num_sides < 1 || num_sides > MAX_SIDES);

    dice_values = (int *)malloc(num_dice * sizeof(int));

    for (i = 0; i < num_dice; i++) {
        dice_values[i] = rand() % num_sides + 1;
    }

    printf("Rolling %d %d-sided dice...\n", num_dice, num_sides);

    for (i = 0; i < num_dice; i++) {
        printf("Die %d: %d\n", i+1, dice_values[i]);
    }

    printf("Do you want to roll again? (y/n): ");
    scanf(" %c", &roll_again);

    while (roll_again == 'y' || roll_again == 'Y') {
        for (i = 0; i < num_dice; i++) {
            dice_values[i] = rand() % num_sides + 1;
        }

        printf("\nRolling %d %d-sided dice...\n", num_dice, num_sides);

        for (i = 0; i < num_dice; i++) {
            printf("Die %d: %d\n", i+1, dice_values[i]);
        }

        printf("Do you want to roll again? (y/n): ");
        scanf(" %c", &roll_again);
    }

    free(dice_values);

    return 0;
}