//FormAI DATASET v1.0 Category: Dice Roller ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_dice, num_sides, roll_again, i, j;
    int total_rolls = 0, total_sum = 0;

    srand(time(0)); // initialize random seed

    printf("Welcome to Dice Roller!\n");

    // get number of dice to roll
    printf("How many dice would you like to roll? ");
    scanf("%d", &num_dice);

    // get number of sides on each die
    printf("How many sides does each die have? ");
    scanf("%d", &num_sides);

    // roll the dice
    do {
        printf("\nRolling %d %d-sided dice...\n", num_dice, num_sides);
        
        int rolls[num_dice];
        int sum = 0;

        // roll each die and add to sum
        for (i = 0; i < num_dice; i++) {
            rolls[i] = rand() % num_sides + 1; // generate random number between 1 and num_sides
            sum += rolls[i];
            printf("Die %d: %d\n", i+1, rolls[i]);
        }

        // print sum and average roll
        printf("Sum: %d\n", sum);
        printf("Average roll: %f\n", (float)sum / num_dice);

        total_sum += sum;
        total_rolls++;

        // ask if user wants to roll again
        printf("\nRoll again? (1 for yes, 0 for no) ");
        scanf("%d", &roll_again);
    } while (roll_again == 1);

    printf("\nThanks for using Dice Roller!\n");
    printf("Total rolls: %d\n", total_rolls);
    printf("Total sum: %d\n", total_sum);

    return 0;
}