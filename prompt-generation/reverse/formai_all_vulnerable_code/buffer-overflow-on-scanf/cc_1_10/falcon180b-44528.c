//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_WORKOUTS 10
#define MAX_WORKOUT_NAME_LENGTH 50
#define MAX_WORKOUT_DURATION 60

typedef struct {
    char name[MAX_WORKOUT_NAME_LENGTH];
    int duration;
} Workout;

int main() {
    int numWorkouts = 0;
    Workout workouts[MAX_WORKOUTS];
    char input[MAX_WORKOUT_NAME_LENGTH];

    printf("Welcome to the Fitness Tracker!\n");
    printf("Enter your name: ");
    scanf("%s", input);

    printf("Hello, %s! How many workouts would you like to track today?\n", input);
    scanf("%d", &numWorkouts);

    printf("Enter the name and duration of each workout (in seconds):\n");

    for (int i = 0; i < numWorkouts; i++) {
        printf("Workout %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", workouts[i].name);
        printf("Duration: ");
        scanf("%d", &workouts[i].duration);
    }

    printf("\nWorkout Summary:\n");
    printf("Name\t\tDuration\n");
    for (int i = 0; i < numWorkouts; i++) {
        printf("%s\t\t%d seconds\n", workouts[i].name, workouts[i].duration);
    }

    printf("\nTotal Workout Duration: %d seconds\n", totalWorkoutDuration(workouts, numWorkouts));

    return 0;
}

int totalWorkoutDuration(Workout workouts[], int numWorkouts) {
    int totalDuration = 0;

    for (int i = 0; i < numWorkouts; i++) {
        totalDuration += workouts[i].duration;
    }

    return totalDuration;
}