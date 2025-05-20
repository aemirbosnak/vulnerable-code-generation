//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIDES 100

int main() {
    int num_sides;
    int num_rolls;
    int *sides;
    int *rolls;
    int i;
    int total = 0;
    int max_roll = 0;
    int min_roll = MAX_SIDES;

    srand(time(NULL));

    printf("Welcome to the Brave C Dice Roller!\n");
    printf("How many sides does your dice have? ");
    scanf("%d", &num_sides);

    if (num_sides > MAX_SIDES || num_sides <= 0) {
        printf("Invalid number of sides.\n");
        return 1;
    }

    sides = (int *)malloc(num_sides * sizeof(int));
    rolls = (int *)malloc(num_rolls * sizeof(int));

    printf("How many times do you want to roll the dice? ");
    scanf("%d", &num_rolls);

    if (num_rolls <= 0) {
        printf("Invalid number of rolls.\n");
        free(sides);
        free(rolls);
        return 1;
    }

    printf("Enter the values for each side (separated by spaces): ");
    for (i = 0; i < num_sides; i++) {
        scanf("%d", &sides[i]);
        if (sides[i] < 1 || sides[i] > num_sides) {
            printf("Invalid value for side %d.\n", i + 1);
            free(sides);
            free(rolls);
            return 1;
        }
    }

    for (i = 0; i < num_rolls; i++) {
        rolls[i] = rand() % num_sides + 1;
        total += rolls[i];
        if (rolls[i] > max_roll) {
            max_roll = rolls[i];
        }
        if (rolls[i] < min_roll) {
            min_roll = rolls[i];
        }
    }

    printf("You rolled the dice %d times.\n", num_rolls);
    printf("The total of all rolls is %d.\n", total);
    printf("The maximum roll was %d.\n", max_roll);
    printf("The minimum roll was %d.\n", min_roll);

    free(sides);
    free(rolls);

    return 0;
}