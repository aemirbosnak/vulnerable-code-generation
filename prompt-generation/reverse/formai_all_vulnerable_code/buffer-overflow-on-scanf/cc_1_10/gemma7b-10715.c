//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store fitness tracker data
typedef struct FitnessTracker {
    int stepsTaken;
    int caloriesBurned;
    int distanceTraveled;
    int heartRate;
} FitnessTracker;

// Function to calculate the number of calories burned
int calculateCalories(int stepsTaken) {
    return (stepsTaken * 0.036) + 60;
}

// Function to calculate the distance traveled
int calculateDistance(int stepsTaken) {
    return (stepsTaken * 0.02) + 1;
}

// Function to calculate the heart rate
int calculateHeartRate(int age) {
    return 220 - (age * 0.67);
}

int main() {
    // Create a fitness tracker object
    FitnessTracker fitTracker;

    // Get the user's age and number of steps taken
    int age;
    printf("Enter your age: ");
    scanf("%d", &age);

    int stepsTaken;
    printf("Enter the number of steps you took: ");
    scanf("%d", &stepsTaken);

    // Calculate the number of calories burned, distance traveled, and heart rate
    fitTracker.caloriesBurned = calculateCalories(stepsTaken);
    fitTracker.distanceTraveled = calculateDistance(stepsTaken);
    fitTracker.heartRate = calculateHeartRate(age);

    // Print the fitness tracker data
    printf("Your fitness tracker data is:\n");
    printf("Number of steps taken: %d\n", fitTracker.stepsTaken);
    printf("Number of calories burned: %d\n", fitTracker.caloriesBurned);
    printf("Distance traveled: %d miles\n", fitTracker.distanceTraveled);
    printf("Heart rate: %d beats per minute\n", fitTracker.heartRate);

    return 0;
}