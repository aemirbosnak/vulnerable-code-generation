//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORKOUTS 100
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    int duration; // duration in minutes
    char type[NAME_LENGTH]; // type of workout (e.g., cardio, strength)
} Workout;

typedef struct {
    Workout workouts[MAX_WORKOUTS];
    int count;
} FitnessTracker;

void addWorkout(FitnessTracker *tracker) {
    if (tracker->count >= MAX_WORKOUTS) {
        printf("Workout log is full!\n");
        return;
    }
    
    Workout newWorkout;
    
    printf("Enter workout name: ");
    scanf("%s", newWorkout.name);

    printf("Enter workout duration (in minutes): ");
    scanf("%d", &newWorkout.duration);

    printf("Enter workout type (e.g., cardio, strength): ");
    scanf("%s", newWorkout.type);

    tracker->workouts[tracker->count] = newWorkout;
    tracker->count++;

    printf("Workout added successfully!\n");
}

void viewWorkouts(FitnessTracker *tracker) {
    if (tracker->count == 0) {
        printf("No workouts logged yet.\n");
        return;
    }

    printf("Workout History:\n");
    printf("-------------------------------------------\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("Workout %d: %s, Duration: %d minutes, Type: %s\n",
               i + 1, tracker->workouts[i].name,
               tracker->workouts[i].duration, tracker->workouts[i].type);
    }
    printf("-------------------------------------------\n");
}

void calculateTotalTime(FitnessTracker *tracker) {
    int totalDuration = 0;
    for (int i = 0; i < tracker->count; i++) {
        totalDuration += tracker->workouts[i].duration;
    }
    printf("Total workout time: %d minutes\n", totalDuration);
}

void displayMenu() {
    printf("Welcome to the Fitness Tracker!\n");
    printf("1. Add a workout\n");
    printf("2. View workouts\n");
    printf("3. Calculate total workout time\n");
    printf("4. Exit\n");
}

int main() {
    FitnessTracker tracker;
    tracker.count = 0;
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addWorkout(&tracker);
                break;
            case 2:
                viewWorkouts(&tracker);
                break;
            case 3:
                calculateTotalTime(&tracker);
                break;
            case 4:
                printf("Exiting the Fitness Tracker. Stay fit!\n");
                return 0;
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    }

    return 0;
}