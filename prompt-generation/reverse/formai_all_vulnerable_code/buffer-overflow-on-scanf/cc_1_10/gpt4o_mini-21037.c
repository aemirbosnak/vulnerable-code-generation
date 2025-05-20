//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORKOUTS 100
#define NAME_LEN 50

typedef struct {
    char workout_name[NAME_LEN];
    float distance; // in kilometers
    float duration; // in minutes
} Workout;

typedef struct {
    Workout workouts[MAX_WORKOUTS];
    int count;
} FitnessTracker;

void addWorkout(FitnessTracker *tracker);
void viewWorkouts(FitnessTracker *tracker);
void calculateStatistics(FitnessTracker *tracker);
void displayMenu();
void clearBuffer();

int main() {
    FitnessTracker tracker = { .count = 0 };
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);
        clearBuffer(); // clear input buffer

        switch (choice) {
            case 1:
                addWorkout(&tracker);
                break;
            case 2:
                viewWorkouts(&tracker);
                break;
            case 3:
                calculateStatistics(&tracker);
                break;
            case 4:
                printf("Exiting Fitness Tracker. Stay fit!\n");
                break;
            default:
                printf("Invalid choice! Please select again.\n");
        }
    } while (choice != 4);

    return 0;
}

void displayMenu() {
    printf("\n--- Fitness Tracker Menu ---\n");
    printf("1. Add Workout\n");
    printf("2. View Workouts\n");
    printf("3. Calculate Statistics\n");
    printf("4. Exit\n");
    printf("Please enter your choice: ");
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void addWorkout(FitnessTracker *tracker) {
    if (tracker->count >= MAX_WORKOUTS) {
        printf("Workout limit reached! Cannot add more workouts.\n");
        return;
    }

    Workout newWorkout;
    printf("Enter workout name: ");
    fgets(newWorkout.workout_name, NAME_LEN, stdin);
    newWorkout.workout_name[strcspn(newWorkout.workout_name, "\n")] = 0; // remove newline

    printf("Enter distance (in kilometers): ");
    scanf("%f", &newWorkout.distance);
    clearBuffer();

    printf("Enter duration (in minutes): ");
    scanf("%f", &newWorkout.duration);
    clearBuffer();

    tracker->workouts[tracker->count] = newWorkout;
    tracker->count++;
    printf("Workout added successfully!\n");
}

void viewWorkouts(FitnessTracker *tracker) {
    if (tracker->count == 0) {
        printf("No workouts logged yet!\n");
        return;
    }

    printf("\n--- Workouts Logged ---\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("Workout %d:\n", i + 1);
        printf("Name: %s\n", tracker->workouts[i].workout_name);
        printf("Distance: %.2f km\n", tracker->workouts[i].distance);
        printf("Duration: %.2f min\n", tracker->workouts[i].duration);
        printf("----------------------\n");
    }
}

void calculateStatistics(FitnessTracker *tracker) {
    if (tracker->count == 0) {
        printf("No workouts to calculate statistics!\n");
        return;
    }

    float totalDistance = 0.0;
    float totalDuration = 0.0;

    for (int i = 0; i < tracker->count; i++) {
        totalDistance += tracker->workouts[i].distance;
        totalDuration += tracker->workouts[i].duration;
    }
    
    printf("\n--- Workout Statistics ---\n");
    printf("Total Distance: %.2f km\n", totalDistance);
    printf("Total Duration: %.2f min\n", totalDuration);
    printf("Average Distance: %.2f km\n", totalDistance / tracker->count);
    printf("Average Duration: %.2f min\n", totalDuration / tracker->count);
}