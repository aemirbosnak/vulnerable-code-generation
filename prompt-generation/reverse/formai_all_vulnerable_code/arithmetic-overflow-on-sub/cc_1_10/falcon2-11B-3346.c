//Falcon2-11B DATASET v1.0 Category: Fitness Tracker ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define constants
#define MAX_DISTANCE 1000 // in meters
#define MAX_STEPS 10000 // number of steps
#define MAX_CALORIES 5000 // calories burned
#define MAX_HEART_RATE 220 // maximum heart rate

// Define struct for holding fitness data
typedef struct {
    int distance;
    int steps;
    int calories;
    int heart_rate;
} FitnessData;

// Function to calculate calories burned based on heart rate
int calculateCalories(int heart_rate) {
    return (heart_rate / 100) * ((heart_rate - 50) * 4.184);
}

// Function to track fitness data
void trackFitness(FitnessData* data) {
    // Set default values for fitness data
    data->distance = 0;
    data->steps = 0;
    data->calories = 0;
    data->heart_rate = 0;

    // Read input from user for fitness data
    printf("Enter distance in meters: ");
    scanf("%d", &data->distance);

    printf("Enter number of steps: ");
    scanf("%d", &data->steps);

    printf("Enter calories burned: ");
    scanf("%d", &data->calories);

    printf("Enter heart rate: ");
    scanf("%d", &data->heart_rate);

    // Calculate calories burned based on heart rate
    data->calories = calculateCalories(data->heart_rate);

    // Display fitness data
    printf("Distance: %d meters\n", data->distance);
    printf("Steps: %d\n", data->steps);
    printf("Calories burned: %d calories\n", data->calories);
    printf("Heart rate: %d beats per minute\n", data->heart_rate);
}

// Main function
int main() {
    FitnessData data;
    trackFitness(&data);
    return 0;
}