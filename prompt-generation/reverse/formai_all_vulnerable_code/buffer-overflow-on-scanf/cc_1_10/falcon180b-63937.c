//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_DICE 6
#define NUM_SIDES 6

/* Function prototypes */
void roll_dice(int dice[NUM_DICE], int num_dice);
int get_random_number(int min, int max);
void print_dice(int dice[NUM_DICE], int num_dice);

int main() {
    int dice[NUM_DICE];
    int num_dice;
    int total = 0;

    printf("Enter the number of dice to roll (1-6): ");
    scanf("%d", &num_dice);

    if (num_dice < 1 || num_dice > NUM_DICE) {
        printf("Invalid number of dice! Exiting...\n");
        return 1;
    }

    printf("Rolling %d dice...\n", num_dice);
    roll_dice(dice, num_dice);

    printf("Dice rolled:\n");
    print_dice(dice, num_dice);

    total = get_sum(dice, num_dice);
    printf("Total: %d\n", total);

    return 0;
}

void roll_dice(int dice[NUM_DICE], int num_dice) {
    int i;
    srand(time(NULL));

    for (i = 0; i < num_dice; i++) {
        dice[i] = get_random_number(1, NUM_SIDES);
    }
}

int get_random_number(int min, int max) {
    int rand_num;
    rand_num = rand() % (max - min + 1) + min;
    return rand_num;
}

void print_dice(int dice[NUM_DICE], int num_dice) {
    int i;

    for (i = 0; i < num_dice; i++) {
        printf("%d ", dice[i]);
    }
    printf("\n");
}

int get_sum(int dice[NUM_DICE], int num_dice) {
    int i;
    int sum = 0;

    for (i = 0; i < num_dice; i++) {
        sum += dice[i];
    }

    return sum;
}