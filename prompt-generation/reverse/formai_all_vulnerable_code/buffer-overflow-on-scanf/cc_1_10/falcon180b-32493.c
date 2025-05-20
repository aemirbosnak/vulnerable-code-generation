//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 100
#define MIN_VALUE 1
#define MAX_VALUE 6

typedef struct {
    int num_dice;
    int num_sides;
    int total_value;
} dice_t;

void roll_dice(dice_t *dice) {
    int i;
    for (i = 0; i < dice->num_dice; i++) {
        dice->total_value += rand() % dice->num_sides + 1;
    }
}

void print_dice(dice_t *dice) {
    printf("Rolling %d dice with %d sides:\n", dice->num_dice, dice->num_sides);
    printf("Total value: %d\n", dice->total_value);
}

int main() {
    int num_dice, num_sides;
    int total_dice = 0;
    int total_sides = 0;
    int total_value = 0;
    dice_t dice_array[MAX_DICE];
    int i;

    srand(time(NULL));

    while (total_dice < MAX_DICE) {
        printf("Enter the number of dice (1-100): ");
        scanf("%d", &num_dice);
        if (num_dice < MIN_VALUE || num_dice > MAX_VALUE) {
            printf("Invalid number of dice.\n");
            continue;
        }
        total_dice += num_dice;

        printf("Enter the number of sides (1-6): ");
        scanf("%d", &num_sides);
        if (num_sides < MIN_VALUE || num_sides > MAX_VALUE) {
            printf("Invalid number of sides.\n");
            continue;
        }
        total_sides += num_sides;

        dice_array[total_dice - 1].num_dice = num_dice;
        dice_array[total_dice - 1].num_sides = num_sides;
    }

    printf("Total number of dice: %d\n", total_dice);
    printf("Total number of sides: %d\n", total_sides);

    for (i = 0; i < total_dice; i++) {
        roll_dice(&dice_array[i]);
        print_dice(&dice_array[i]);
        total_value += dice_array[i].total_value;
    }

    printf("Total value of all dice: %d\n", total_value);

    return 0;
}