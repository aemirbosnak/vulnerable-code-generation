//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 1000
#define MAX_SIDES 1000
#define MAX_ROLLS 1000

typedef struct {
    int num_sides;
    int num_dice;
    int num_rolls;
    int *rolls;
} dice_t;

void init_dice(dice_t *dice) {
    dice->num_sides = 0;
    dice->num_dice = 0;
    dice->num_rolls = 0;
    dice->rolls = NULL;
}

void roll_dice(dice_t *dice) {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < dice->num_rolls; i++) {
        for (j = 0; j < dice->num_dice; j++) {
            dice->rolls[i * dice->num_dice + j] = rand() % dice->num_sides + 1;
        }
    }
}

void print_dice(dice_t *dice) {
    int i, j;
    for (i = 0; i < dice->num_rolls; i++) {
        for (j = 0; j < dice->num_dice; j++) {
            printf("%d ", dice->rolls[i * dice->num_dice + j]);
        }
        printf("\n");
    }
}

int main() {
    dice_t dice;
    int choice;
    init_dice(&dice);

    do {
        printf("Enter number of sides per die: ");
        scanf("%d", &dice.num_sides);
        printf("Enter number of dice: ");
        scanf("%d", &dice.num_dice);
        printf("Enter number of rolls: ");
        scanf("%d", &dice.num_rolls);

        if (dice.num_sides <= 0 || dice.num_dice <= 0 || dice.num_rolls <= 0) {
            printf("Invalid input. Please try again.\n");
        }
    } while (dice.num_sides <= 0 || dice.num_dice <= 0 || dice.num_rolls <= 0);

    dice.rolls = (int *)malloc(dice.num_rolls * dice.num_dice * sizeof(int));

    roll_dice(&dice);
    printf("Rolling %d %d-sided dice %d times:\n", dice.num_dice, dice.num_sides, dice.num_rolls);
    print_dice(&dice);

    free(dice.rolls);

    return 0;
}