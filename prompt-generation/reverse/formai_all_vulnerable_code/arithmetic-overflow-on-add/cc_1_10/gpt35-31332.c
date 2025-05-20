//FormAI DATASET v1.0 Category: Dice Roller ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(int sides);
int get_int(char prompt[]);

int main(void)
{
    int dice_sides, num_rolls, total = 0, roll;
    
    // Seed the random number generator
    srand((unsigned int)time(NULL));
    
    printf("=== Dice Roller ===\n\n");
    
    // Get the number of sides on the dice
    dice_sides = get_int("Enter the number of sides on the dice: ");
    
    // Get the number of rolls to perform
    num_rolls = get_int("Enter the number of rolls to perform: ");
    
    // Roll the dice and display the results
    printf("\nRolling %d %d-sided dice...\n", num_rolls, dice_sides);
    for (int i = 0; i < num_rolls; i++) {
        roll = roll_dice(dice_sides);
        printf("Roll %2d: %d\n", i+1, roll);
        total += roll;
    }
    
    printf("\nTotal: %d\n", total);
    
    return 0;
}

/*
 * Roll a dice with the specified number of sides.
 * Returns a random number between 1 and the number of sides.
 */
int roll_dice(int sides)
{
    return rand() % sides + 1;
}

/*
 * Prompt the user for an integer value.
 * Returns the entered integer.
 */
int get_int(char prompt[])
{
    int input;
    
    do {
        printf("%s", prompt);
        fflush(stdout);
    } while (scanf("%d", &input) != 1);
    
    return input;
}