//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

#define MAX_WORKOUTS 10
#define MAX_STEPS 1000

typedef struct {
    char name[50];
    int steps;
    int distance;
    int calories;
    int heartRate;
    time_t startTime;
    time_t endTime;
    bool isSaved;
} workout;

workout workouts[MAX_WORKOUTS];
int numWorkouts = 0;

void addWorkout() {
    if (numWorkouts >= MAX_WORKOUTS) {
        printf("Cannot add more than %d workouts.\n", MAX_WORKOUTS);
        return;
    }
    printf("Enter workout name: ");
    scanf("%s", workouts[numWorkouts].name);
    workouts[numWorkouts].steps = 0;
    workouts[numWorkouts].distance = 0;
    workouts[numWorkouts].calories = 0;
    workouts[numWorkouts].heartRate = 0;
    workouts[numWorkouts].startTime = time(NULL);
    workouts[numWorkouts].endTime = 0;
    workouts[numWorkouts].isSaved = false;
    numWorkouts++;
}

void saveWorkout() {
    if (!workouts[numWorkouts-1].isSaved) {
        workouts[numWorkouts-1].endTime = time(NULL);
        workouts[numWorkouts-1].isSaved = true;
    }
}

void displayWorkouts() {
    printf("Workout Name | Steps | Distance | Calories | Heart Rate | Time\n");
    for (int i = 0; i < numWorkouts; i++) {
        if (workouts[i].isSaved) {
            double distance = (double)workouts[i].steps * 0.762;
            double calories = (double)workouts[i].steps * 0.0175 * (double)workouts[i].heartRate / 60;
            printf("%s | %d | %.2f | %d | %d | %s\n", workouts[i].name, workouts[i].steps, distance, calories, workouts[i].heartRate, ctime(&workouts[i].endTime));
        }
    }
}

void deleteWorkout() {
    if (numWorkouts == 0) {
        printf("No workouts to delete.\n");
        return;
    }
    int choice;
    printf("Enter the number of the workout to delete: ");
    scanf("%d", &choice);
    if (choice < 0 || choice >= numWorkouts) {
        printf("Invalid choice.\n");
        return;
    }
    for (int i = choice; i < numWorkouts-1; i++) {
        workouts[i] = workouts[i+1];
    }
    numWorkouts--;
}

int main() {
    int choice;
    while (true) {
        printf("\nFitness Tracker\n");
        printf("1. Add workout\n");
        printf("2. Save workout\n");
        printf("3. Display workouts\n");
        printf("4. Delete workout\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addWorkout();
                break;
            case 2:
                saveWorkout();
                break;
            case 3:
                displayWorkouts();
                break;
            case 4:
                deleteWorkout();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}