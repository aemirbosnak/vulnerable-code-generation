//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 100
#define MAX_SIDES 100

typedef struct {
    int num_dice;
    int num_sides;
} RollParams;

void roll_dice(RollParams params, int *results) {
    srand(time(NULL));
    for (int i = 0; i < params.num_dice; i++) {
        results[i] = rand() % params.num_sides + 1;
    }
}

void print_results(int num_dice, int num_sides, int *results) {
    printf("Rolling %d %d-sided dice...\n", num_dice, num_sides);
    for (int i = 0; i < num_dice; i++) {
        printf("Dice %d rolled a %d.\n", i + 1, results[i]);
    }
}

int main() {
    RollParams params;
    int num_dice = 0;
    int num_sides = 0;
    int results[MAX_DICE];

    // Get input from user
    printf("Enter number of dice to roll: ");
    scanf("%d", &num_dice);

    printf("Enter number of sides for each dice: ");
    scanf("%d", &num_sides);

    // Set parameters
    params.num_dice = num_dice;
    params.num_sides = num_sides;

    // Roll dice
    roll_dice(params, results);

    // Print results
    print_results(num_dice, num_sides, results);

    return 0;
}