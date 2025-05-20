//MISTRAL-7B DATASET v1.0 Category: Dice Roller ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIDES 20
#define MAX_DICE 10

typedef struct Dice {
    int sides;
    int roll;
} Dice;

void roll_dice(Dice *dice, int num_dice) {
    time_t seed;
    int i;

    seed = time(NULL);
    srand(seed);

    for (i = 0; i < num_dice; i++) {
        dice[i].roll = 1 + rand() % (dice[i].sides + 1);
    }
}

void print_dice(const Dice *dice, int num_dice) {
    int i;

    for (i = 0; i < num_dice; i++) {
        printf("D%d: %d\n", dice[i].sides, dice[i].roll);
    }
}

int main() {
    Dice dice[MAX_DICE];
    int num_dice, sides;

    printf("Enter the number of dice: ");
    scanf("%d", &num_dice);

    printf("Enter the number of sides on each die: ");
    scanf("%d", &sides);

    if (num_dice > MAX_DICE || sides > MAX_SIDES) {
        printf("Error: too many dice or sides.\n");
        return 1;
    }

    dice[0].sides = sides;

    roll_dice(dice, num_dice);
    print_dice(dice, num_dice);

    return 0;
}

// Protected functions

void Dice_set_sides(Dice *self, int new_sides) {
    if (new_sides > MAX_SIDES) {
        printf("Error: too many sides.\n");
        return;
    }
    self->sides = new_sides;
}

void Dice_roll(Dice *self) {
    self->roll = 1 + rand() % (self->sides + 1);
}

// Protected members
// None in this example