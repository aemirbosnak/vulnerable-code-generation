//FormAI DATASET v1.0 Category: Dice Roller ; Style: satisfied
// Dice Roller Program
// By [Your Name]

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(int n)
{
    // This function simulates rolling n dice
    // Returns the sum of the face values
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int face = rand() % 6 + 1;
        sum += face;
        printf("Die %d rolled a %d.\n", i+1, face);
    }
    return sum;
}

int main()
{
    srand(time(0));  // Seed the random number generator

    printf("Welcome to the Dice Roller Program!\n");
    printf("How many dice do you want to roll? ");
    int num_dice;
    scanf("%d", &num_dice);

    if (num_dice < 1) {
        printf("Error: Invalid number of dice. You must roll at least 1 die.\n");
        return 1;
    }

    printf("How many times do you want to roll the dice? ");
    int num_rolls;
    scanf("%d", &num_rolls);

    if (num_rolls < 1) {
        printf("Error: Invalid number of rolls. You must roll at least 1 time.\n");
        return 1;
    }

    int roll_totals[num_rolls];
    for (int i = 0; i < num_rolls; i++) {
        printf("Roll %d:\n", i+1);
        roll_totals[i] = roll_dice(num_dice);
        printf("Total: %d\n\n", roll_totals[i]);
    }

    printf("Here are the results of your dice rolls:\n");
    for (int i = 0; i < num_rolls; i++) {
        printf("Roll %d: %d\n", i+1, roll_totals[i]);
    }

    return 0;
}