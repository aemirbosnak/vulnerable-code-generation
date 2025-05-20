//Falcon2-11B DATASET v1.0 Category: Fitness Tracker ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int heartRate;
    int steps;
    int caloriesBurned;
} fitnessTracker;

void calculateAverages(fitnessTracker tracker) {
    int totalHeartRate = tracker.heartRate;
    int totalSteps = tracker.steps;
    int totalCaloriesBurned = tracker.caloriesBurned;

    int avgHeartRate = totalHeartRate / 2;
    int avgSteps = totalSteps / 2;
    int avgCaloriesBurned = totalCaloriesBurned / 2;

    printf("Heart rate: %d\n", avgHeartRate);
    printf("Steps: %d\n", avgSteps);
    printf("Calories burned: %d\n", avgCaloriesBurned);
}

int main() {
    fitnessTracker tracker;

    int heartRate;
    int steps;
    int caloriesBurned;

    printf("Enter heart rate: ");
    scanf("%d", &heartRate);

    printf("Enter steps: ");
    scanf("%d", &steps);

    printf("Enter calories burned: ");
    scanf("%d", &caloriesBurned);

    tracker.heartRate = heartRate;
    tracker.steps = steps;
    tracker.caloriesBurned = caloriesBurned;

    printf("Input data:\n");
    printf("Heart rate: %d\n", tracker.heartRate);
    printf("Steps: %d\n", tracker.steps);
    printf("Calories burned: %d\n", tracker.caloriesBurned);

    calculateAverages(tracker);

    return 0;
}