//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_WORKOUTS 10
#define MAX_EXERCISES 20
#define MAX_DURATION 60

typedef struct {
    char name[30];
    int duration;
} Workout;

typedef struct {
    char name[30];
    int calories;
} Exercise;

Workout workouts[MAX_WORKOUTS];
Exercise exercises[MAX_EXERCISES];
int num_workouts = 0;
int num_exercises = 0;

void add_workout(char* name, int duration) {
    if (num_workouts >= MAX_WORKOUTS) {
        printf("Error: Maximum number of workouts reached.\n");
        return;
    }

    strcpy(workouts[num_workouts].name, name);
    workouts[num_workouts].duration = duration;
    num_workouts++;
}

void add_exercise(char* name, int calories) {
    if (num_exercises >= MAX_EXERCISES) {
        printf("Error: Maximum number of exercises reached.\n");
        return;
    }

    strcpy(exercises[num_exercises].name, name);
    exercises[num_exercises].calories = calories;
    num_exercises++;
}

void start_workout(int workout_id, int exercise_id) {
    if (workout_id < 0 || workout_id >= num_workouts) {
        printf("Error: Invalid workout ID.\n");
        return;
    }

    if (exercise_id < 0 || exercise_id >= num_exercises) {
        printf("Error: Invalid exercise ID.\n");
        return;
    }

    time_t start_time = time(NULL);
    int duration = workouts[workout_id].duration;
    int calories = exercises[exercise_id].calories;

    printf("Starting workout: %s\n", workouts[workout_id].name);
    printf("Duration: %d minutes\n", duration);
    printf("Calories burned: %d\n", calories);

    time_t end_time = start_time + duration * 60;
    while (time(NULL) < end_time) {
        // Simulate workout
    }

    printf("Workout completed.\n");
}

int main() {
    add_workout("Running", 30);
    add_workout("Cycling", 45);

    add_exercise("Jogging", 200);
    add_exercise("Sprinting", 300);

    start_workout(0, 0);

    return 0;
}