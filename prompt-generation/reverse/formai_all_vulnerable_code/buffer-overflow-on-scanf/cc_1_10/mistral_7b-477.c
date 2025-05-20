//MISTRAL-7B DATASET v1.0 Category: Dice Roller ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_DICE_MAX 10
#define SIDE_MAX 6

typedef struct {
    int sides;
    int value;
} Die;

void roll_die(Die *dice) {
    dice->value = rand() % dice->sides + 1;
}

int main() {
    int num_dice, num_sides;
    Die *dice_arr;

    printf("Welcome to the Dice Roller!\n");
    printf("Please enter the number of dice to roll: ");
    scanf("%d", &num_dice);

    if (num_dice > NUM_DICE_MAX) {
        printf("Error: maximum number of dice is %d.\n", NUM_DICE_MAX);
        return 1;
    }

    dice_arr = (Die *)malloc(num_dice * sizeof(Die));

    printf("Please enter the number of sides on each die: ");
    scanf("%d", &num_sides);

    if (num_sides > SIDE_MAX) {
        printf("Error: maximum number of sides on a die is %d.\n", SIDE_MAX);
        free(dice_arr);
        return 1;
    }

    for (int i = 0; i < num_dice; i++) {
        dice_arr[i].sides = num_sides;
    }

    srand(time(NULL));

    printf("\nRolling the dice...\n");
    for (int i = 0; i < num_dice; i++) {
        roll_die(&dice_arr[i]);
        printf("Die %d rolled a %d.\n", i + 1, dice_arr[i].value);
    }

    free(dice_arr);

    return 0;
}