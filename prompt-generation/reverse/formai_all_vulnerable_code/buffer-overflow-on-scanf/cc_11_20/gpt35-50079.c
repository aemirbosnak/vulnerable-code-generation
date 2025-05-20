//FormAI DATASET v1.0 Category: Dice Roller ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int num_dice, num_sides, total_rolls;
    int i, j, current_roll, total;
    char again;

    srand(time(NULL));

    do {
        printf("Welcome to the C Dice Roller!\n");
        printf("How many dice would you like to roll? (1-10): ");
        scanf("%d", &num_dice);

        if (num_dice < 1 || num_dice > 10) {
            printf("Invalid number of dice, please choose between 1 and 10.\n");
            continue;
        }

        printf("How many sides would you like on each die? (4-20): ");
        scanf("%d", &num_sides);

        if (num_sides < 4 || num_sides > 20) {
            printf("Invalid number of sides, please choose between 4 and 20.\n");
            continue;
        }

        printf("How many times would you like to roll? (1-1000): ");
        scanf("%d", &total_rolls);

        if (total_rolls < 1 || total_rolls > 1000) {
            printf("Invalid number of rolls, please choose between 1 and 1000.\n");
            continue;
        }

        total = 0;

        printf("\n");

        for (i = 0; i < total_rolls; i++) {
            current_roll = 0;

            for (j = 0; j < num_dice; j++) {
                current_roll += (rand() % num_sides) + 1;
            }

            printf("Roll %d: %d\n", i + 1, current_roll);
            total += current_roll;
        }

        printf("\nTotal: %d\n", total);

        printf("\nWould you like to roll again? (Y/N): ");
        scanf(" %c", &again);
    } while (again == 'y' || again == 'Y');

    return 0;
}