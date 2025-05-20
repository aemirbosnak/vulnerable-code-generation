//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_DICE 6
#define SIDES 6

int roll_dice(int num_dice, int sides) {
    int i;
    int total = 0;
    for (i = 0; i < num_dice; i++) {
        int roll = rand() % sides + 1;
        printf("Rolled a %d on dice %d\n", roll, i+1);
        total += roll;
    }
    return total;
}

int main() {
    int num_rolls;
    int total_rolls = 0;
    int total_sum = 0;
    int max_sum = 0;
    int max_rolls = 0;

    srand(time(NULL));

    printf("How many times do you want to roll the dice? ");
    scanf("%d", &num_rolls);

    while (num_rolls > 0) {
        int current_rolls = num_rolls > 10? 10 : num_rolls;
        int current_sum = roll_dice(NUM_DICE, SIDES);
        total_rolls += current_rolls;
        total_sum += current_sum;

        if (current_sum > max_sum) {
            max_sum = current_sum;
            max_rolls = current_rolls;
        }

        num_rolls -= current_rolls;
    }

    printf("Total rolls: %d\n", total_rolls);
    printf("Average roll: %.2f\n", (float)total_sum / total_rolls);
    printf("Max roll: %d (in %d rolls)\n", max_sum, max_rolls);

    return 0;
}