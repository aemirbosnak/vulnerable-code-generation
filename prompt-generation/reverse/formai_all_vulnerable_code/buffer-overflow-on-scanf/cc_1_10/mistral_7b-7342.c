//MISTRAL-7B DATASET v1.0 Category: Dice Roller ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIDE 20
#define MIN_SIDE 1

void paranoid_srand() {
    unsigned char r[32];
    unsigned int i;

    if (time(NULL) == 0) {
        fprintf(stderr, "Error: Unable to get current time.\n");
        exit(EXIT_FAILURE);
    }

    if (rand_r(r) == RAND_MAX) {
        fprintf(stderr, "Error: Unable to generate random seed.\n");
        exit(EXIT_FAILURE);
    }

    srand((unsigned int)time(NULL) ^ (unsigned int)rand_r(r));
}

int paranoid_rand(int upper_bound) {
    int roll;

    if (upper_bound < MIN_SIDE || upper_bound > MAX_SIDE) {
        fprintf(stderr, "Error: Invalid upper bound for dice roll.\n");
        exit(EXIT_FAILURE);
    }

    roll = rand() % upper_bound + 1;

    if (roll < MIN_SIDE) {
        fprintf(stderr, "Error: Rolled a negative number.\n");
        exit(EXIT_FAILURE);
    }

    return roll;
}

void roll_dice(int num_dice, int sides_per_die) {
    int i, roll;

    if (num_dice <= 0 || sides_per_die <= 0) {
        fprintf(stderr, "Error: Invalid number of dice or sides.\n");
        exit(EXIT_FAILURE);
    }

    paranoid_srand();

    for (i = 0; i < num_dice; i++) {
        roll = paranoid_rand(sides_per_die);
        printf("Rolled a %d on dice %d.\n", roll, i + 1);
    }
}

int main() {
    int num_dice, sides_per_die;

    printf("Enter the number of dice: ");
    scanf("%d", &num_dice);

    printf("Enter the number of sides on each die: ");
    scanf("%d", &sides_per_die);

    roll_dice(num_dice, sides_per_die);

    return EXIT_SUCCESS;
}