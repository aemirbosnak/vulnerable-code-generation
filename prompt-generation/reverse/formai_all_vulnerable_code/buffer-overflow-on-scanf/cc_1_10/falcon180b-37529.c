//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_WORKOUTS 10

typedef struct {
    char name[50];
    int duration;
    int caloriesBurned;
} workout;

void addWorkout(workout workouts[], int numWorkouts, char name[], int duration, int caloriesBurned) {
    if (numWorkouts >= MAX_WORKOUTS) {
        printf("Cannot add more than %d workouts.\n", MAX_WORKOUTS);
        return;
    }
    strcpy(workouts[numWorkouts].name, name);
    workouts[numWorkouts].duration = duration;
    workouts[numWorkouts].caloriesBurned = caloriesBurned;
    numWorkouts++;
}

void displayWorkouts(workout workouts[], int numWorkouts) {
    printf("Workout Name\tDuration (mins)\tCalories Burned\n");
    for (int i = 0; i < numWorkouts; i++) {
        printf("%s\t\t%d\t\t%d\n", workouts[i].name, workouts[i].duration, workouts[i].caloriesBurned);
    }
}

int main() {
    srand(time(NULL));
    int numWorkouts = 0;
    workout workouts[MAX_WORKOUTS];
    char choice;

    do {
        printf("Fitness Tracker\n");
        printf("1. Add a workout\n");
        printf("2. Display workouts\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            printf("Enter workout name: ");
            scanf("%s", workouts[numWorkouts].name);
            printf("Enter workout duration (in minutes): ");
            scanf("%d", &workouts[numWorkouts].duration);
            printf("Enter calories burned: ");
            scanf("%d", &workouts[numWorkouts].caloriesBurned);
            numWorkouts++;
            break;
        case '2':
            displayWorkouts(workouts, numWorkouts);
            break;
        case '3':
            printf("Thank you for using Fitness Tracker!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= '3');

    return 0;
}