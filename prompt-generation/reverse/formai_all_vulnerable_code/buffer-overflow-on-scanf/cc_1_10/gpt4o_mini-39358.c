//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORKOUTS 100
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    int duration; // in minutes
    float calories; // calories burned
} Workout;

typedef struct {
    Workout workouts[MAX_WORKOUTS];
    int count;
} FitnessTracker;

void displayMenu() {
    printf("\n=== Fitness Tracker ===\n");
    printf("1. Add Workout\n");
    printf("2. View Workout History\n");
    printf("3. Exit\n");
    printf("========================\n");
    printf("Select an option: ");
}

void addWorkout(FitnessTracker *tracker) {
    if (tracker->count >= MAX_WORKOUTS) {
        printf("Workout history is full! Cannot add more workouts.\n");
        return;
    }

    Workout newWorkout;
    
    printf("Enter workout name (e.g., Running, Cycling): ");
    scanf("%s", newWorkout.name);
    
    printf("Enter duration (minutes): ");
    scanf("%d", &newWorkout.duration);
    
    printf("Enter calories burned: ");
    scanf("%f", &newWorkout.calories);

    tracker->workouts[tracker->count] = newWorkout;
    tracker->count++;

    printf("Workout added successfully!\n");
}

void viewWorkoutHistory(FitnessTracker *tracker) {
    if (tracker->count == 0) {
        printf("No workouts recorded yet.\n");
        return;
    }

    printf("\n=== Workout History ===\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("Workout %d:\n", i + 1);
        printf("Name: %s\n", tracker->workouts[i].name);
        printf("Duration: %d minutes\n", tracker->workouts[i].duration);
        printf("Calories Burned: %.2f\n", tracker->workouts[i].calories);
        printf("========================\n");
    }
}

int main() {
    FitnessTracker tracker;
    tracker.count = 0;
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addWorkout(&tracker);
                break;
            case 2:
                viewWorkoutHistory(&tracker);
                break;
            case 3:
                printf("Exiting Fitness Tracker. Stay fit!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}