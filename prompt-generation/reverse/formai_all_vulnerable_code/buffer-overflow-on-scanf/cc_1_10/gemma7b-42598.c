//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to store fitness tracker data
typedef struct FitnessTracker {
    char name[20];
    int age;
    float height;
    float weight;
    int stepsTaken;
    int caloriesBurned;
} FitnessTracker;

// Function to calculate the number of calories burned
int calculateCalories(int weight, int stepsTaken) {
    int calories = (weight * stepsTaken) / 10;
    return calories;
}

// Function to store fitness tracker data
void storeFitnessTrackerData(FitnessTracker *fitTracker) {
    printf("Enter your name: ");
    scanf("%s", fitTracker->name);

    printf("Enter your age: ");
    scanf("%d", &fitTracker->age);

    printf("Enter your height (in inches): ");
    scanf("%f", &fitTracker->height);

    printf("Enter your weight (in pounds): ");
    scanf("%f", &fitTracker->weight);

    printf("Enter the number of steps you took today: ");
    scanf("%d", &fitTracker->stepsTaken);

    fitTracker->caloriesBurned = calculateCalories(fitTracker->weight, fitTracker->stepsTaken);
}

// Main function
int main() {
    // Create a fitness tracker object
    FitnessTracker fitTracker;

    // Store fitness tracker data
    storeFitnessTrackerData(&fitTracker);

    // Display fitness tracker data
    printf("Name: %s\n", fitTracker.name);
    printf("Age: %d\n", fitTracker.age);
    printf("Height: %.2f inches\n", fitTracker.height);
    printf("Weight: %.2f pounds\n", fitTracker.weight);
    printf("Steps taken: %d\n", fitTracker.stepsTaken);
    printf("Calories burned: %d\n", fitTracker.caloriesBurned);

    return 0;
}