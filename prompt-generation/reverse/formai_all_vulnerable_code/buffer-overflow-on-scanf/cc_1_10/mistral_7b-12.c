//MISTRAL-7B DATASET v1.0 Category: Dice Roller ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DICE_ROLLER

typedef struct Dice {
    int sides;
    int value;
} Dice;

void roll_dice(Dice* dice) {
    dice->value = rand() % dice->sides + 1;
}

void print_dice(const Dice* dice) {
    printf("Dice with %d sides rolled a %d\n", dice->sides, dice->value);
}

int main() {
    srand(time(NULL));

    int num_dice;
    printf("Hey there, Rollercoaster!\n");
    printf("How many dice do you want to roll? ");
    scanf("%d", &num_dice);

    Dice* dice_array = (Dice*)calloc(num_dice, sizeof(Dice));

    if (!dice_array) {
        printf("Sorry, we couldn't allocate memory for that many dice. Better luck next time!\n");
        return 1;
    }

    for (int i = 0; i < num_dice; i++) {
        printf("Enter the number of sides on die %d: ", i + 1);
        scanf("%d", &dice_array[i].sides);
    }

    printf("\nLet's roll those dice, %s!\n", (num_dice > 1) ? "wildcat" : "kitten");

    for (int i = 0; i < num_dice; i++) {
        roll_dice(&dice_array[i]);
        print_dice(&dice_array[i]);
    }

    free(dice_array);

    return 0;
}

#undef DICE_ROLLER