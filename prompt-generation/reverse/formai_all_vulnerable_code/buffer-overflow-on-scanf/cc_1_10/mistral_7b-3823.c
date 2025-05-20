//MISTRAL-7B DATASET v1.0 Category: Dice Roller ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_DICE 1
#define MAX_DICE 100
#define MIN_SIDE 2
#define MAX_SIDE 100

void roll_dice(int num_dice, int num_sides, int dice_results[]) {
    int i;
    for (i = 0; i < num_dice; i++) {
        dice_results[i] = rand() % num_sides + 1;
    }
}

int main() {
    int num_dice, num_sides, dice_results[100], total_sum = 0;

    srand(time(NULL)); // Initialize random seed

    printf("\n*****************************************************\n");
    printf("*                                                   *\n");
    printf("*     Welcome to the Dice Roller Extravaganza!       *\n");
    printf("*                                                   *\n");
    printf("*****************************************************\n");
    printf("\nHow many dice do you want to roll? (Between %d and %d): ", MIN_DICE, MAX_DICE);
    scanf("%d", &num_dice);

    if (num_dice < MIN_DICE || num_dice > MAX_DICE) {
        printf("\nInvalid number of dice! Please enter a number between %d and %d.\n", MIN_DICE, MAX_DICE);
        return 1;
    }

    printf("\nHow many sides does each die have? (Between %d and %d): ", MIN_SIDE, MAX_SIDE);
    scanf("%d", &num_sides);

    if (num_sides < MIN_SIDE || num_sides > MAX_SIDE) {
        printf("\nInvalid number of sides! Please enter a number between %d and %d.\n", MIN_SIDE, MAX_SIDE);
        return 1;
    }

    int dice_rolls[num_dice];

    printf("\nRolling %d %d-sided dice...\n", num_dice, num_sides);

    roll_dice(num_dice, num_sides, dice_rolls);

    printf("\nYour dice rolls:\n");
    for (int i = 0; i < num_dice; i++) {
        printf("Dice %d rolled a %d!\n", i + 1, dice_rolls[i]);
        total_sum += dice_rolls[i];
    }

    printf("\nThe total sum of all dice rolls is %d!\n", total_sum);

    printf("\n*****************************************************\n");
    printf("*                                                   *\n");
    printf("*    Thank you for using the Dice Roller Extravaganza! *\n");
    printf("*                                                   *\n");
    printf("*****************************************************\n");

    return 0;
}