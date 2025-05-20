//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store fitness tracker data
typedef struct FitnessTrackerData
{
    int stepsTaken;
    float distanceTraveled;
    double caloriesBurned;
    char activityType;
} FitnessTrackerData;

// Function to calculate the number of calories burned
int calculateCalories(int stepsTaken, char activityType)
{
    int caloriesBurned = 0;

    // Calculate the number of calories burned based on the activity type
    switch (activityType)
    {
        case 'a':
            caloriesBurned = stepsTaken * 0.01;
            break;
        case 'b':
            caloriesBurned = stepsTaken * 0.02;
            break;
        case 'c':
            caloriesBurned = stepsTaken * 0.03;
            break;
        default:
            break;
    }

    return caloriesBurned;
}

int main()
{
    // Create a fitness tracker data structure
    FitnessTrackerData trackerData;

    // Get the user's input
    printf("Enter the number of steps taken: ");
    scanf("%d", &trackerData.stepsTaken);

    // Get the user's activity type
    printf("Enter the activity type (a, b, c): ");
    scanf(" %c", &trackerData.activityType);

    // Calculate the number of calories burned
    trackerData.caloriesBurned = calculateCalories(trackerData.stepsTaken, trackerData.activityType);

    // Display the results
    printf("Number of steps taken: %d\n", trackerData.stepsTaken);
    printf("Distance traveled: %.2f miles\n", trackerData.distanceTraveled);
    printf("Calories burned: %.2f\n", trackerData.caloriesBurned);

    return 0;
}