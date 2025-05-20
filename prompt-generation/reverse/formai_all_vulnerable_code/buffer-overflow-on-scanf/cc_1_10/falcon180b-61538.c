//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 100
#define MAX_SIDES 100

typedef struct {
    int num_dice;
    int num_sides;
    int *dice;
} Roll;

void init_roll(Roll *roll) {
    roll->num_dice = 0;
    roll->num_sides = 0;
    roll->dice = NULL;
}

void free_roll(Roll *roll) {
    if (roll->dice!= NULL) {
        free(roll->dice);
        roll->dice = NULL;
    }
}

void roll_dice(Roll *roll) {
    if (roll->num_dice == 0 || roll->num_sides == 0) {
        printf("Invalid number of dice or sides.\n");
        return;
    }

    roll->dice = malloc(roll->num_dice * sizeof(int));
    if (roll->dice == NULL) {
        printf("Memory error.\n");
        return;
    }

    srand(time(NULL));
    for (int i = 0; i < roll->num_dice; i++) {
        roll->dice[i] = rand() % roll->num_sides + 1;
    }
}

int main(int argc, char *argv[]) {
    Roll roll;
    init_roll(&roll);

    printf("Enter the number of dice: ");
    scanf("%d", &roll.num_dice);

    printf("Enter the number of sides: ");
    scanf("%d", &roll.num_sides);

    roll_dice(&roll);

    printf("Rolling %d %d-sided dice...\n", roll.num_dice, roll.num_sides);
    for (int i = 0; i < roll.num_dice; i++) {
        printf("%d ", roll.dice[i]);
    }
    printf("\n");

    free_roll(&roll);

    return 0;
}