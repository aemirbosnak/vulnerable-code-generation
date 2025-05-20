//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIDES 1000
#define MAX_DICE 100

struct dice {
    int num_sides;
    int *sides;
};

int roll_dice(struct dice *dice) {
    return dice->sides[rand() % dice->num_sides];
}

int main() {
    srand(time(NULL));

    int num_dice, max_sides;
    printf("Enter the number of dice: ");
    scanf("%d", &num_dice);

    struct dice *dice_array = malloc(num_dice * sizeof(struct dice));

    for (int i = 0; i < num_dice; i++) {
        printf("Enter the number of sides for dice %d: ", i+1);
        scanf("%d", &dice_array[i].num_sides);

        if (dice_array[i].num_sides > MAX_SIDES) {
            printf("Error: number of sides is too large.\n");
            exit(1);
        }

        dice_array[i].sides = malloc(dice_array[i].num_sides * sizeof(int));

        for (int j = 0; j < dice_array[i].num_sides; j++) {
            printf("Enter side %d: ", j+1);
            scanf("%d", &dice_array[i].sides[j]);
        }
    }

    printf("Rolling dice...\n");

    for (int i = 0; i < num_dice; i++) {
        printf("Dice %d rolled %d.\n", i+1, roll_dice(dice_array+i));
    }

    return 0;
}