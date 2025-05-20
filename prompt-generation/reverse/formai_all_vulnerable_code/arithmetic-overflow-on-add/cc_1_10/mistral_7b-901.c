//MISTRAL-7B DATASET v1.0 Category: Dice Roller ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 10
#define MAX_SIDES 6
#define MAX_ROLLS 10

typedef struct {
    int sides;
    int rolls[MAX_ROLLS];
    int total;
} dice_t;

void roll_dice(dice_t *dice) {
    for (int i = 0; i < MAX_ROLLS; i++) {
        dice->rolls[i] = rand() % (dice->sides + 1);
        dice->total += dice->rolls[i];
    }
}

void print_dice(dice_t dice) {
    printf("\nDice with %d sides rolled %d times:\n", dice.sides, MAX_ROLLS);
    printf("Rolls:\n");

    for (int i = 0; i < MAX_ROLLS; i++) {
        printf("Roll %d: %d\n", i + 1, dice.rolls[i]);
    }

    printf("\nTotal: %d\n", dice.total);
}

int main() {
    srand(time(NULL));

    dice_t my_dice[MAX_DICE];

    for (int i = 0; i < MAX_DICE; i++) {
        printf("Enter number of sides for dice %d: ", i + 1);
        scanf("%d", &my_dice[i].sides);

        if (my_dice[i].sides > MAX_SIDES || my_dice[i].sides < 1) {
            printf("Invalid number of sides! Try again.\n");
            i--;
            continue;
        }

        roll_dice(&my_dice[i]);
        print_dice(my_dice[i]);
    }

    return 0;
}