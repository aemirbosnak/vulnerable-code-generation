//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIDES 10000
#define MAX_DICE 1000

typedef struct {
    int num_sides;
    int num_dice;
    int *values;
} DiceRoller;

void init_dice_roller(DiceRoller *dr, int num_sides, int num_dice) {
    dr->num_sides = num_sides;
    dr->num_dice = num_dice;
    dr->values = malloc(sizeof(int) * num_dice);
    srand(time(NULL));
    for (int i = 0; i < num_dice; i++) {
        dr->values[i] = rand() % num_sides + 1;
    }
}

void roll_dice(DiceRoller *dr) {
    for (int i = 0; i < dr->num_dice; i++) {
        printf("%d ", dr->values[i]);
    }
    printf("\n");
}

void free_dice_roller(DiceRoller *dr) {
    free(dr->values);
}

void recursive_roll_dice(DiceRoller *dr, int depth) {
    if (depth == 0) {
        roll_dice(dr);
    } else {
        for (int i = 0; i < dr->num_dice; i++) {
            dr->values[i] = rand() % dr->num_sides + 1;
        }
        recursive_roll_dice(dr, depth - 1);
    }
}

int main(void) {
    DiceRoller dr;
    int num_sides, num_dice;

    printf("Enter the number of sides on the dice: ");
    scanf("%d", &num_sides);

    printf("Enter the number of dice to roll: ");
    scanf("%d", &num_dice);

    init_dice_roller(&dr, num_sides, num_dice);

    int depth;
    printf("Enter the depth of recursion: ");
    scanf("%d", &depth);

    recursive_roll_dice(&dr, depth);

    free_dice_roller(&dr);

    return 0;
}