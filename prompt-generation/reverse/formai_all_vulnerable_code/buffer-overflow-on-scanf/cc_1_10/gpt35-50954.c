//FormAI DATASET v1.0 Category: Table Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
int roll_dice(void);
int play_game(void);

int main(void)
{
    int wins = 0, losses = 0;

    srand(time(NULL)); // initialize random number generator

    printf("Welcome to the peaceful game of Dice!\n\n");

    char repeat = 'y';
    while (repeat == 'y') {
        if (play_game()) {
            printf("You win!\n\n");
            wins++;
        } else {
            printf("You lose!\n\n");
            losses++;
        }

        printf("Play again? (y/n): ");
        scanf(" %c", &repeat);
    }

    printf("\nWins: %d  Losses: %d\n", wins, losses);
    
    return 0;
}

// Roll two dice and return their sum
int roll_dice(void)
{
    int die1 = rand() % 6 + 1; // generate random number from 1 to 6
    int die2 = rand() % 6 + 1;

    printf("You rolled %d and %d\n", die1, die2);
    return die1 + die2;
}

// Play one round of the game
int play_game(void)
{
    int point = roll_dice();

    if (point == 7 || point == 11) {
        return 1; // win
    } else if (point == 2 || point == 3 || point == 12) {
        return 0; // lose
    }

    printf("Your point is %d\n", point);

    int roll;
    while (1) {
        roll = roll_dice();
        if (roll == point) {
            return 1; // win
        } else if (roll == 7) {
            return 0; // lose
        }
    }
}