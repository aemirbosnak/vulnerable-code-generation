//MISTRAL-7B DATASET v1.0 Category: Dice Roller ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int sides;
    int rolled_values[6];
} Dice;

void roll_dice(Dice *dice) {
    int i;
    for (i = 0; i < 6; i++) {
        dice->rolled_values[i] = rand() % dice->sides + 1;
    }
}

void print_dice_roll(const Dice *dice) {
    int i;
    printf("Rolled:");
    for (i = 0; i < 6; i++) {
        printf(" %d", dice->rolled_values[i]);
    }
    printf("\n");
}

void roll_d20_with_modifier(Dice *dice, int modifier) {
    roll_dice(dice);
    int total = 0;
    int i;
    for (i = 0; i < 6; i++) {
        total += dice->rolled_values[i];
    }
    total += modifier;
    printf("Rolled a d20 with modifier %d and got a total of %d.\n", modifier, total);
}

void roll_percentile(Dice *dice) {
    roll_dice(dice);
    int total = 0;
    int i;
    for (i = 0; i < 10; i++) {
        total += dice->rolled_values[i];
    }
    double percent = (double) total / 100.0;
    printf("Rolled %d on 10 percentile dice and got %0.2f%%.\n", total, percent * 100);
}

int main() {
    srand(time(NULL));

    Dice standard_dice = {6, {0}};
    Dice d20 = {20, {0}};
    Dice percentile_dice = {10, {0}};

    printf("Rolling a standard 6-sided dice:\n");
    roll_dice(&standard_dice);
    print_dice_roll(&standard_dice);

    printf("Rolling a d20 with a modifier of 5:\n");
    roll_d20_with_modifier(&d20, 5);

    printf("Rolling 10 10-sided percentile dice:\n");
    roll_percentile(&percentile_dice);

    return 0;
}