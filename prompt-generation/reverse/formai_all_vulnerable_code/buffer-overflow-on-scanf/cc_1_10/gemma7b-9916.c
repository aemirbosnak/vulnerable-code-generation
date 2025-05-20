//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Define a struct to store fitness data
    typedef struct FitnessData
    {
        int stepsTaken;
        int distanceTraveled;
        int caloriesBurned;
        char mood;
    } FitnessData;

    // Create a pointer to a fitness data structure
    FitnessData* fitnessData = (FitnessData*)malloc(sizeof(FitnessData));

    // Initialize the fitness data structure
    fitnessData->stepsTaken = 0;
    fitnessData->distanceTraveled = 0;
    fitnessData->caloriesBurned = 0;
    fitnessData->mood = 'N';

    // Get the user's input
    printf("Enter the number of steps you took: ");
    scanf("%d", &fitnessData->stepsTaken);

    // Calculate the distance traveled
    fitnessData->distanceTraveled = fitnessData->stepsTaken * 2;

    // Calculate the calories burned
    fitnessData->caloriesBurned = fitnessData->stepsTaken * 10;

    // Set the user's mood
    if (fitnessData->caloriesBurned >= 500)
    {
        fitnessData->mood = 'H';
    }
    else if (fitnessData->caloriesBurned >= 200)
    {
        fitnessData->mood = 'G';
    }
    else
    {
        fitnessData->mood = 'L';
    }

    // Print the fitness data
    printf("Your steps taken: %d\n", fitnessData->stepsTaken);
    printf("Distance traveled: %d miles\n", fitnessData->distanceTraveled);
    printf("Calories burned: %d\n", fitnessData->caloriesBurned);
    printf("Mood: %c\n", fitnessData->mood);

    // Free the memory allocated for the fitness data structure
    free(fitnessData);

    return 0;
}