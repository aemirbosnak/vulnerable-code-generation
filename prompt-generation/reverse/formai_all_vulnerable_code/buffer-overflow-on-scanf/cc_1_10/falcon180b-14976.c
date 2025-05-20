//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIDES 100
#define MAX_DICE 100

typedef struct {
    int sides;
    int *rolls;
} Dice;

void roll_dice(Dice *dice, int num_rolls) {
    for (int i = 0; i < num_rolls; i++) {
        dice->rolls[i] = rand() % dice->sides + 1;
    }
}

void print_dice_rolls(Dice *dice, int num_rolls) {
    for (int i = 0; i < num_rolls; i++) {
        printf("%d ", dice->rolls[i]);
    }
    printf("\n");
}

int main() {
    int num_dice, num_sides, num_rolls;
    srand(time(NULL));

    printf("Enter number of dice: ");
    scanf("%d", &num_dice);

    Dice *dice = malloc(num_dice * sizeof(Dice));

    for (int i = 0; i < num_dice; i++) {
        printf("Enter number of sides for dice %d: ", i+1);
        scanf("%d", &num_sides);
        dice[i].sides = num_sides;
        dice[i].rolls = malloc(num_sides * sizeof(int));
    }

    printf("Enter number of rolls: ");
    scanf("%d", &num_rolls);

    for (int i = 0; i < num_dice; i++) {
        roll_dice(&dice[i], num_rolls);
        print_dice_rolls(&dice[i], num_rolls);
    }

    free(dice);

    return 0;
}