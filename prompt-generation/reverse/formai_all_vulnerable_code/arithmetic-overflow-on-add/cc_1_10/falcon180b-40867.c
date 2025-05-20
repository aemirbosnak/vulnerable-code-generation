//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM_DICE 100
#define MAX_NUM_SIDES 100

typedef struct {
    int num_dice;
    int num_sides;
    int *rolls;
} dice_t;

void init_dice(dice_t *dice, int num_dice, int num_sides) {
    dice->num_dice = num_dice;
    dice->num_sides = num_sides;
    dice->rolls = malloc(num_dice * sizeof(int));
}

void roll_dice(dice_t *dice) {
    for (int i = 0; i < dice->num_dice; i++) {
        dice->rolls[i] = rand() % dice->num_sides + 1;
    }
}

void print_dice(dice_t *dice) {
    for (int i = 0; i < dice->num_dice; i++) {
        printf("%d ", dice->rolls[i]);
    }
    printf("\n");
}

void free_dice(dice_t *dice) {
    free(dice->rolls);
}

int main() {
    srand(time(NULL));

    int num_dice;
    int num_sides;

    printf("Enter the number of dice: ");
    scanf("%d", &num_dice);

    printf("Enter the number of sides on each dice: ");
    scanf("%d", &num_sides);

    dice_t dice;
    init_dice(&dice, num_dice, num_sides);

    roll_dice(&dice);
    print_dice(&dice);

    free_dice(&dice);

    return 0;
}