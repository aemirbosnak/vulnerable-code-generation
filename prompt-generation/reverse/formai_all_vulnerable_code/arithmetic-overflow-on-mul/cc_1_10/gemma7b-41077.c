//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Define the maximum number of steps a person can take in a day
    #define MAX_STEPS 10000

    // Create a struct to store the user's fitness data
    typedef struct FitnessData
    {
        int stepsTaken;
        float distanceTraveled;
        int caloriesBurned;
    } FitnessData;

    // Allocate memory for the user's fitness data
    FitnessData* fitnessData = malloc(sizeof(FitnessData));

    // Get the user's name and age
    char userName[20];
    int userAge;

    // Prompt the user to enter their name and age
    printf("Enter your name: ");
    scanf("%s", userName);

    printf("Enter your age: ");
    scanf("%d", &userAge);

    // Calculate the user's daily step goal
    int dailyStepGoal = MAX_STEPS * userAge / 100;

    // Set the user's fitness data
    fitnessData->stepsTaken = 0;
    fitnessData->distanceTraveled = 0.0f;
    fitnessData->caloriesBurned = 0;

    // Loop until the user reaches their daily step goal
    while (fitnessData->stepsTaken < dailyStepGoal)
    {
        // Get the user's input
        int stepsTakenToday = 0;

        // Prompt the user to enter the number of steps they took today
        printf("Enter the number of steps you took today: ");
        scanf("%d", &stepsTakenToday);

        // Update the user's fitness data
        fitnessData->stepsTaken += stepsTakenToday;
        fitnessData->distanceTraveled += (float)stepsTakenToday * 0.02f;
        fitnessData->caloriesBurned += stepsTakenToday * 10;

        // Print the user's progress
        printf("Your progress: %d/%d steps taken\n", fitnessData->stepsTaken, dailyStepGoal);
        printf("Distance traveled: %.2f miles\n", fitnessData->distanceTraveled);
        printf("Calories burned: %d\n", fitnessData->caloriesBurned);
    }

    // Print the user's success message
    printf("Congratulations, %s! You reached your daily step goal!", userName);

    // Free the memory allocated for the user's fitness data
    free(fitnessData);

    return 0;
}