//MISTRAL-7B DATASET v1.0 Category: Dice Roller ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_SIDE 4
#define MAX_SIDE 20
#define NUM_DICE 5

typedef struct {
    int sides;
    int rolled[NUM_DICE];
} Dice;

void roll_dice(Dice *dice) {
    int i;
    for (i = 0; i < NUM_DICE; i++) {
        dice->rolled[i] = rand() % (dice->sides + 1);
    }
}

void print_dice(const Dice *dice) {
    int i;
    printf("Rolled:\n");
    for (i = 0; i < NUM_DICE; i++) {
        printf("Dice %d: %d\n", i + 1, dice->rolled[i]);
    }
}

void set_dice_sides(Dice *dice, int sides) {
    if (sides < MIN_SIDE || sides > MAX_SIDE) {
        printf("Error: Invalid number of sides.\n");
        return;
    }
    dice->sides = sides;
}

int main() {
    srand(time(NULL));
    Dice my_dice;

    printf("Welcome to the Dice Roller!\n");
    set_dice_sides(&my_dice, 6); // Set the number of sides for the dice

    while (1) {
        roll_dice(&my_dice);
        print_dice(&my_dice);
        printf("Do you want to roll again? (y/n): ");
        char choice;
        scanf("%c", &choice);
        if (choice == 'n') {
            break;
        }
    }

    return 0;
}