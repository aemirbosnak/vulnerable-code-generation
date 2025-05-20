//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 100
#define MAX_SIDES 1000

typedef struct {
    int num_dice;
    int num_sides;
    int sum;
} RollResult;

void roll_dice(int num_dice, int num_sides, RollResult *result) {
    int i, roll;

    for (i = 0; i < num_dice; i++) {
        roll = rand() % num_sides + 1;
        result->sum += roll;
    }

    result->num_dice = num_dice;
    result->num_sides = num_sides;
}

void print_result(RollResult result) {
    printf("You rolled %d dice with %d sides.\n", result.num_dice, result.num_sides);
    printf("The total is %d.\n", result.sum);
}

int main() {
    int num_dice, num_sides;
    RollResult result;

    srand(time(NULL));

    printf("Enter the number of dice: ");
    scanf("%d", &num_dice);

    printf("Enter the number of sides on each die: ");
    scanf("%d", &num_sides);

    if (num_dice <= 0 || num_sides <= 0 || num_dice > MAX_DICE || num_sides > MAX_SIDES) {
        printf("Invalid input.\n");
        return 1;
    }

    roll_dice(num_dice, num_sides, &result);
    print_result(result);

    return 0;
}