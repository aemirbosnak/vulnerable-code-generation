//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORKOUTS 100
#define MAX_STEPS 1000

typedef struct {
    char name[50];
    int duration;
    int calories;
} Workout;

typedef struct {
    int steps;
    int distance;
    int calories;
} StepTracker;

Workout workouts[MAX_WORKOUTS];
StepTracker stepTracker;
int numWorkouts = 0;
int numSteps = 0;

void addWorkout(char* name, int duration, int calories) {
    if (numWorkouts >= MAX_WORKOUTS) {
        printf("Error: Maximum number of workouts reached.\n");
        return;
    }

    strcpy(workouts[numWorkouts].name, name);
    workouts[numWorkouts].duration = duration;
    workouts[numWorkouts].calories = calories;

    numWorkouts++;
}

void displayWorkouts() {
    printf("Workouts:\n");
    for (int i = 0; i < numWorkouts; i++) {
        printf("%s - %d minutes - %d calories\n", workouts[i].name, workouts[i].duration, workouts[i].calories);
    }
}

void resetStepTracker() {
    stepTracker.steps = 0;
    stepTracker.distance = 0;
    stepTracker.calories = 0;
}

void startStepTracker() {
    time_t startTime = time(NULL);
    while (1) {
        int steps = 0;
        printf("Enter number of steps: ");
        scanf("%d", &steps);

        if (steps <= 0) {
            printf("Invalid input.\n");
            continue;
        }

        stepTracker.steps += steps;
        stepTracker.distance += steps * 0.762;
        stepTracker.calories += (int) ((double) steps * 0.0175 * (double) (time(NULL) - startTime));

        numSteps++;
        printf("Steps: %d\n", stepTracker.steps);
        printf("Distance: %.2f km\n", stepTracker.distance / 1000);
        printf("Calories burned: %d\n", stepTracker.calories);
    }
}

int main() {
    addWorkout("Running", 30, 300);
    addWorkout("Cycling", 45, 450);

    displayWorkouts();

    resetStepTracker();
    startStepTracker();

    return 0;
}