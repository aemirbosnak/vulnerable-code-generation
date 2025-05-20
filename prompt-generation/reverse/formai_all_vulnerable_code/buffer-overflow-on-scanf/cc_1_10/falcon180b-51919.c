//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX 6
#define MIN 1
#define SIDES 6

int roll_dice(int num_dice, int sides) {
    int i = 0;
    int sum = 0;
    int dice_result[num_dice];

    srand(time(NULL));

    for (i = 0; i < num_dice; i++) {
        dice_result[i] = (rand() % sides) + 1;
        sum += dice_result[i];
    }

    return sum;
}

int main() {
    int num_dice;
    int sides;
    int roll_result;
    int total_rolls = 0;
    int max_result = 0;
    int min_result = 999;
    int avg_result = 0;

    printf("Welcome to the Dice Roller!\n");

    do {
        printf("Enter the number of dice you want to roll (between %d and %d): ", MIN, MAX);
        scanf("%d", &num_dice);
    } while (num_dice < MIN || num_dice > MAX);

    do {
        printf("Enter the number of sides on each dice (between %d and %d): ", MIN, MAX);
        scanf("%d", &sides);
    } while (sides < MIN || sides > MAX);

    while (1) {
        roll_result = roll_dice(num_dice, sides);
        printf("You rolled %d with %d dice of %d sides.\n", roll_result, num_dice, sides);

        if (roll_result > max_result) {
            max_result = roll_result;
        }

        if (roll_result < min_result) {
            min_result = roll_result;
        }

        total_rolls++;
        avg_result = total_rolls / roll_result;

        printf("Max result so far: %d\n", max_result);
        printf("Min result so far: %d\n", min_result);
        printf("Average result so far: %.2f\n", avg_result);

        printf("Roll again? (y/n): ");
        char answer;
        scanf(" %c", &answer);

        if (answer!= 'y') {
            break;
        }
    }

    return 0;
}