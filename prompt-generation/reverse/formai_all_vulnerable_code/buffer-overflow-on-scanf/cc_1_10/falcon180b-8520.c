//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265359

struct FitnessData {
    float heartRate;
    float stepsTaken;
    float distanceTraveled;
    float caloriesBurned;
};

float calculateHeartRate(int steps) {
    float heartRate = (220 - (float) steps) / (220 - 60);
    return heartRate;
}

float calculateDistanceTraveled(int steps) {
    float distanceTraveled = (float) steps * 0.762;
    return distanceTraveled;
}

float calculateCaloriesBurned(int steps) {
    float caloriesBurned = (float) steps * 0.0175;
    return caloriesBurned;
}

int main() {
    int choice, steps;
    struct FitnessData fitnessData;

    do {
        printf("Fitness Tracker\n");
        printf("1. Enter Steps\n");
        printf("2. View Fitness Data\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of steps taken: ");
                scanf("%d", &steps);
                printf("Heart Rate: %.2f\n", calculateHeartRate(steps));
                printf("Distance Traveled: %.2f km\n", calculateDistanceTraveled(steps));
                printf("Calories Burned: %.2f\n", calculateCaloriesBurned(steps));
                break;
            case 2:
                printf("Fitness Data:\n");
                printf("Heart Rate: %.2f\n", fitnessData.heartRate);
                printf("Steps Taken: %d\n", fitnessData.stepsTaken);
                printf("Distance Traveled: %.2f km\n", fitnessData.distanceTraveled);
                printf("Calories Burned: %.2f\n", fitnessData.caloriesBurned);
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 3);

    return 0;
}