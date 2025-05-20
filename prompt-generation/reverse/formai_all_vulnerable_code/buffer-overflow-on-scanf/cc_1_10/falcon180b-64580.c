//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIDES 6
#define MAX_DICE 100

int roll_dice(int num_dice, int sides) {
    int i, result = 0;
    for (i = 0; i < num_dice; i++) {
        result += rand() % sides + 1;
    }
    return result;
}

int main() {
    int num_dice, sides = SIDES, total_rolls = 0, max_rolls = 0, current_rolls = 0;
    double average = 0.0;
    char play_again = 'y';

    srand(time(NULL));

    while (play_again == 'y' || play_again == 'Y') {
        printf("Enter number of dice to roll (1-%d): ", MAX_DICE);
        scanf("%d", &num_dice);

        if (num_dice > MAX_DICE || num_dice < 1) {
            printf("Invalid input. Please try again.\n");
            continue;
        }

        total_rolls = 0;
        max_rolls = 0;
        current_rolls = 0;

        while (total_rolls < 10) {
            int roll = roll_dice(num_dice, sides);
            total_rolls++;
            if (roll > max_rolls) {
                max_rolls = roll;
            }
            if (current_rolls == 0 || roll > current_rolls) {
                current_rolls = roll;
            }
        }

        printf("You rolled %d dice with %d sides.\n", num_dice, sides);
        printf("Total rolls: %d\n", total_rolls);
        printf("Maximum roll: %d\n", max_rolls);
        printf("Current roll: %d\n", current_rolls);
        printf("Average roll: %.2f\n\n", (double)total_rolls / SIDES);

        printf("Play again? (y/n): ");
        scanf(" %c", &play_again);
    }

    return 0;
}