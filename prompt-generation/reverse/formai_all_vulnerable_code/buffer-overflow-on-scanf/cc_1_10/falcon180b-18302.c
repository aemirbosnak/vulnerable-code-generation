//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORKOUTS 10
#define MAX_EXERCISES 20

typedef struct {
    char name[50];
    int duration;
    int calories;
} Workout;

typedef struct {
    char name[50];
    int reps;
    int sets;
    int weight;
} Exercise;

void addWorkout(Workout* workouts, int numWorkouts) {
    printf("Enter workout name: ");
    scanf("%s", workouts[numWorkouts].name);
    printf("Enter workout duration (in minutes): ");
    scanf("%d", &workouts[numWorkouts].duration);
    printf("Enter workout calories burned: ");
    scanf("%d", &workouts[numWorkouts].calories);
    numWorkouts++;
}

void displayWorkouts(Workout* workouts, int numWorkouts) {
    printf("\nWorkout summary:\n");
    for (int i = 0; i < numWorkouts; i++) {
        printf("%s - %d minutes - %d calories\n", workouts[i].name, workouts[i].duration, workouts[i].calories);
    }
}

void addExercise(Exercise* exercises, int numExercises) {
    printf("Enter exercise name: ");
    scanf("%s", exercises[numExercises].name);
    printf("Enter number of reps: ");
    scanf("%d", &exercises[numExercises].reps);
    printf("Enter number of sets: ");
    scanf("%d", &exercises[numExercises].sets);
    printf("Enter weight lifted (in pounds): ");
    scanf("%d", &exercises[numExercises].weight);
    numExercises++;
}

void displayExercises(Exercise* exercises, int numExercises) {
    printf("\nExercise summary:\n");
    for (int i = 0; i < numExercises; i++) {
        printf("%s - %d reps - %d sets - %d pounds\n", exercises[i].name, exercises[i].reps, exercises[i].sets, exercises[i].weight);
    }
}

int main() {
    Workout workouts[MAX_WORKOUTS];
    Exercise exercises[MAX_EXERCISES];

    int numWorkouts = 0;
    int numExercises = 0;

    addWorkout(workouts, numWorkouts);
    addExercise(exercises, numExercises);

    displayWorkouts(workouts, numWorkouts);
    displayExercises(exercises, numExercises);

    return 0;
}