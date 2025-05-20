//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORKOUTS 100
#define MAX_STEPS 10000
#define MAX_DISTANCE 1000
#define MAX_CALORIES 1000

typedef struct {
    char name[50];
    int steps;
    int distance;
    int calories;
} Workout;

Workout workouts[MAX_WORKOUTS];
int numWorkouts;

void addWorkout() {
    numWorkouts++;
    printf("Enter workout name: ");
    scanf("%s", workouts[numWorkouts-1].name);
    workouts[numWorkouts-1].steps = 0;
    workouts[numWorkouts-1].distance = 0;
    workouts[numWorkouts-1].calories = 0;
}

void viewWorkouts() {
    printf("Workout Name | Steps | Distance | Calories\n");
    for(int i = 0; i < numWorkouts; i++) {
        printf("%s | %d | %d | %d\n", workouts[i].name, workouts[i].steps, workouts[i].distance, workouts[i].calories);
    }
}

void startWorkout() {
    int workoutIndex;
    printf("Enter workout index: ");
    scanf("%d", &workoutIndex);
    if(workoutIndex >= 0 && workoutIndex < numWorkouts) {
        time_t startTime, endTime;
        workouts[workoutIndex].steps = 0;
        workouts[workoutIndex].distance = 0;
        workouts[workoutIndex].calories = 0;
        time(&startTime);
        printf("Workout started\n");
        while(1) {
            int steps, distance, calories;
            printf("Enter number of steps: ");
            scanf("%d", &steps);
            workouts[workoutIndex].steps += steps;
            printf("Enter distance in meters: ");
            scanf("%d", &distance);
            workouts[workoutIndex].distance += distance;
            workouts[workoutIndex].calories += (steps * 0.0175) + (distance * 0.00037);
            time(&endTime);
            double duration = difftime(endTime, startTime);
            if(duration >= 60) {
                printf("Workout ended\n");
                break;
            }
        }
    } else {
        printf("Invalid workout index\n");
    }
}

int main() {
    printf("Welcome to the Fitness Tracker\n");
    addWorkout();
    viewWorkouts();
    startWorkout();
    return 0;
}