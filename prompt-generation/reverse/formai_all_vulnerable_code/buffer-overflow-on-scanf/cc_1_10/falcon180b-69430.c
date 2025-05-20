//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORKOUTS 100

typedef struct {
    char name[50];
    int duration;
    int calories;
} Workout;

void addWorkout(Workout workouts[], int numWorkouts) {
    char input[100];
    int duration, calories;

    printf("Enter workout name: ");
    scanf("%s", input);

    printf("Enter workout duration (in minutes): ");
    scanf("%d", &duration);

    printf("Enter calories burned: ");
    scanf("%d", &calories);

    strcpy(workouts[numWorkouts].name, input);
    workouts[numWorkouts].duration = duration;
    workouts[numWorkouts].calories = calories;

    numWorkouts++;
}

void displayWorkouts(Workout workouts[], int numWorkouts) {
    int i;

    for (i = 0; i < numWorkouts; i++) {
        printf("Name: %s\n", workouts[i].name);
        printf("Duration: %d minutes\n", workouts[i].duration);
        printf("Calories burned: %d\n\n", workouts[i].calories);
    }
}

int main() {
    int numWorkouts = 0;
    Workout workouts[MAX_WORKOUTS];

    time_t start, end;

    printf("Welcome to the Fitness Tracker!\n\n");

    while (1) {
        printf("1. Add workout\n");
        printf("2. Display workouts\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addWorkout(workouts, numWorkouts);
            break;

        case 2:
            displayWorkouts(workouts, numWorkouts);
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}