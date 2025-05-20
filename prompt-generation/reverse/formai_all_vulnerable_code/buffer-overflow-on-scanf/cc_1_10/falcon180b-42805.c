//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORKOUTS 100
#define MAX_EXERCISES 100
#define MAX_REPS 100
#define MAX_SETS 100
#define MAX_DURATION 100

typedef struct {
    char name[50];
    int duration;
} Workout;

typedef struct {
    char name[50];
    int reps;
    int sets;
} Exercise;

void addWorkout(Workout workouts[], int numWorkouts) {
    char name[50];
    int duration;

    printf("Enter workout name: ");
    scanf("%s", name);

    printf("Enter workout duration (in seconds): ");
    scanf("%d", &duration);

    strcpy(workouts[numWorkouts].name, name);
    workouts[numWorkouts].duration = duration;

    numWorkouts++;
}

void addExercise(Exercise exercises[], int numExercises, int workoutId) {
    char name[50];
    int reps, sets;

    printf("Enter exercise name for workout %d: ", workoutId);
    scanf("%s", name);

    printf("Enter number of reps: ");
    scanf("%d", &reps);

    printf("Enter number of sets: ");
    scanf("%d", &sets);

    strcpy(exercises[numExercises].name, name);
    exercises[numExercises].reps = reps;
    exercises[numExercises].sets = sets;

    numExercises++;
}

void printWorkout(Workout workout) {
    printf("Workout name: %s\n", workout.name);
    printf("Duration: %d seconds\n", workout.duration);
}

void printExercise(Exercise exercise) {
    printf("Exercise name: %s\n", exercise.name);
    printf("Reps: %d\n", exercise.reps);
    printf("Sets: %d\n", exercise.sets);
}

void trackWorkout(Workout workout, Exercise exercises[], int numExercises) {
    int i;
    time_t startTime, endTime;

    time(&startTime);

    for (i = 0; i < numExercises; i++) {
        printf("Starting %s...\n", exercises[i].name);
        fflush(stdout);

        time(&endTime);
        while (difftime(endTime, startTime) < workout.duration) {
            // Perform exercise
        }

        printf("Finished %s.\n", exercises[i].name);
        fflush(stdout);
    }
}

int main() {
    Workout workouts[MAX_WORKOUTS];
    Exercise exercises[MAX_EXERCISES];
    int numWorkouts = 0, numExercises = 0, workoutId;

    addWorkout(workouts, numWorkouts);

    while (numWorkouts > 0) {
        printf("Select a workout:\n");
        for (workoutId = 0; workoutId < numWorkouts; workoutId++) {
            printWorkout(workouts[workoutId]);
        }

        scanf("%d", &workoutId);

        trackWorkout(workouts[workoutId], exercises, numExercises);
    }

    return 0;
}