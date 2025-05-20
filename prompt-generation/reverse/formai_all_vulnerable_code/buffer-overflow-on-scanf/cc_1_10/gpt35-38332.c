//FormAI DATASET v1.0 Category: Dice Roller ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num_dice, num_sides, i, j, sum;
    char play_again;

    do {
        printf("Welcome to the Mind-Bending Dice Roller!\n");

        printf("How many dice do you want to roll? (1-10) ");
        scanf("%d", &num_dice);
        while (num_dice < 1 || num_dice > 10) {
            printf("Invalid input. Please enter a number between 1 and 10: ");
            scanf("%d", &num_dice);
        }

        printf("How many sides should each die have? (2-20) ");
        scanf("%d", &num_sides);
        while (num_sides < 2 || num_sides > 20) {
            printf("Invalid input. Please enter a number between 2 and 20: ");
            scanf("%d", &num_sides);
        }

        srand(time(NULL));

        printf("\nRolling %d D%d...\n", num_dice, num_sides);

        sum = 0;
        for (i = 0; i < num_dice; i++) {
            int roll = rand() % num_sides + 1;
            printf("Dice %d: %d\n", i+1, roll);
            sum += roll;
        }

        if (num_dice > 1) {
            printf("Total: %d\n", sum);
        }

        printf("\nDo you want to roll again? (y/n) ");
        scanf(" %c", &play_again);
        while (play_again != 'y' && play_again != 'n') {
            printf("Invalid input. Please enter 'y' or 'n': ");
            scanf(" %c", &play_again);
        }

        printf("\n");

    } while (play_again == 'y');

    printf("Thanks for playing the Mind-Bending Dice Roller. Goodbye!\n");

    return 0;
}