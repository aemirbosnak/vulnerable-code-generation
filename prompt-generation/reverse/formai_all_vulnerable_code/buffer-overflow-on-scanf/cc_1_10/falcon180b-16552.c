//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIDES 100
#define MAX_DICE 100

struct die {
    int sides;
    int value;
};

struct roll {
    int num_dice;
    struct die dice[MAX_DICE];
};

void roll_dice(struct roll *roll) {
    for (int i = 0; i < roll->num_dice; i++) {
        roll->dice[i].value = rand() % roll->dice[i].sides + 1;
    }
}

void print_roll(struct roll *roll) {
    printf("Rolled %d dice with %d sides:\n", roll->num_dice, roll->dice[0].sides);
    for (int i = 0; i < roll->num_dice; i++) {
        printf("Die %d: %d\n", i+1, roll->dice[i].value);
    }
}

int main() {
    srand(time(NULL));

    int num_dice;
    printf("How many dice do you want to roll? ");
    scanf("%d", &num_dice);

    if (num_dice > MAX_DICE) {
        printf("Sorry, you can only roll up to %d dice at a time.\n", MAX_DICE);
        return 1;
    }

    struct roll roll;
    roll.num_dice = num_dice;

    int sides;
    printf("Enter the number of sides for each die: ");
    scanf("%d", &sides);

    if (sides > MAX_SIDES) {
        printf("Sorry, each die can have at most %d sides.\n", MAX_SIDES);
        return 1;
    }

    for (int i = 0; i < num_dice; i++) {
        roll.dice[i].sides = sides;
    }

    roll_dice(&roll);
    print_roll(&roll);

    return 0;
}