//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 100
#define MAX_SIDES 1000

struct die {
    int num_sides;
    int value;
};

struct roll {
    int num_dice;
    struct die dice[MAX_DICE];
};

void init_die(struct die *d, int num_sides) {
    d->num_sides = num_sides;
    d->value = rand() % num_sides + 1;
}

void init_roll(struct roll *r, int num_dice, int num_sides) {
    r->num_dice = num_dice;
    for (int i = 0; i < num_dice; i++) {
        init_die(&r->dice[i], num_sides);
    }
}

void roll_dice(struct roll *r) {
    for (int i = 0; i < r->num_dice; i++) {
        printf("Dice %d: %d\n", i+1, r->dice[i].value);
    }
}

int main() {
    srand(time(NULL));

    int num_dice, num_sides;

    printf("Enter the number of dice: ");
    scanf("%d", &num_dice);

    printf("Enter the number of sides on each die: ");
    scanf("%d", &num_sides);

    struct roll r;
    init_roll(&r, num_dice, num_sides);

    roll_dice(&r);

    return 0;
}