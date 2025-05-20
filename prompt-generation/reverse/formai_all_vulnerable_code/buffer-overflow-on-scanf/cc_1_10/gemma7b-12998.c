//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: satisfied
#include <stdio.h>
#include <string.h>

// Define a structure to store fitness tracker data
typedef struct FitnessTrackerData {
    char name[50];
    int age;
    double height;
    double weight;
    double targetHeartRate;
    int stepsTaken;
    double distanceTraveled;
} FitnessTrackerData;

// Function to calculate target heart rate
double calculateTargetHeartRate(int age, double height, double weight) {
    int maxHeartRate = 220 - (age * 2);
    double targetHeartRate = (maxHeartRate - 50) * height / 2.2 * weight / 100;
    return targetHeartRate;
}

// Function to calculate steps taken
int calculateStepsTaken(double distanceTraveled) {
    int stepsTaken = (int)(distanceTraveled * 1000);
    return stepsTaken;
}

// Function to calculate distance traveled
double calculateDistanceTraveled(int stepsTaken) {
    double distanceTraveled = (double)stepsTaken / 1000;
    return distanceTraveled;
}

int main() {
    // Create a fitness tracker data structure
    FitnessTrackerData fitnessTrackerData;

    // Get the user's name, age, height, and weight
    printf("Enter your name: ");
    scanf("%s", fitnessTrackerData.name);

    printf("Enter your age: ");
    scanf("%d", &fitnessTrackerData.age);

    printf("Enter your height (in inches): ");
    scanf("%lf", &fitnessTrackerData.height);

    printf("Enter your weight (in pounds): ");
    scanf("%lf", &fitnessTrackerData.weight);

    // Calculate the target heart rate
    fitnessTrackerData.targetHeartRate = calculateTargetHeartRate(fitnessTrackerData.age, fitnessTrackerData.height, fitnessTrackerData.weight);

    // Calculate the number of steps taken
    fitnessTrackerData.stepsTaken = calculateStepsTaken(fitnessTrackerData.distanceTraveled);

    // Calculate the distance traveled
    fitnessTrackerData.distanceTraveled = calculateDistanceTraveled(fitnessTrackerData.stepsTaken);

    // Print the fitness tracker data
    printf("Name: %s\n", fitnessTrackerData.name);
    printf("Age: %d\n", fitnessTrackerData.age);
    printf("Height: %.2lf inches\n", fitnessTrackerData.height);
    printf("Weight: %.2lf pounds\n", fitnessTrackerData.weight);
    printf("Target Heart Rate: %.2lf beats per minute\n", fitnessTrackerData.targetHeartRate);
    printf("Steps Taken: %d\n", fitnessTrackerData.stepsTaken);
    printf("Distance Traveled: %.2lf miles\n", fitnessTrackerData.distanceTraveled);

    return 0;
}