//Gemma-7B DATASET v1.0 Category: Table Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

#define NUM_SIDES 6

int main()
{
    // Variables
    int roll_number = 0;
    int number_of_rolls = 0;
    int sum_of_rolls = 0;
    int average_roll = 0;
    int sides_of_die = NUM_SIDES;

    // Loop until the user wants to quit
    while (1)
    {
        // Get the number of rolls from the user
        printf("How many rolls do you want to make? ");
        scanf("%d", &number_of_rolls);

        // Calculate the number of rolls
        roll_number = number_of_rolls;

        // Roll the die
        for (int i = 0; i < roll_number; i++)
        {
            int roll_result = rand() % sides_of_die + 1;
            sum_of_rolls += roll_result;
        }

        // Calculate the average roll
        average_roll = sum_of_rolls / roll_number;

        // Print the results
        printf("Your total roll is: %d\n", sum_of_rolls);
        printf("Your average roll is: %d\n", average_roll);

        // Ask the user if they want to continue
        printf("Do you want to continue? (Y/N) ");
        char continue_answer;
        scanf("%c", &continue_answer);

        // If the user does not want to continue, break out of the loop
        if (continue_answer == 'N')
        {
            break;
        }

        // Reset the variables
        sum_of_rolls = 0;
        average_roll = 0;
    }

    return 0;
}