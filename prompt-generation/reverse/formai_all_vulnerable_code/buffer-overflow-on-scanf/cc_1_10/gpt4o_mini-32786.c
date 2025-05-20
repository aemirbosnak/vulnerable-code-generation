//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORKOUTS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int caloriesBurned;
    int duration; // in minutes
} Workout;

typedef struct {
    Workout workouts[MAX_WORKOUTS];
    int count;
} FitnessTracker;

void addWorkout(FitnessTracker *tracker, const char *name, int calories, int duration) {
    if (tracker->count < MAX_WORKOUTS) {
        strncpy(tracker->workouts[tracker->count].name, name, NAME_LENGTH - 1);
        tracker->workouts[tracker->count].caloriesBurned = calories;
        tracker->workouts[tracker->count].duration = duration;
        tracker->count++;
        printf("Workout added: %s, Calories: %d, Duration: %d minutes\n", name, calories, duration);
    } else {
        printf("Cannot add workout. Maximum limit reached.\n");
    }
}

void viewWorkouts(const FitnessTracker *tracker) {
    if (tracker->count == 0) {
        printf("No workouts recorded yet.\n");
        return;
    }
    
    printf("Recorded Workouts:\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("%d. %s - Calories: %d, Duration: %d minutes\n", 
               i + 1, tracker->workouts[i].name, tracker->workouts[i].caloriesBurned, tracker->workouts[i].duration);
    }
}

int totalCaloriesBurned(const FitnessTracker *tracker) {
    int total = 0;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->workouts[i].caloriesBurned;
    }
    return total;
}

void displayMenu() {
    printf("Fitness Tracker Menu:\n");
    printf("1. Add Workout\n");
    printf("2. View Workouts\n");
    printf("3. Total Calories Burned\n");
    printf("4. Exit\n");
}

int main() {
    FitnessTracker tracker;
    tracker.count = 0;

    int choice;
    char name[NAME_LENGTH];
    int calories, duration;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter workout name: ");
                scanf(" %[^\n]", name);
                printf("Enter calories burned: ");
                scanf("%d", &calories);
                printf("Enter duration in minutes: ");
                scanf("%d", &duration);
                addWorkout(&tracker, name, calories, duration);
                break;
            case 2:
                viewWorkouts(&tracker);
                break;
            case 3:
                printf("Total calories burned: %d\n", totalCaloriesBurned(&tracker));
                break;
            case 4:
                printf("Exiting the Fitness Tracker. Stay fit!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}