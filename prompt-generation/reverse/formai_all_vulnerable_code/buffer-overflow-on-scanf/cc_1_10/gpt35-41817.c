//FormAI DATASET v1.0 Category: Dice Roller ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function to simulate rolling of dice
int roll_dice(int num_sides)
{
    return rand() % num_sides + 1;
}

int main()
{
    int num_dice, num_sides, i, roll_sum;
    char choice;

    //seed random number generator with current time
    srand(time(NULL));

    printf("Welcome to the Dice Roller Program!\n");

    do {
        printf("\nEnter the number of dice and number of sides:\n");
        scanf("%d %d", &num_dice, &num_sides);

        //validate input
        if (num_dice <= 0 || num_sides <= 0) {
            printf("Invalid input! Number of dice and number of sides must be greater than zero.\n");
            continue;
        }

        printf("\nLet's roll the dice!\n\n");
        roll_sum = 0;

        for (i = 1; i <= num_dice; i++) {
            int roll = roll_dice(num_sides);
            printf("Die %d: %d\n", i, roll);
            roll_sum += roll;
        }

        printf("\nTotal roll: %d\n", roll_sum);

        //ask if user wants to roll again
        printf("\nDo you want to roll again? (y/n)\n");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("\nThanks for rolling with us. Come again soon!\n");

    return 0;
}