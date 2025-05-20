//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIDES 1000
#define MAX_DICE 1000

typedef struct {
    int num_sides;
    char *name;
} dice_t;

dice_t dice[MAX_DICE];

void roll_dice(int num_rolls, int num_dice, int num_sides) {
    int i, j, k, total = 0;

    for (i = 0; i < num_rolls; i++) {
        for (j = 0; j < num_dice; j++) {
            k = rand() % num_sides + 1;
            printf("%s: %d\n", dice[j].name, k);
            total += k;
        }
        printf("Total: %d\n\n", total);
        total = 0;
    }
}

int main() {
    int i, num_dice, num_sides;

    srand(time(NULL));

    for (i = 0; i < MAX_DICE; i++) {
        printf("Enter name of dice #%d: ", i + 1);
        scanf("%s", dice[i].name);
        printf("Enter number of sides for %s: ", dice[i].name);
        scanf("%d", &dice[i].num_sides);
    }

    printf("Enter number of dice to roll: ");
    scanf("%d", &num_dice);

    printf("Enter number of sides for each dice (or 0 to choose randomly): ");
    scanf("%d", &num_sides);

    if (num_sides == 0) {
        for (i = 0; i < num_dice; i++) {
            num_sides = dice[i % MAX_DICE].num_sides;
            roll_dice(1, 1, num_sides);
        }
    } else {
        roll_dice(1, num_dice, num_sides);
    }

    return 0;
}