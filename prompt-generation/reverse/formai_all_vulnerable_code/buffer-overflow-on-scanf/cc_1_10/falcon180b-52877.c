//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 1000
#define MIN_VALUE 1
#define MAX_VALUE 6

enum {
    ROLL_SUCCESS = 0,
    ROLL_FAILURE_INVALID_DICE_COUNT = 1,
    ROLL_FAILURE_INVALID_VALUE_RANGE = 2
};

int roll_dice(int count, int min_value, int max_value) {
    if (count <= 0 || count > MAX_DICE) {
        return ROLL_FAILURE_INVALID_DICE_COUNT;
    }
    if (min_value < MIN_VALUE || max_value > MAX_VALUE || min_value > max_value) {
        return ROLL_FAILURE_INVALID_VALUE_RANGE;
    }
    int result = rand() % (max_value - min_value + 1) + min_value;
    for (int i = 1; i < count; ++i) {
        int temp = rand() % (max_value - min_value + 1) + min_value;
        if (temp == result) {
            --i;
        } else {
            result = temp;
        }
    }
    return result;
}

int main() {
    int dice_count, min_value, max_value;
    printf("Enter the number of dice to roll: ");
    if (scanf("%d", &dice_count)!= 1 || dice_count <= 0) {
        printf("Invalid dice count.\n");
        return 1;
    }
    printf("Enter the minimum value: ");
    if (scanf("%d", &min_value)!= 1 || min_value < MIN_VALUE) {
        printf("Invalid minimum value.\n");
        return 1;
    }
    printf("Enter the maximum value: ");
    if (scanf("%d", &max_value)!= 1 || max_value > MAX_VALUE || min_value > max_value) {
        printf("Invalid maximum value.\n");
        return 1;
    }
    int result = roll_dice(dice_count, min_value, max_value);
    if (result == ROLL_FAILURE_INVALID_DICE_COUNT) {
        printf("Invalid dice count.\n");
    } else if (result == ROLL_FAILURE_INVALID_VALUE_RANGE) {
        printf("Invalid value range.\n");
    } else {
        printf("You rolled %d on %d dice.\n", result, dice_count);
    }
    return 0;
}