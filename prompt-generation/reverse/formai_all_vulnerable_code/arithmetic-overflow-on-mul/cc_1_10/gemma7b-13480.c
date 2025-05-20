//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store fitness tracker data
typedef struct FitnessTrackerData
{
    int heartRate;
    float distanceTraveled;
    double timeSpent;
    char mood;
} FitnessTrackerData;

// Function to calculate the average heart rate
int calculateAverageHeartRate(FitnessTrackerData data)
{
    int averageHeartRate = (data.heartRate * 3) / 4;
    return averageHeartRate;
}

// Function to calculate the total distance traveled
float calculateTotalDistanceTraveled(FitnessTrackerData data)
{
    float totalDistanceTraveled = data.distanceTraveled * 1.613;
    return totalDistanceTraveled;
}

// Function to calculate the total time spent
double calculateTotalTimeSpent(FitnessTrackerData data)
{
    double totalTimeSpent = data.timeSpent / 60;
    return totalTimeSpent;
}

// Function to determine the mood
char determineMood(FitnessTrackerData data)
{
    char mood;

    if (data.heartRate >= 80)
    {
        mood = 'H';
    }
    else if (data.heartRate >= 60)
    {
        mood = 'M';
    }
    else
    {
        mood = 'L';
    }

    return mood;
}

int main()
{
    // Create a fitness tracker data structure
    FitnessTrackerData data;

    // Get the heart rate, distance traveled, and time spent from the user
    printf("Enter your heart rate: ");
    scanf("%d", &data.heartRate);

    printf("Enter the distance traveled in kilometers: ");
    scanf("%f", &data.distanceTraveled);

    printf("Enter the time spent in minutes: ");
    scanf("%lf", &data.timeSpent);

    // Calculate the average heart rate, total distance traveled, total time spent, and mood
    int averageHeartRate = calculateAverageHeartRate(data);
    float totalDistanceTraveled = calculateTotalDistanceTraveled(data);
    double totalTimeSpent = calculateTotalTimeSpent(data);
    char mood = determineMood(data);

    // Print the results
    printf("Your average heart rate is: %d\n", averageHeartRate);
    printf("Your total distance traveled is: %.2f kilometers\n", totalDistanceTraveled);
    printf("Your total time spent is: %.2f hours\n", totalTimeSpent);
    printf("Your mood is: %c\n", mood);

    return 0;
}