//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define a struct to hold fitness data
typedef struct {
    int steps;
    float distance;
    float calories;
    bool isHealthy;
} FitnessData;

// Function to calculate calories burned based on distance traveled
float calculateCalories(float distance) {
    float caloriesPerMile = 100;
    return caloriesPerMile * distance;
}

int main() {
    // Create a FitnessData instance
    FitnessData data;

    // Prompt the user for their step count
    printf("How many steps did you take today?\n");
    scanf("%d", &data.steps);

    // Prompt the user for the distance they traveled (in miles)
    printf("How many miles did you travel?\n");
    scanf("%f", &data.distance);

    // Calculate calories burned
    data.calories = calculateCalories(data.distance);

    // Determine if user met daily healthy step goal threshold 
    if (data.steps >= 10000) {
        printf("Congratulations! You've met your daily step goal of 10,000 steps.\n");
        data.isHealthy = true;
    } else {
        printf("You've taken %d steps today. You need %d more steps to meet your daily goal of 10,000 steps.\n", data.steps, 10000 - data.steps);
        data.isHealthy = false;
    }

    // Print fitness data to console
    printf("Fitness Data:\n");
    printf("Steps Taken: %d\n", data.steps);
    printf("Distance Traveled: %.2f miles\n", data.distance);
    printf("Calories Burned: %.2f\n", data.calories);
    printf("Healthy Day? %s\n", data.isHealthy ? "Yes" : "No");

    return 0;
}