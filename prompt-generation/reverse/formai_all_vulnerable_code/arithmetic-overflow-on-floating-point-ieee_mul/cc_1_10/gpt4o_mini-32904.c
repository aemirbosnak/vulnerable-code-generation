//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORKOUTS 100

typedef struct {
    char type[30];
    float duration; // in hours
    float caloriesBurned; // in calories
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
    
    printf("Enter the type of workout: ");
    scanf("%s", newWorkout.type);
    
    printf("Enter the duration (in hours): ");
    scanf("%f", &newWorkout.duration);
    
    // Approximate calories burned for demonstration purposes
    newWorkout.caloriesBurned = 0;
    if (strcmp(newWorkout.type, "running") == 0) {
        newWorkout.caloriesBurned = newWorkout.duration * 700;
    } else if (strcmp(newWorkout.type, "cycling") == 0) {
        newWorkout.caloriesBurned = newWorkout.duration * 500;
    } else if (strcmp(newWorkout.type, "swimming") == 0) {
        newWorkout.caloriesBurned = newWorkout.duration * 600;
    } else if (strcmp(newWorkout.type, "walking") == 0) {
        newWorkout.caloriesBurned = newWorkout.duration * 300;
    } else {
        printf("Unknown workout type! Defaulting to 200 calories/hour.\n");
        newWorkout.caloriesBurned = newWorkout.duration * 200;
    }

    tracker->workouts[tracker->count] = newWorkout;
    tracker->count++;
    
    printf("Workout added successfully!\n");
}

void viewWorkouts(const FitnessTracker *tracker) {
    if (tracker->count == 0) {
        printf("No workouts logged yet.\n");
        return;
    }
    
    printf("\nWorkout Log:\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("%d. Type: %s, Duration: %.2f hours, Calories Burned: %.2f\n",
               i + 1,
               tracker->workouts[i].type,
               tracker->workouts[i].duration,
               tracker->workouts[i].caloriesBurned);
    }
}

void totalCaloriesBurned(const FitnessTracker *tracker) {
    float totalCalories = 0;
    for (int i = 0; i < tracker->count; i++) {
        totalCalories += tracker->workouts[i].caloriesBurned;
    }
    printf("Total Calories Burned: %.2f cal\n", totalCalories);
}

int main() {
    FitnessTracker tracker;
    tracker.count = 0;

    int choice;
    
    do {
        printf("\n****** Fitness Tracker ******\n");
        printf("1. Add Workout\n");
        printf("2. View Workouts\n");
        printf("3. Total Calories Burned\n");
        printf("4. Exit\n");
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
                totalCaloriesBurned(&tracker);
                break;
            case 4:
                printf("Exiting the Fitness Tracker. Stay healthy!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 4);
    
    return 0;
}