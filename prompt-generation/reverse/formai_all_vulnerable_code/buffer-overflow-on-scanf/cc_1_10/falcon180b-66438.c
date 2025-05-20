//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int roll;
    int num_rolls;
    int i;
    int sum = 0;
    int max_roll = 0;
    int min_roll = 999;
    int avg_roll;
    char play_again;

    srand(time(NULL));

    do {
        printf("Welcome to the C Dice Roller!\n");
        printf("How many rolls would you like to make? ");
        scanf("%d", &num_rolls);

        if (num_rolls < 1) {
            printf("Sorry, you must roll at least once.\n");
        } else if (num_rolls > 1000) {
            printf("Sorry, I don't have all day.\n");
        } else {
            for (i = 0; i < num_rolls; i++) {
                roll = rand() % 6 + 1;
                sum += roll;

                if (roll > max_roll) {
                    max_roll = roll;
                }

                if (roll < min_roll) {
                    min_roll = roll;
                }
            }

            avg_roll = sum / num_rolls;

            printf("You rolled the dice %d times.\n", num_rolls);
            printf("Your total is %d.\n", sum);
            printf("Your highest roll was %d.\n", max_roll);
            printf("Your lowest roll was %d.\n", min_roll);
            printf("Your average roll was %.2f.\n", (float)avg_roll / num_rolls);

            printf("Do you want to play again? (y/n) ");
            scanf(" %c", &play_again);
        }
    } while (play_again == 'y' || play_again == 'Y');

    return 0;
}