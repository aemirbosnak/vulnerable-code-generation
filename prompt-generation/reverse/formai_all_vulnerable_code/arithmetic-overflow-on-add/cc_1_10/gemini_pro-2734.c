//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of dice and the number of sides on each die
#define NUM_DICE 5
#define NUM_SIDES 6

// Generate a random number between 1 and the specified number
int roll_die(int num_sides)
{
    return rand() % num_sides + 1;
}

// Roll the specified number of dice and return the sum of the results
int roll_dice(int num_dice, int num_sides)
{
    int sum = 0;
    for (int i = 0; i < num_dice; i++)
    {
        sum += roll_die(num_sides);
    }
    return sum;
}

// Print the results of rolling the dice
void print_results(int num_dice, int num_sides, int sum)
{
    printf("You rolled %d dice with %d sides each.\n", num_dice, num_sides);
    printf("The sum of the results is %d.\n", sum);
}

int main()
{
    // Initialize the random number generator
    srand(time(NULL));

    // Get the number of dice and the number of sides on each die from the user
    int num_dice, num_sides;
    printf("How many dice do you want to roll? ");
    scanf("%d", &num_dice);
    printf("How many sides should each die have? ");
    scanf("%d", &num_sides);

    // Roll the dice and print the results
    int sum = roll_dice(num_dice, num_sides);
    print_results(num_dice, num_sides, sum);

    return 0;
}