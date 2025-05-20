//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 100
#define MAX_SIDES 1000

struct dice {
    int num_dice;
    int num_sides;
    int *values;
};

void roll_dice(struct dice *d) {
    int i, j;
    for (i = 0; i < d->num_dice; i++) {
        d->values[i] = rand() % d->num_sides + 1;
    }
}

void print_dice(struct dice *d) {
    int i;
    printf("Rolling %d %d-sided dice...\n", d->num_dice, d->num_sides);
    for (i = 0; i < d->num_dice; i++) {
        printf("%d ", d->values[i]);
    }
    printf("\n");
}

int main() {
    int num_dice, num_sides;
    struct dice d;

    srand(time(NULL));

    printf("Enter the number of dice: ");
    scanf("%d", &num_dice);
    printf("Enter the number of sides: ");
    scanf("%d", &num_sides);

    d.num_dice = num_dice;
    d.num_sides = num_sides;
    d.values = malloc(d.num_dice * sizeof(int));

    roll_dice(&d);
    print_dice(&d);

    free(d.values);

    return 0;
}