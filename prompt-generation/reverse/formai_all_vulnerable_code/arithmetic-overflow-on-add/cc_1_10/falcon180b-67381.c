//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 100
#define MAX_SIDES 1000

typedef struct {
    int num_dice;
    int num_sides;
    int *rolls;
} DiceRoller;

void init_roller(DiceRoller *roller, int num_dice, int num_sides) {
    roller->num_dice = num_dice;
    roller->num_sides = num_sides;
    roller->rolls = malloc(num_dice * sizeof(int));
}

void free_roller(DiceRoller *roller) {
    free(roller->rolls);
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
    int num_dice, num_sides;
    printf("Enter the number of dice: ");
    scanf("%d", &num_dice);
    printf("Enter the number of sides per dice: ");
    scanf("%d", &num_sides);

    if (num_dice > MAX_DICE || num_sides > MAX_SIDES) {
        printf("Invalid input. Maximum number of dice is %d and maximum number of sides is %d.\n", MAX_DICE, MAX_SIDES);
        return 1;
    }

    DiceRoller roller;
    init_roller(&roller, num_dice, num_sides);

    printf("Rolling the dice...\n");
    roll_dice(&roller);

    printf("The rolls are:\n");
    print_rolls(&roller);

    free_roller(&roller);

    return 0;
}