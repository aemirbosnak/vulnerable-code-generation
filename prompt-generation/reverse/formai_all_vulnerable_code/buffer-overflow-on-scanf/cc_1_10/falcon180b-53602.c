//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORKOUTS 100
#define MAX_STEPS 10000

typedef struct {
    char name[50];
    int steps;
    int calories;
} Workout;

void addWorkout(Workout workouts[], int numWorkouts) {
    printf("Enter workout name: ");
    scanf("%s", workouts[numWorkouts].name);
    workouts[numWorkouts].steps = 0;
    workouts[numWorkouts].calories = 0;
    numWorkouts++;
}

void displayWorkouts(Workout workouts[], int numWorkouts) {
    printf("\nWorkout Summary:\n");
    printf("--------------------\n");
    printf("Name\tSteps\tCalories\n");
    for (int i = 0; i < numWorkouts; i++) {
        printf("%s\t%d\t%d\n", workouts[i].name, workouts[i].steps, workouts[i].calories);
    }
}

void calculateCalories(int steps) {
    int calories = steps * 0.0425;
    printf("\nCalories burned: %d\n", calories);
}

int main() {
    int numWorkouts = 0;
    Workout workouts[MAX_WORKOUTS];

    srand(time(NULL));
    int maxSteps = rand() % MAX_STEPS + 1;

    while (numWorkouts < MAX_WORKOUTS) {
        addWorkout(workouts, numWorkouts);
    }

    int totalSteps = 0;
    for (int i = 0; i < numWorkouts; i++) {
        printf("\nWorkout %d:\n", i+1);
        int steps = rand() % maxSteps + 1;
        workouts[i].steps += steps;
        totalSteps += steps;
        calculateCalories(steps);
    }

    displayWorkouts(workouts, numWorkouts);

    return 0;
}