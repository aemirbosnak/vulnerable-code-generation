//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int steps;
    int caloriesBurned;
    int distance;
    int activeMinutes;
    int heartRate;
} FitnessData;

FitnessData fitnessTracker;

void initFitnessTracker() {
    fitnessTracker.steps = 0;
    fitnessTracker.caloriesBurned = 0;
    fitnessTracker.distance = 0;
    fitnessTracker.activeMinutes = 0;
    fitnessTracker.heartRate = 0;
}

void updateFitnessData(int steps, int caloriesBurned, int distance, int activeMinutes, int heartRate) {
    fitnessTracker.steps += steps;
    fitnessTracker.caloriesBurned += caloriesBurned;
    fitnessTracker.distance += distance;
    fitnessTracker.activeMinutes += activeMinutes;
    fitnessTracker.heartRate = heartRate;
}

void displayFitnessData() {
    printf("Steps taken: %d\n", fitnessTracker.steps);
    printf("Calories burned: %d\n", fitnessTracker.caloriesBurned);
    printf("Distance covered: %d\n", fitnessTracker.distance);
    printf("Active minutes: %d\n", fitnessTracker.activeMinutes);
    printf("Heart rate: %d\n", fitnessTracker.heartRate);
}

int main() {
    int choice;
    int steps, caloriesBurned, distance, activeMinutes, heartRate;

    initFitnessTracker();

    do {
        printf("1. Update fitness data\n");
        printf("2. Display fitness data\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter steps taken: ");
                scanf("%d", &steps);
                printf("Enter calories burned: ");
                scanf("%d", &caloriesBurned);
                printf("Enter distance covered: ");
                scanf("%d", &distance);
                printf("Enter active minutes: ");
                scanf("%d", &activeMinutes);
                printf("Enter heart rate: ");
                scanf("%d", &heartRate);
                updateFitnessData(steps, caloriesBurned, distance, activeMinutes, heartRate);
                break;

            case 2:
                displayFitnessData();
                break;

            case 3:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while(choice!= 3);

    return 0;
}