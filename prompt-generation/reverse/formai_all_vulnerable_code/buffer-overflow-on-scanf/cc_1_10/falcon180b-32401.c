//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORKOUTS 100
#define MAX_STEPS 100000

typedef struct {
    char name[50];
    int duration;
    int calories;
    int steps;
} Workout;

Workout workouts[MAX_WORKOUTS];
int numWorkouts = 0;

void addWorkout() {
    printf("Enter workout name: ");
    scanf("%s", workouts[numWorkouts].name);

    printf("Enter workout duration in seconds: ");
    scanf("%d", &workouts[numWorkouts].duration);

    printf("Enter workout calories burned: ");
    scanf("%d", &workouts[numWorkouts].calories);

    printf("Enter workout steps taken: ");
    scanf("%d", &workouts[numWorkouts].steps);

    numWorkouts++;
}

void displayWorkouts() {
    printf("Workout Name | Duration (sec) | Calories Burned | Steps Taken\n");
    for (int i = 0; i < numWorkouts; i++) {
        printf("%s | %d | %d | %d\n", workouts[i].name, workouts[i].duration, workouts[i].calories, workouts[i].steps);
    }
}

void startWorkout(int workoutIndex) {
    time_t startTime, endTime;
    time(&startTime);
    workouts[workoutIndex].duration = 0;

    while (1) {
        printf("Press enter to end workout...\n");
        getchar();

        time(&endTime);
        workouts[workoutIndex].duration = difftime(endTime, startTime);
        break;
    }
}

int main() {
    int choice;

    do {
        printf("Fitness Tracker Menu:\n");
        printf("1. Add workout\n");
        printf("2. Display workouts\n");
        printf("3. Start workout\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addWorkout();
                break;
            case 2:
                displayWorkouts();
                break;
            case 3:
                printf("Enter workout index: ");
                int workoutIndex;
                scanf("%d", &workoutIndex);

                if (workoutIndex >= 0 && workoutIndex < numWorkouts) {
                    startWorkout(workoutIndex);
                } else {
                    printf("Invalid workout index.\n");
                }
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice!= 4);

    return 0;
}