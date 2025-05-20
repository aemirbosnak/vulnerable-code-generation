//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 100
#define MAX_SIDES 10000

typedef struct {
    int num_dice;
    int num_sides;
    int *rolls;
} DiceRoller;

void init_dice_roller(DiceRoller *roller) {
    roller->num_dice = 0;
    roller->num_sides = 0;
    roller->rolls = NULL;
}

void add_dice(DiceRoller *roller, int num_dice, int num_sides) {
    roller->num_dice += num_dice;
    roller->num_sides = num_sides;
    roller->rolls = realloc(roller->rolls, roller->num_dice * sizeof(int));
}

void roll_dice(DiceRoller *roller) {
    srand(time(NULL));
    for (int i = 0; i < roller->num_dice; i++) {
        roller->rolls[i] = rand() % roller->num_sides + 1;
    }
}

void print_rolls(DiceRoller *roller) {
    for (int i = 0; i < roller->num_dice; i++) {
        printf("%d ", roller->rolls[i]);
    }
    printf("\n");
}

int main() {
    DiceRoller roller;
    init_dice_roller(&roller);

    int choice;
    do {
        printf("Enter number of dice (0 to quit): ");
        scanf("%d", &choice);

        if (choice > 0) {
            add_dice(&roller, choice, 6);
        } else if (choice == 0) {
            break;
        } else {
            printf("Invalid input, please try again.\n");
        }

        printf("Enter number of sides per die (1 to %d): ", MAX_SIDES);
        scanf("%d", &choice);

        if (choice > 0 && choice <= MAX_SIDES) {
            roller.num_sides = choice;
        } else {
            printf("Invalid input, please try again.\n");
        }

    } while (1);

    roll_dice(&roller);
    print_rolls(&roller);

    return 0;
}