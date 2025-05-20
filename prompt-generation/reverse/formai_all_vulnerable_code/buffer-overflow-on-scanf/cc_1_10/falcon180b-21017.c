//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_STR_LEN 50
#define MAX_NUM_EXERCISES 10
#define MAX_NUM_WORKOUTS 50

typedef struct {
    char name[MAX_STR_LEN];
    int caloriesBurned;
    int duration;
    int distance;
    int heartRate;
} Exercise;

typedef struct {
    Exercise exercises[MAX_NUM_EXERCISES];
    int numExercises;
} Workout;

void addExercise(Workout* workout) {
    printf("Enter exercise name: ");
    scanf("%s", workout->exercises[workout->numExercises].name);
    printf("Enter calories burned: ");
    scanf("%d", &workout->exercises[workout->numExercises].caloriesBurned);
    printf("Enter duration (in seconds): ");
    scanf("%d", &workout->exercises[workout->numExercises].duration);
    printf("Enter distance (in meters): ");
    scanf("%d", &workout->exercises[workout->numExercises].distance);
    printf("Enter heart rate (in bpm): ");
    scanf("%d", &workout->exercises[workout->numExercises].heartRate);
    workout->numExercises++;
}

void displayWorkout(Workout* workout) {
    printf("Workout %d:\n", workout->numExercises);
    for (int i = 0; i < workout->numExercises; i++) {
        printf("%s: %d calories burned, %d seconds duration, %d meters distance, %d bpm heart rate\n",
               workout->exercises[i].name,
               workout->exercises[i].caloriesBurned,
               workout->exercises[i].duration,
               workout->exercises[i].distance,
               workout->exercises[i].heartRate);
    }
}

int main() {
    Workout workout;
    workout.numExercises = 0;

    while (1) {
        printf("\nFitness Tracker\n");
        printf("1. Add exercise\n");
        printf("2. Display workout\n");
        printf("3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addExercise(&workout);
            break;
        case 2:
            displayWorkout(&workout);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}