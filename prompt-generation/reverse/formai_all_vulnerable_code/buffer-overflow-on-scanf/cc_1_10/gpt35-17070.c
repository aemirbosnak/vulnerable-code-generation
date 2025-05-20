//FormAI DATASET v1.0 Category: Dice Roller ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// number of dice
#define N_DICE 2

// number of sides on each die
#define N_SIDES 6

// maximum number of rolls per turn
#define MAX_ROLLS 3

// get random number between 1 and N_SIDES inclusive
int roll_die() {
    return rand() % N_SIDES + 1;
}

// prompt for number of dice to roll
int prompt_n_dice() {
    int n_dice;

    printf("Enter number of dice to roll (%d-%d): ", 1, N_DICE);
    scanf("%d", &n_dice);

    // ensure valid number of dice
    if (n_dice < 1 || n_dice > N_DICE) {
        printf("Invalid number of dice!\n");
        exit(1);
    }

    return n_dice;
}

// prompt for number of rolls
int prompt_n_rolls() {
    int n_rolls;

    printf("Enter number of rolls per turn (%d-%d): ", 1, MAX_ROLLS);
    scanf("%d", &n_rolls);

    // ensure valid number of rolls
    if (n_rolls < 1 || n_rolls > MAX_ROLLS) {
        printf("Invalid number of rolls!\n");
        exit(1);
    }

    return n_rolls;
}

int main() {
    int n_dice, n_rolls, i, j, k;
    int roll_total, total;

    srand(time(NULL)); // seed random number generator

    // prompt for number of dice and rolls
    n_dice = prompt_n_dice();
    n_rolls = prompt_n_rolls();

    // loop until player quits
    while (1) {
        total = 0;

        // roll the dice
        for (i = 0; i < n_rolls; i++) {
            roll_total = 0;
            printf("Roll %d: ", i+1);

            for (j = 0; j < n_dice; j++) {
                k = roll_die();
                printf("%d ", k);
                roll_total += k;
            }

            printf("= %d\n", roll_total);
            total += roll_total;
        }

        printf("Total: %d\n", total);

        // prompt to play again
        char choice;
        printf("Play again? (y/n): ");
        scanf(" %c", &choice);
        if (choice == 'n')
            break;

        printf("\n");
    }

    return 0;
}