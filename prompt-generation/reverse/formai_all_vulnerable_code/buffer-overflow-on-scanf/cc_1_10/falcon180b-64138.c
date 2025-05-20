//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORKOUTS 100

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

    printf("Enter workout duration (in seconds): ");
    scanf("%d", &workouts[numWorkouts].duration);

    printf("Enter workout calories burned: ");
    scanf("%d", &workouts[numWorkouts].calories);

    numWorkouts++;
}

void displayWorkouts(Workout workouts[], int numWorkouts) {
    printf("\nWorkout List:\n");
    for (int i = 0; i < numWorkouts; i++) {
        printf("%s - %d seconds - %d calories\n", workouts[i].name, workouts[i].duration, workouts[i].calories);
    }
}

void calculateTotals(Workout workouts[], int numWorkouts) {
    int totalDuration = 0;
    int totalCalories = 0;

    for (int i = 0; i < numWorkouts; i++) {
        totalDuration += workouts[i].duration;
        totalCalories += workouts[i].calories;
    }

    printf("\nTotal Duration: %d seconds\n", totalDuration);
    printf("Total Calories Burned: %d\n", totalCalories);
}

int main() {
    Workout workouts[MAX_WORKOUTS];
    int numWorkouts = 0;

    while (numWorkouts < MAX_WORKOUTS) {
        printf("\nEnter 1 to add a workout or 0 to exit: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            addWorkout(workouts, numWorkouts);
        } else if (choice == 0) {
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    displayWorkouts(workouts, numWorkouts);
    calculateTotals(workouts, numWorkouts);

    return 0;
}