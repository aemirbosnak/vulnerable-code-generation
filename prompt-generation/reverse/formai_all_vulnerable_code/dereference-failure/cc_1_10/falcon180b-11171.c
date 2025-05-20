//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 100
#define MAX_SIDES 1000
#define MAX_ROLLS 1000

typedef struct {
    int num_dice;
    int num_sides;
    int num_rolls;
    int *dice_values;
    int *roll_values;
} Dice;

void roll_dice(Dice *dice) {
    for (int i = 0; i < dice->num_rolls; i++) {
        for (int j = 0; j < dice->num_dice; j++) {
            dice->roll_values[i * dice->num_dice + j] = rand() % dice->num_sides + 1;
        }
    }
}

int main() {
    srand(time(NULL));

    int num_dice, num_sides, num_rolls;
    printf("Enter the number of dice: ");
    scanf("%d", &num_dice);
    printf("Enter the number of sides: ");
    scanf("%d", &num_sides);
    printf("Enter the number of rolls: ");
    scanf("%d", &num_rolls);

    Dice dice;
    dice.num_dice = num_dice;
    dice.num_sides = num_sides;
    dice.num_rolls = num_rolls;

    dice.dice_values = (int *)malloc(num_dice * sizeof(int));
    for (int i = 0; i < num_dice; i++) {
        dice.dice_values[i] = i + 1;
    }

    dice.roll_values = (int *)malloc(num_dice * num_rolls * sizeof(int));

    roll_dice(&dice);

    printf("Dice values:\n");
    for (int i = 0; i < num_dice; i++) {
        printf("%d ", dice.dice_values[i]);
    }
    printf("\n");

    printf("Roll values:\n");
    for (int i = 0; i < num_rolls; i++) {
        for (int j = 0; j < num_dice; j++) {
            printf("%d ", dice.roll_values[i * num_dice + j]);
        }
        printf("\n");
    }

    free(dice.dice_values);
    free(dice.roll_values);

    return 0;
}