//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 1000

typedef struct {
    int faces;
    int value;
} Die;

void init_dice(Die dice[], int num_dice) {
    for (int i = 0; i < num_dice; i++) {
        dice[i].faces = 6;
        dice[i].value = rand() % dice[i].faces + 1;
    }
}

void roll_dice(Die dice[], int num_dice) {
    srand(time(NULL));
    for (int i = 0; i < num_dice; i++) {
        dice[i].value = rand() % dice[i].faces + 1;
    }
}

void print_dice(Die dice[], int num_dice) {
    for (int i = 0; i < num_dice; i++) {
        printf("%d", dice[i].value);
    }
    printf("\n");
}

int main() {
    Die dice[MAX_DICE];
    int num_dice;

    printf("Enter the number of dice (up to %d): ", MAX_DICE);
    scanf("%d", &num_dice);

    init_dice(dice, num_dice);
    roll_dice(dice, num_dice);

    printf("Initial roll:\n");
    print_dice(dice, num_dice);

    roll_dice(dice, num_dice);

    printf("Second roll:\n");
    print_dice(dice, num_dice);

    return 0;
}