//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_EXERCISES 10
#define MAX_EXERCISE_NAME_LENGTH 50
#define MAX_EXERCISE_DURATION_MINUTES 180
#define MAX_EXERCISE_DURATION_SECONDS (MAX_EXERCISE_DURATION_MINUTES * 60)

typedef struct {
    char name[MAX_EXERCISE_NAME_LENGTH];
    int duration; // in seconds
} Exercise;

typedef struct {
    int numExercises;
    Exercise exercises[MAX_EXERCISES];
} Workout;

void printWorkout(Workout* workout) {
    printf("Workout (%d exercises):\n", workout->numExercises);
    for (int i = 0; i < workout->numExercises; i++) {
        printf("%s (%d seconds)\n", workout->exercises[i].name, workout->exercises[i].duration);
    }
}

int main() {
    char input[100];
    Workout workout = { 0 };

    while (1) {
        printf("Enter workout name (or 'quit' to exit): ");
        scanf("%s", input);

        if (strcmp(input, "quit") == 0) {
            break;
        }

        workout.numExercises++;
        workout.exercises[workout.numExercises - 1].duration = 0;
        printf("Enter exercise name: ");
        scanf("%s", workout.exercises[workout.numExercises - 1].name);
    }

    printf("Workout (%d exercises):\n", workout.numExercises);
    for (int i = 0; i < workout.numExercises; i++) {
        printf("%s (%d seconds)\n", workout.exercises[i].name, workout.exercises[i].duration);
    }

    return 0;
}