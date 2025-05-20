//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORKOUTS 100
#define MAX_EXERCISES 10
#define MAX_SETS 10

typedef struct {
    char name[50];
    int reps;
    int sets;
    float weight;
} Exercise;

typedef struct {
    char name[50];
    int duration;
    int calories;
} Workout;

void addWorkout(Workout workouts[], int numWorkouts) {
    char input[100];
    printf("Enter workout name: ");
    scanf("%s", input);
    strcpy(workouts[numWorkouts].name, input);
    printf("Enter workout duration in seconds: ");
    scanf("%d", &workouts[numWorkouts].duration);
    printf("Enter calories burned: ");
    scanf("%d", &workouts[numWorkouts].calories);
    numWorkouts++;
}

void addExercise(Exercise exercises[], int numExercises) {
    char input[100];
    printf("Enter exercise name: ");
    scanf("%s", input);
    strcpy(exercises[numExercises].name, input);
    printf("Enter number of reps: ");
    scanf("%d", &exercises[numExercises].reps);
    printf("Enter number of sets: ");
    scanf("%d", &exercises[numExercises].sets);
    printf("Enter weight in pounds: ");
    scanf("%f", &exercises[numExercises].weight);
    numExercises++;
}

void displayWorkout(Workout workout) {
    printf("Workout name: %s\n", workout.name);
    printf("Duration: %d seconds\n", workout.duration);
    printf("Calories burned: %d\n", workout.calories);
}

void displayExercise(Exercise exercise) {
    printf("Exercise name: %s\n", exercise.name);
    printf("Reps: %d\n", exercise.reps);
    printf("Sets: %d\n", exercise.sets);
    printf("Weight: %f pounds\n", exercise.weight);
}

int main() {
    Workout workouts[MAX_WORKOUTS];
    Exercise exercises[MAX_EXERCISES];
    int numWorkouts = 0;
    int numExercises = 0;

    addWorkout(workouts, numWorkouts);
    addExercise(exercises, numExercises);

    printf("Workouts:\n");
    for (int i = 0; i < numWorkouts; i++) {
        displayWorkout(workouts[i]);
    }

    printf("\nExercises:\n");
    for (int i = 0; i < numExercises; i++) {
        displayExercise(exercises[i]);
    }

    return 0;
}