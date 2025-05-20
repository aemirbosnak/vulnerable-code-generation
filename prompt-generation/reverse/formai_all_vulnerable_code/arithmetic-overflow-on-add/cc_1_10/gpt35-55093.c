//FormAI DATASET v1.0 Category: Dice Roller ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
int roll_dice(int num_dice, int num_sides);
char prompt_play_again();

int main(void) {
    srand(time(0)); // Seed random number generator
    int num_dice, num_sides, total, roll, i;
    char play_again;

    printf("===== Dice Roller =====\n");
    do {
        printf("How many dice do you want to roll? ");
        scanf(" %d", &num_dice);
        printf("How many sides do the dice have? ");
        scanf(" %d", &num_sides);

        total = 0;
        printf("The dice are rolling...\n");
        for (i = 1; i <= num_dice; i++) {
            roll = roll_dice(1, num_sides);
            printf("Die %d: %d\n", i, roll);
            total += roll;
        }
        printf("Total roll: %d\n", total);

        play_again = prompt_play_again();
    } while (play_again == 'y' || play_again == 'Y');

    printf("Thanks for playing!\n");

    return 0;
}

int roll_dice(int num_dice, int num_sides) {
    int total = 0, i;
    for (i = 1; i <= num_dice; i++) {
        total += rand() % num_sides + 1;
    }
    return total;
}

char prompt_play_again() {
    char choice;
    while (1) {
        printf("Do you want to play again? (y/n) ");
        scanf(" %c", &choice);
        if (choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N') {
            break;
        }
        printf("Invalid choice, please enter 'y' or 'n'.\n");
    }
    return choice;
}