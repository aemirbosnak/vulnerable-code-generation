//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function to calculate heart rate from steps and time taken
float calculateHeartRate(int steps, float time) {
    float heartRate = (220 - (0.15 * ((float)steps / time)));
    return heartRate;
}

// Function to calculate calories burned from heart rate and weight
float calculateCaloriesBurned(float heartRate, float weight) {
    float caloriesBurned = (heartRate * weight) / 200;
    return caloriesBurned;
}

// Function to calculate distance traveled from steps and step length
float calculateDistanceTraveled(int steps, float stepLength) {
    float distanceTraveled = (stepLength * ((float)steps / 2));
    return distanceTraveled;
}

// Function to get user input for steps, time, weight and step length
void getUserInput(int *steps, float *time, float *weight, float *stepLength) {
    printf("Enter the number of steps taken: ");
    scanf("%d", steps);

    printf("Enter the time taken in seconds: ");
    scanf("%f", time);

    printf("Enter your weight in pounds: ");
    scanf("%f", weight);

    printf("Enter your step length in feet: ");
    scanf("%f", stepLength);
}

// Main function to call all other functions and display results
int main() {
    int steps;
    float time, weight, stepLength;

    // Get user input for steps, time, weight and step length
    getUserInput(&steps, &time, &weight, &stepLength);

    // Calculate heart rate, calories burned and distance traveled
    float heartRate = calculateHeartRate(steps, time);
    float caloriesBurned = calculateCaloriesBurned(heartRate, weight);
    float distanceTraveled = calculateDistanceTraveled(steps, stepLength);

    // Display results
    printf("\nHeart rate: %.2f\n", heartRate);
    printf("Calories burned: %.2f\n", caloriesBurned);
    printf("Distance traveled: %.2f\n", distanceTraveled);

    return 0;
}