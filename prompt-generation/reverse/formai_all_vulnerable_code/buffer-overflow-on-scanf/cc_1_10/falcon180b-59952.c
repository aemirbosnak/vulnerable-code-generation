//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_DICE 6
#define NUM_SIDES 6

int roll_dice() {
    int i, sum = 0;
    srand(time(0)); // seed the random number generator with current time

    for (i = 0; i < NUM_DICE; i++) {
        sum += rand() % NUM_SIDES + 1; // generate a random number between 1 and 6 and add it to the sum
    }

    return sum;
}

int main() {
    int num_rolls = 0, total_sum = 0, max_sum = 0;

    printf("Welcome to the Dice Roller!\n");

    while (1) {
        printf("How many times do you want to roll the dice? ");
        scanf("%d", &num_rolls);

        if (num_rolls <= 0) {
            printf("Invalid input. Please enter a positive integer.\n");
            continue;
        }

        printf("Rolling the dice %d times...\n", num_rolls);

        int roll, curr_sum = 0;
        for (int i = 0; i < num_rolls; i++) {
            roll = roll_dice();
            printf("Roll %d: %d\n", i+1, roll);
            curr_sum += roll;

            if (curr_sum > max_sum) {
                max_sum = curr_sum;
            }
        }

        total_sum += curr_sum;
        printf("Total sum: %d\n", total_sum);
        printf("Maximum sum: %d\n", max_sum);

        printf("Do you want to roll again? (y/n) ");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'n') {
            break;
        }
    }

    return 0;
}