//FormAI DATASET v1.0 Category: Dice Roller ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(int num_dice, int sides);

int main(void)
{
    int num_dice, sides, roll;
    char response;

    srand((unsigned) time(NULL));  /* seed random number generator */

    printf("Welcome to the Dice Roller Game!\n\n");

    do {
        printf("How many dice would you like to roll? (up to 3): ");
        scanf("%d", &num_dice);

        printf("How many sides should the dice have? (4, 6, 8, 10 or 12): ");
        scanf("%d", &sides);

        if (num_dice < 1 || num_dice > 3) {
            printf("Sorry, you can only roll up to 3 dice.\n");
            continue;
        }

        if (sides != 4 && sides != 6 && sides != 8 && sides != 10 && sides != 12) {
            printf("Sorry, you can only have dice with 4, 6, 8, 10 or 12 sides.\n");
            continue;
        }

        roll = roll_dice(num_dice, sides);

        printf("\nYou rolled a total of %d.\n\n", roll);

        printf("Would you like to roll again? (Y/N) ");
        scanf(" %c", &response);  /* leave space before %c to consume whitespace */
    } while (response == 'y' || response == 'Y');

    printf("\nThanks for playing! Goodbye.\n");

    return 0;
}

/*
 * roll_dice - simulate the rolling of a specified number of dice, where
 * each die has a specified number of sides. Returns the sum of the rolls.
 */
int roll_dice(int num_dice, int sides)
{
    int i, roll, sum = 0;

    for (i = 0; i < num_dice; i++) {
        roll = rand() % sides + 1;
        printf("Dice %d: %d\n", i + 1, roll);
        sum += roll;
    }

    return sum;
}