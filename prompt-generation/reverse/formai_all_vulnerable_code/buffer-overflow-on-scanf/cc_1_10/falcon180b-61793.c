//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_DICE 3
#define NUM_SIDES 6

// Function to roll a single die
int roll_die() {
    return rand() % NUM_SIDES + 1;
}

// Function to roll multiple dice and return total
int roll_dice(int num_dice) {
    int total = 0;
    for (int i = 0; i < num_dice; i++) {
        total += roll_die();
    }
    return total;
}

// Main function
int main() {
    srand(time(NULL)); // Seed random number generator with current time

    int total;
    int player_total;
    int num_dice;
    int num_rolls = 0;
    int wins = 0;
    int losses = 0;
    int ties = 0;

    printf("Welcome to the post-apocalyptic dice game!\n");
    printf("In this game, you will roll %d dice with %d sides each.\n", NUM_DICE, NUM_SIDES);
    printf("You must roll a total of %d or higher to win.\n", 10);

    while (1) {
        printf("\nRoll the dice? (y/n) ");
        char choice;
        scanf("%c", &choice);

        if (choice == 'y') {
            num_dice = NUM_DICE;
            printf("Rolling %d dice...\n", num_dice);
            total = roll_dice(num_dice);
            printf("You rolled a total of %d.\n", total);

            if (total >= 10) {
                wins++;
                printf("You win!\n");
            } else if (total == 7) {
                losses++;
                printf("You lose!\n");
            } else {
                ties++;
                printf("It's a tie!\n");
            }

            num_rolls++;
            if (num_rolls == 10) {
                printf("\nGame over.\n");
                printf("You won %d times, lost %d times, and tied %d times.\n", wins, losses, ties);
                break;
            }
        } else if (choice == 'n') {
            break;
        } else {
            printf("Invalid input. Try again.\n");
        }
    }

    return 0;
}