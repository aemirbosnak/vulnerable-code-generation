//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIDES 1000
#define MIN_SIDES 1

int main() {
    int num_dice, sides_per_die, i, j, sum = 0;
    char response[3];

    printf("Welcome to the Sherlock Holmes Dice Roller!\n");
    printf("How many dice would you like to roll? ");
    scanf("%d", &num_dice);

    while (num_dice < MIN_SIDES || num_dice > MAX_SIDES) {
        printf("Invalid number of dice. Please enter a number between %d and %d: ", MIN_SIDES, MAX_SIDES);
        scanf("%d", &num_dice);
    }

    for (i = 0; i < num_dice; i++) {
        printf("How many sides on die %d? ", i+1);
        scanf("%d", &sides_per_die);

        while (sides_per_die < MIN_SIDES || sides_per_die > MAX_SIDES) {
            printf("Invalid number of sides. Please enter a number between %d and %d: ", MIN_SIDES, MAX_SIDES);
            scanf("%d", &sides_per_die);
        }

        sum += sides_per_die;
    }

    srand(time(NULL));

    for (i = 0; i < num_dice; i++) {
        printf("Rolling die %d...\n", i+1);
        for (j = 0; j < sides_per_die; j++) {
            printf(".");
            fflush(stdout);
            usleep(100000); // Sleep for 0.1 seconds
        }
        printf("\n");

        int roll = rand() % sides_per_die + 1;
        printf("Die %d rolled a %d!\n", i+1, roll);

        if (i == 0) {
            printf("Your total roll is: %d\n", roll);
        } else {
            printf("Adding %d to your total roll...\n", roll);
            sum += roll;
        }
    }

    printf("\nYour final roll is: %d\n", sum);

    return 0;
}