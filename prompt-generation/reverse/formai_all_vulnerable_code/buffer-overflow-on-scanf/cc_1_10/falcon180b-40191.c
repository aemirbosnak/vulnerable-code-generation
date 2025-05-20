//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX_WORKOUTS 100
#define MAX_STEPS 10000
#define MAX_DISTANCE 10000
#define MAX_CALORIES 10000

typedef struct {
    char name[50];
    int steps;
    int distance;
    int calories;
} Workout;

Workout workouts[MAX_WORKOUTS];
int numWorkouts = 0;

void addWorkout() {
    if (numWorkouts >= MAX_WORKOUTS) {
        printf("Sorry, cannot add more workouts.\n");
        return;
    }

    printf("Enter workout name: ");
    scanf("%s", workouts[numWorkouts].name);

    printf("Enter number of steps: ");
    scanf("%d", &workouts[numWorkouts].steps);

    printf("Enter distance covered (in meters): ");
    scanf("%d", &workouts[numWorkouts].distance);

    printf("Enter calories burned: ");
    scanf("%d", &workouts[numWorkouts].calories);

    numWorkouts++;
}

void viewWorkouts() {
    if (numWorkouts == 0) {
        printf("No workouts yet.\n");
        return;
    }

    for (int i = 0; i < numWorkouts; i++) {
        printf("%s - Steps: %d, Distance: %d meters, Calories burned: %d\n",
               workouts[i].name, workouts[i].steps, workouts[i].distance, workouts[i].calories);
    }
}

void calculateTotals() {
    int totalSteps = 0;
    int totalDistance = 0;
    int totalCalories = 0;

    for (int i = 0; i < numWorkouts; i++) {
        totalSteps += workouts[i].steps;
        totalDistance += workouts[i].distance;
        totalCalories += workouts[i].calories;
    }

    printf("Total steps: %d\n", totalSteps);
    printf("Total distance covered (in meters): %d\n", totalDistance);
    printf("Total calories burned: %d\n", totalCalories);
}

int main() {
    int choice;

    do {
        printf("Fitness Tracker\n");
        printf("1. Add workout\n");
        printf("2. View workouts\n");
        printf("3. Calculate totals\n");
        printf("4. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addWorkout();
                break;
            case 2:
                viewWorkouts();
                break;
            case 3:
                calculateTotals();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}