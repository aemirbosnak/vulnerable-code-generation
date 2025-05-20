//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_DICE 1000
#define MIN_SIDES 1
#define MAX_SIDES 1000

typedef struct {
    int sides;
    int count;
} dice_t;

void roll_dice(dice_t* dice, int num_dice, int sides) {
    srand(time(NULL));

    for (int i = 0; i < num_dice; i++) {
        dice[i].sides = sides;
        dice[i].count = rand() % sides + 1;
    }
}

void print_rolls(dice_t* dice, int num_dice) {
    for (int i = 0; i < num_dice; i++) {
        printf("Roll %d: %d\n", i+1, dice[i].count);
    }
}

int main() {
    int num_dice;
    printf("Enter the number of dice to roll (1 to %d): ", MAX_DICE);
    scanf("%d", &num_dice);

    if (num_dice > MAX_DICE || num_dice < 1) {
        printf("Invalid number of dice.\n");
        return 1;
    }

    int sides;
    printf("Enter the number of sides on each die (1 to %d): ", MAX_SIDES);
    scanf("%d", &sides);

    if (sides > MAX_SIDES || sides < MIN_SIDES) {
        printf("Invalid number of sides.\n");
        return 1;
    }

    dice_t dice[num_dice];
    roll_dice(dice, num_dice, sides);
    print_rolls(dice, num_dice);

    return 0;
}