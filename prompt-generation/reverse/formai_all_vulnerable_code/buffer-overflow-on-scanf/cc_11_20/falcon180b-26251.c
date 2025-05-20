//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIDES 6
#define NUM_DICE 2

int main() {
    int dice[NUM_DICE][SIDES] = {{0}};
    int i, j, k, roll_count = 0;
    int total_rolls, total_sum = 0;
    char play_again;

    srand(time(0));

    for (i = 0; i < NUM_DICE; i++) {
        for (j = 0; j < SIDES; j++) {
            dice[i][j] = rand() % SIDES + 1;
        }
    }

    printf("Welcome to the Happy Dice Roller Game!\n");
    printf("You have %d dice with %d sides each.\n", NUM_DICE, SIDES);
    printf("Press enter to roll the dice...\n");

    while (1) {
        system("clear");
        for (i = 0; i < NUM_DICE; i++) {
            for (j = 0; j < SIDES; j++) {
                printf("%d ", dice[i][j]);
            }
            printf("\n");
        }
        total_sum = 0;
        for (i = 0; i < NUM_DICE; i++) {
            for (j = 0; j < SIDES; j++) {
                total_sum += dice[i][j];
            }
        }
        printf("\nTotal sum: %d\n", total_sum);
        printf("Do you want to roll again? (y/n): ");
        scanf("%c", &play_again);
        if (play_again == 'n') {
            break;
        }
        roll_count++;
        for (i = 0; i < NUM_DICE; i++) {
            for (j = 0; j < SIDES; j++) {
                dice[i][j] = rand() % SIDES + 1;
            }
        }
    }

    printf("\nYou rolled the dice %d times!\n", roll_count);

    return 0;
}