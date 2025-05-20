//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_WORKOUTS 10
#define MAX_EXERCISES 20
#define MAX_REPS 100

// Struct for workout
typedef struct {
    char name[50];
    int duration;
    int calories;
} Workout;

// Struct for exercise
typedef struct {
    char name[50];
    int reps;
    int sets;
} Exercise;

void addWorkout(Workout workouts[], int numWorkouts) {
    printf("Enter workout name: ");
    scanf("%s", workouts[numWorkouts].name);
    printf("Enter workout duration (in minutes): ");
    scanf("%d", &workouts[numWorkouts].duration);
    printf("Enter workout calories burned: ");
    scanf("%d", &workouts[numWorkouts].calories);
    numWorkouts++;
}

void printWorkout(Workout workout) {
    printf("Workout name: %s\n", workout.name);
    printf("Duration: %d minutes\n", workout.duration);
    printf("Calories burned: %d\n\n", workout.calories);
}

void addExercise(Exercise exercises[], int numExercises) {
    printf("Enter exercise name: ");
    scanf("%s", exercises[numExercises].name);
    printf("Enter number of reps: ");
    scanf("%d", &exercises[numExercises].reps);
    printf("Enter number of sets: ");
    scanf("%d", &exercises[numExercises].sets);
    numExercises++;
}

void printExercise(Exercise exercise) {
    printf("Exercise name: %s\n", exercise.name);
    printf("Reps: %d\n", exercise.reps);
    printf("Sets: %d\n\n", exercise.sets);
}

void main() {
    Workout workouts[MAX_WORKOUTS];
    Exercise exercises[MAX_EXERCISES];
    int numWorkouts = 0;
    int numExercises = 0;

    // Add some sample workouts
    addWorkout(workouts, numWorkouts);
    addWorkout(workouts, numWorkouts);
    addWorkout(workouts, numWorkouts);

    // Add some sample exercises
    addExercise(exercises, numExercises);
    addExercise(exercises, numExercises);
    addExercise(exercises, numExercises);

    // Print all workouts
    printf("Workouts:\n");
    for (int i = 0; i < numWorkouts; i++) {
        printWorkout(workouts[i]);
    }

    // Print all exercises
    printf("\nExercises:\n");
    for (int i = 0; i < numExercises; i++) {
        printExercise(exercises[i]);
    }
}