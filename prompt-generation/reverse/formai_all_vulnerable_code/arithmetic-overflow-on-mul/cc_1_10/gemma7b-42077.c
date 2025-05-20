//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: funny
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int stepsTaken = 0;
    int distanceTraveled = 0;
    float timeSpent = 0.0f;
    char mood = 'H';

    // Initialize the fitness tracker
    printf("Welcome to the McFit 3000! Prepare to be fit!\n");

    // Loop until the user decides to quit
    while (mood != 'Q')
    {
        // Get the user's input
        printf("Enter the number of steps you took today: ");
        scanf("%d", &stepsTaken);

        // Calculate the distance traveled
        distanceTraveled = stepsTaken * 2;

        // Calculate the time spent
        timeSpent = (stepsTaken / 200.0f) + 1.0f;

        // Update the user's mood
        if (distanceTraveled >= 1000)
        {
            mood = 'S';
        }
        else if (timeSpent >= 2.0f)
        {
            mood = 'A';
        }
        else
        {
            mood = 'H';
        }

        // Print the results
        printf("You took %d steps, traveled %d miles, and spent %f hours exercising.\n", stepsTaken, distanceTraveled, timeSpent);

        // Check if the user wants to quit
        printf("Do you want to quit (Q/N)? ");
        scanf(" %c", &mood);
    }

    // Goodbye
    printf("Thanks for using the McFit 3000! See you next time.\n");
}