//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 100
#define MAX_SIDES 1000

typedef struct {
    int num_dice;
    int num_sides;
} dice_t;

void roll_dice(dice_t *dice, int num_rolls) {
    int i, j, roll;

    for (i = 0; i < num_rolls; i++) {
        for (j = 0; j < dice->num_dice; j++) {
            roll = rand() % dice->num_sides + 1;
            printf("%d ", roll);
        }
        printf("\n");
    }
}

int main() {
    dice_t dice;
    int num_dice, num_sides, num_rolls;

    srand(time(NULL));

    printf("Enter the number of dice: ");
    scanf("%d", &num_dice);

    printf("Enter the number of sides per die: ");
    scanf("%d", &num_sides);

    if (num_dice <= 0 || num_sides <= 0 || num_dice > MAX_DICE || num_sides > MAX_SIDES) {
        printf("Invalid input.\n");
        return 1;
    }

    dice.num_dice = num_dice;
    dice.num_sides = num_sides;

    printf("Enter the number of rolls: ");
    scanf("%d", &num_rolls);

    if (num_rolls <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    roll_dice(&dice, num_rolls);

    return 0;
}