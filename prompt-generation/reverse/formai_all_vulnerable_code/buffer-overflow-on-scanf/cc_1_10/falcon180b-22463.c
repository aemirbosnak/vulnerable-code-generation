//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORKOUTS 100
#define MAX_EXERCISES 100
#define MAX_SETS 100
#define MAX_REPS 100
#define MAX_DURATION 100
#define MAX_DISTANCE 100
#define MAX_CALORIES 100
#define MAX_NOTES_LENGTH 100

typedef struct {
    char name[MAX_NOTES_LENGTH];
    int reps;
    int sets;
    int duration;
    int distance;
    int calories;
} Exercise;

typedef struct {
    char name[MAX_NOTES_LENGTH];
    int num_exercises;
    Exercise exercises[MAX_EXERCISES];
} Workout;

int main() {
    int choice;
    char name[MAX_NOTES_LENGTH];
    Workout workout;
    Exercise exercise;

    do {
        printf("Fitness Tracker\n");
        printf("1. New Workout\n");
        printf("2. View Workouts\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter workout name: ");
            scanf("%s", name);
            strcpy(workout.name, name);
            printf("Enter number of exercises: ");
            scanf("%d", &workout.num_exercises);

            for (int i = 0; i < workout.num_exercises; i++) {
                printf("Enter exercise name: ");
                scanf("%s", name);
                strcpy(exercise.name, name);
                printf("Enter reps: ");
                scanf("%d", &exercise.reps);
                printf("Enter sets: ");
                scanf("%d", &exercise.sets);
                printf("Enter duration: ");
                scanf("%d", &exercise.duration);
                printf("Enter distance: ");
                scanf("%d", &exercise.distance);
                printf("Enter calories: ");
                scanf("%d", &exercise.calories);

                strcpy(workout.exercises[i].name, name);
                workout.exercises[i].reps = exercise.reps;
                workout.exercises[i].sets = exercise.sets;
                workout.exercises[i].duration = exercise.duration;
                workout.exercises[i].distance = exercise.distance;
                workout.exercises[i].calories = exercise.calories;
            }
            break;
        case 2:
            printf("View Workouts\n");
            break;
        case 3:
            printf("Exit\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice!= 3);

    return 0;
}