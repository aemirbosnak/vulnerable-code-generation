//FormAI DATASET v1.0 Category: Dice Roller ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int dice, sides, roll_again = 1;
    char response;

    srand(time(NULL));

    printf("Welcome to the Mind-Bending Dice Roller!\n");

    do {
        printf("\nHow many sides does your dice have?\n");
        scanf("%d", &sides);

        if (sides < 2) {
            printf("\nThat dice is too small for my mind-bending powers!\n");
            continue;
        }

        printf("\nHow many dice do you want to roll?\n");
        scanf("%d", &dice);

        if (dice < 1) {
            printf("\nWe need at least one dice to roll!\n");
            continue;
        }

        printf("\nRolling the dice...\n");

        for (int i = 1; i <= dice; i++) {
            int result = rand() % sides + 1;
            printf("\nDice %d: %d", i, result);
        }

        printf("\n\nWould you like to roll again? (y/n)\n");
        scanf(" %c", &response);

        if (response == 'y' || response == 'Y') {
            roll_again = 1;
        } else {
            roll_again = 0;
        }

    } while (roll_again);

    printf("\nThanks for playing the Mind-Bending Dice Roller! Goodbye!\n");

    return 0;
}