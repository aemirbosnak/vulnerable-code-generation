//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORKOUTS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int duration; // in minutes
    int calories; // calories burned
} Workout;

typedef struct {
    Workout workouts[MAX_WORKOUTS];
    int count;
} FitnessTracker;

void addWorkout(FitnessTracker *tracker) {
    if (tracker->count >= MAX_WORKOUTS) {
        printf("Maximum number of workouts reached!\n");
        return;
    }
    
    Workout newWorkout;
    printf("Enter workout name: ");
    getchar(); // Clear buffer
    fgets(newWorkout.name, NAME_LENGTH, stdin);
    newWorkout.name[strcspn(newWorkout.name, "\n")] = 0; // Remove newline char

    printf("Enter duration in minutes: ");
    scanf("%d", &newWorkout.duration);

    printf("Enter calories burned: ");
    scanf("%d", &newWorkout.calories);

    tracker->workouts[tracker->count] = newWorkout;
    tracker->count++;
    printf("Workout added successfully!\n");
}

void viewWorkouts(const FitnessTracker *tracker) {
    if (tracker->count == 0) {
        printf("No workouts recorded yet.\n");
        return;
    }
    
    printf("Your Workouts:\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("Workout %d: %s, Duration: %d minutes, Calories: %d\n",
            i + 1, tracker->workouts[i].name, 
            tracker->workouts[i].duration, 
            tracker->workouts[i].calories);
    }
}

void calculateCaloriesBurned(const FitnessTracker *tracker) {
    int totalCalories = 0;
    for (int i = 0; i < tracker->count; i++) {
        totalCalories += tracker->workouts[i].calories;
    }
    printf("Total calories burned in recorded workouts: %d\n", totalCalories);
}

void resetTracker(FitnessTracker *tracker) {
    tracker->count = 0;
    printf("All workouts have been reset!\n");
}

void menu() {
    printf("Fitness Tracker Menu:\n");
    printf("1. Add Workout\n");
    printf("2. View Workouts\n");
    printf("3. Calculate Total Calories Burned\n");
    printf("4. Reset Tracker\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

int main() {
    FitnessTracker tracker;
    tracker.count = 0;

    int choice;
    while (1) {
        menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: 
                addWorkout(&tracker);
                break;
            case 2:
                viewWorkouts(&tracker);
                break;
            case 3:
                calculateCaloriesBurned(&tracker);
                break;
            case 4:
                resetTracker(&tracker);
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please select again.\n");
        }
    }
    
    return 0;
}