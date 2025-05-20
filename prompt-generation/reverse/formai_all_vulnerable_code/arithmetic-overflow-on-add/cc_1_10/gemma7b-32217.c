//Gemma-7B DATASET v1.0 Category: Dice Roller ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number_of_rolls = 0;
    int total_sum = 0;
    int current_roll = 0;
    int face_of_the_die = 0;

    printf("Welcome to the Dice Roller Game!\n");

    // Loop until the user enters a valid number of rolls
    while (1)
    {
        printf("Enter the number of rolls you want to make: ");
        scanf("%d", &number_of_rolls);

        if (number_of_rolls > 0)
        {
            break;
        }
        else
        {
            printf("Invalid input. Please try again.\n");
        }
    }

    // Loop to roll the die for the specified number of times
    for (int i = 0; i < number_of_rolls; i++)
    {
        // Generate a random number between 1 and 6
        face_of_the_die = rand() % 6 + 1;

        // Add the face of the die to the current roll
        current_roll += face_of_the_die;

        // Increment the number of rolls
        number_of_rolls++;

        // Print the face of the die
        printf("Roll %d: %d\n", number_of_rolls, face_of_the_die);
    }

    // Calculate the total sum of the rolls
    total_sum = current_roll;

    // Print the total sum of the rolls
    printf("Total Sum: %d\n", total_sum);

    return 0;
}