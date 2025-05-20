//MISTRAL-7B DATASET v1.0 Category: Dice Roller ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIDE_COUNT 6
#define MAX_ROLLS 10

void print_dice_roll(int *dice, int rolls) {
    int i, j;

    printf("\nRolls: %d\n", rolls);
    printf("-----------\n");
    for (i = 0; i < rolls; i++) {
        printf("Roll %d: ", i + 1);
        for (j = 0; j < SIDE_COUNT; j++)
            printf(" %d", dice[i] + j + 1);
        printf("\n");
    }
    printf("-----------\n");
}

void roll_dice(int *dice, int rolls) {
    int i;

    srand(time(NULL));
    for (i = 0; i < rolls; i++)
        dice[i] = (rand() % SIDE_COUNT) + 1;
}

int main() {
    int rolls, i;
    int *dice;

    printf("Welcome, brave adventurer, to the Sage's Fortune, where we roll the dice to determine your fate!\n");
    printf("How many rolls would you like to make? (max %d)\n", MAX_ROLLS);
    scanf("%d", &rolls);

    if (rolls > MAX_ROLLS) {
        printf("You cannot roll more than %d dice at once! Try again.\n", MAX_ROLLS);
        rolls = MAX_ROLLS;
    }

    dice = (int *)calloc(rolls, sizeof(int));
    if (dice == NULL) {
        printf("Could not allocate memory for dice rolls!\n");
        return -1;
    }

    roll_dice(dice, rolls);
    print_dice_roll(dice, rolls);

    free(dice);
    return 0;
}