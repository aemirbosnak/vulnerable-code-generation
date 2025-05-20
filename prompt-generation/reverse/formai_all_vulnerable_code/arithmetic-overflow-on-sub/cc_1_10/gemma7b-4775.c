//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Initialize the fitness tracker
    int steps = 0;
    int calories = 0;
    int heart_rate = 0;
    time_t start_time = time(NULL);

    // Start tracking
    while (1)
    {
        // Get the user's input
        int input = getchar();

        // Check if the user wants to stop tracking
        if (input == 'q')
        {
            break;
        }

        // Increment the steps taken
        if (input == 's')
        {
            steps++;
        }

        // Increment the calories burned
        if (input == 'c')
        {
            calories++;
        }

        // Increment the heart rate
        if (input == 'h')
        {
            heart_rate++;
        }

        // Update the start time
        start_time = time(NULL);
    }

    // Calculate the total time spent tracking
    int total_time = (int)time(NULL) - (int)start_time;

    // Print the results
    printf("Total steps taken: %d\n", steps);
    printf("Total calories burned: %d\n", calories);
    printf("Total heart rate: %d\n", heart_rate);
    printf("Total time spent tracking: %d minutes\n", total_time);

    return 0;
}