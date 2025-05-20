//Code Llama-13B DATASET v1.0 Category: Dice Roller ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_DIE_SIDES 100

typedef struct {
    int num_dice;
    int num_sides;
    int total;
    int* rolls;
} DiceRoller;

DiceRoller* init_dice_roller(int num_dice, int num_sides) {
    DiceRoller* roller = malloc(sizeof(DiceRoller));
    roller->num_dice = num_dice;
    roller->num_sides = num_sides;
    roller->total = 0;
    roller->rolls = malloc(num_dice * sizeof(int));
    return roller;
}

void roll_dice(DiceRoller* roller) {
    for (int i = 0; i < roller->num_dice; i++) {
        roller->rolls[i] = rand() % roller->num_sides + 1;
        roller->total += roller->rolls[i];
    }
}

void print_dice_rolls(DiceRoller* roller) {
    printf("You rolled: ");
    for (int i = 0; i < roller->num_dice; i++) {
        printf("%d ", roller->rolls[i]);
    }
    printf("\n");
}

void print_total(DiceRoller* roller) {
    printf("Total: %d\n", roller->total);
}

int main() {
    srand(time(NULL));
    DiceRoller* roller = init_dice_roller(3, 6);
    roll_dice(roller);
    print_dice_rolls(roller);
    print_total(roller);
    free(roller->rolls);
    free(roller);
    return 0;
}