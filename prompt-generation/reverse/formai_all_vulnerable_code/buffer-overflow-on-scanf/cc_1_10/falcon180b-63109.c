//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define NUM_WORKOUTS 5

typedef struct {
    char name[50];
    int duration;
    int caloriesBurned;
} Workout;

void printWorkout(Workout workout) {
    printf("Name: %s\n", workout.name);
    printf("Duration: %d minutes\n", workout.duration);
    printf("Calories Burned: %d\n\n", workout.caloriesBurned);
}

void addWorkout(Workout *workouts, int index) {
    char name[50];
    int duration, caloriesBurned;

    printf("Enter workout name: ");
    scanf("%s", name);

    printf("Enter workout duration (in minutes): ");
    scanf("%d", &duration);

    printf("Enter calories burned: ");
    scanf("%d", &caloriesBurned);

    strcpy(workouts[index].name, name);
    workouts[index].duration = duration;
    workouts[index].caloriesBurned = caloriesBurned;
}

void editWorkout(Workout *workouts, int index) {
    char name[50];
    int duration, caloriesBurned;

    printf("Enter new workout name: ");
    scanf("%s", name);

    printf("Enter new workout duration (in minutes): ");
    scanf("%d", &duration);

    printf("Enter new calories burned: ");
    scanf("%d", &caloriesBurned);

    strcpy(workouts[index].name, name);
    workouts[index].duration = duration;
    workouts[index].caloriesBurned = caloriesBurned;
}

void deleteWorkout(Workout *workouts, int index) {
    workouts[index] = workouts[--index];
}

void viewWorkouts(Workout *workouts, int numWorkouts) {
    printf("Viewing %d workouts:\n", numWorkouts);
    for (int i = 0; i < numWorkouts; i++) {
        printWorkout(workouts[i]);
    }
}

int main() {
    Workout workouts[NUM_WORKOUTS];
    int numWorkouts = 0;

    while (numWorkouts < NUM_WORKOUTS) {
        printf("Enter 1 to add a workout, 2 to view workouts, 3 to exit:\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (numWorkouts >= NUM_WORKOUTS) {
                printf("Cannot add more workouts.\n");
            } else {
                addWorkout(workouts, numWorkouts);
                numWorkouts++;
            }
            break;
        case 2:
            viewWorkouts(workouts, numWorkouts);
            break;
        case 3:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}