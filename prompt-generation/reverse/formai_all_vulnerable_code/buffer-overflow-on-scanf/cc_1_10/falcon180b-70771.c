//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXERCISES 100
#define MAX_NAME_LEN 50
#define MAX_DESCRIPTION_LEN 200

typedef struct {
    char name[MAX_NAME_LEN];
    char description[MAX_DESCRIPTION_LEN];
    int caloriesBurned;
} Exercise;

typedef struct {
    int numExercises;
    Exercise exercises[MAX_EXERCISES];
} Workout;

void addExercise(Workout *workout) {
    int i;
    for (i = 0; i < workout->numExercises; i++) {
        if (strcmp(workout->exercises[i].name, "") == 0) {
            break;
        }
    }
    if (i == workout->numExercises) {
        printf("Workout is full. Cannot add more exercises.\n");
        return;
    }
    printf("Enter exercise name: ");
    scanf("%s", workout->exercises[i].name);
    printf("Enter exercise description: ");
    scanf("%s", workout->exercises[i].description);
    printf("Enter calories burned: ");
    scanf("%d", &workout->exercises[i].caloriesBurned);
    workout->numExercises++;
}

void viewWorkout(Workout workout) {
    int i;
    printf("Workout:\n");
    for (i = 0; i < workout.numExercises; i++) {
        printf("%s: %s (%d calories)\n", workout.exercises[i].name, workout.exercises[i].description, workout.exercises[i].caloriesBurned);
    }
}

void main() {
    Workout workout;
    workout.numExercises = 0;
    int choice;
    do {
        printf("Fitness Tracker\n");
        printf("1. Add exercise\n");
        printf("2. View workout\n");
        printf("3. Quit\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            addExercise(&workout);
            break;
        case 2:
            viewWorkout(workout);
            break;
        case 3:
            printf("Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (choice!= 3);
}