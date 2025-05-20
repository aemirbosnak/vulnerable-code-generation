//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIDES 100
#define MAX_DICE 100

typedef struct {
    int num_sides;
    int value;
} Die;

typedef struct {
    int num_dice;
    Die dice[MAX_DICE];
} Roll;

void init_die(Die* die, int num_sides) {
    die->num_sides = num_sides;
    die->value = rand() % num_sides + 1;
}

void init_roll(Roll* roll, int num_dice, int num_sides) {
    roll->num_dice = num_dice;
    for (int i = 0; i < num_dice; i++) {
        init_die(&roll->dice[i], num_sides);
    }
}

int roll_dice(Roll* roll) {
    int total = 0;
    for (int i = 0; i < roll->num_dice; i++) {
        total += roll->dice[i].value;
    }
    return total;
}

int main() {
    srand(time(NULL));

    Roll roll;
    int num_dice, num_sides;

    printf("Enter the number of dice to roll: ");
    scanf("%d", &num_dice);

    printf("Enter the number of sides on each die: ");
    scanf("%d", &num_sides);

    init_roll(&roll, num_dice, num_sides);

    int result = roll_dice(&roll);

    printf("You rolled %d with %d dice, each with %d sides.\n", result, num_dice, num_sides);

    return 0;
}