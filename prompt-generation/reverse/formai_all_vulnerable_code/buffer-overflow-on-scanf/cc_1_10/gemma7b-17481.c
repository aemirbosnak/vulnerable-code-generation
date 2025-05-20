//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of steps that can be tracked
#define MAX_STEPS 10000

// Define the maximum number of calories that can be burned
#define MAX_CALORIES 5000

// Define the maximum number of minutes that can be tracked
#define MAX_MINUTES 60

// Create a structure to store fitness data
typedef struct FitnessData {
    int stepsTaken;
    int caloriesBurned;
    int minutesSpent;
} FitnessData;

// Function to track steps taken
void trackSteps(FitnessData *data) {
    printf("Enter the number of steps taken: ");
    scanf("%d", &data->stepsTaken);
}

// Function to track calories burned
void trackCalories(FitnessData *data) {
    printf("Enter the number of calories burned: ");
    scanf("%d", &data->caloriesBurned);
}

// Function to track minutes spent
void trackMinutes(FitnessData *data) {
    printf("Enter the number of minutes spent exercising: ");
    scanf("%d", &data->minutesSpent);
}

// Function to display fitness data
void displayFitnessData(FitnessData data) {
    printf("Your fitness data for today:\n");
    printf("Steps taken: %d\n", data.stepsTaken);
    printf("Calories burned: %d\n", data.caloriesBurned);
    printf("Minutes spent exercising: %d\n", data.minutesSpent);
}

int main() {
    // Create a structure to store fitness data
    FitnessData data;

    // Track steps taken
    trackSteps(&data);

    // Track calories burned
    trackCalories(&data);

    // Track minutes spent
    trackMinutes(&data);

    // Display fitness data
    displayFitnessData(data);

    return 0;
}