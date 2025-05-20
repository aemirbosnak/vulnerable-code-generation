//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: safe
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int steps_taken = 0;
    int current_hour = 0;
    int current_minute = 0;

    // Initialize the steps taken counter
    steps_taken = 0;

    // Initialize the current time
    current_hour = 0;
    current_minute = 0;

    // Loop to simulate activity
    while (1)
    {
        // Simulate walking for 3 minutes
        for (int i = 0; i < 3; i++)
        {
            // Increment the number of steps taken
            steps_taken++;

            // Update the current time
            current_hour++;
            current_minute++;

            // Print the current time and number of steps taken
            printf("Time: %02d:%02d, Steps taken: %d\n", current_hour, current_minute, steps_taken);
        }

        // Take a break for 3 minutes
        for (int i = 0; i < 3; i++)
        {
            // Update the current time
            current_hour++;
            current_minute++;

            // Print the current time and number of steps taken
            printf("Time: %02d:%02d, Steps taken: %d\n", current_hour, current_minute, steps_taken);
        }

        // Check if the user wants to continue
        int continue_flag = 0;
        printf("Do you want to continue? (Y/N): ");
        char answer;
        scanf("%c", &answer);

        // If the user does not want to continue, break out of the loop
        if (answer == 'N')
        {
            break;
        }
    }

    // Print the final number of steps taken
    printf("Total number of steps taken: %d\n", steps_taken);

    return 0;
}