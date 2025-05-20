//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_DICE 100
#define MAX_SIDES 1000

int main() {
    int num_dice, num_sides, total_sides, i, j, k;
    int *sides;
    int **dice;
    char play_again = 'y';

    srand(time(NULL));

    printf("Welcome to the Dice Roller!\n\n");

    while (play_again == 'y') {
        printf("How many dice would you like to roll? ");
        scanf("%d", &num_dice);

        printf("How many sides should each die have? ");
        scanf("%d", &num_sides);

        total_sides = num_dice * num_sides;

        sides = (int *) malloc(total_sides * sizeof(int));
        dice = (int **) malloc(num_dice * sizeof(int *));

        for (i = 0; i < num_dice; i++) {
            dice[i] = (int *) malloc(num_sides * sizeof(int));
        }

        printf("Enter the values for the sides of the dice (separated by spaces): ");
        for (i = 0; i < total_sides; i++) {
            scanf("%d", &sides[i]);
        }

        for (i = 0; i < num_dice; i++) {
            for (j = 0; j < num_sides; j++) {
                dice[i][j] = sides[i * num_sides + j];
            }
        }

        printf("Rolling the dice...\n");

        for (i = 0; i < num_dice; i++) {
            for (j = 0; j < num_sides; j++) {
                k = rand() % num_sides;
                dice[i][j] = sides[k];
            }
        }

        printf("The results are:\n");

        for (i = 0; i < num_dice; i++) {
            for (j = 0; j < num_sides; j++) {
                printf("%d ", dice[i][j]);
            }
            printf("\n");
        }

        printf("Play again? (y/n) ");
        scanf(" %c", &play_again);

        for (i = 0; i < num_dice; i++) {
            free(dice[i]);
        }
        free(dice);
        free(sides);
    }

    return 0;
}