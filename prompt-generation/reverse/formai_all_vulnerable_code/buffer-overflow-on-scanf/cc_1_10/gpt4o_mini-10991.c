//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORKOUTS 100
#define MAX_STRING_LENGTH 50

typedef struct {
    char name[MAX_STRING_LENGTH];
    int duration; // in minutes
    int caloriesBurned;
} Workout;

typedef struct {
    Workout workouts[MAX_WORKOUTS];
    int workoutCount;
} FitnessTracker;

void addWorkout(FitnessTracker *tracker) {
    if (tracker->workoutCount >= MAX_WORKOUTS) {
        printf("Workout limit reached. Cannot add more workouts.\n");
        return;
    }
    
    Workout newWorkout;
    
    printf("Enter workout name: ");
    scanf(" %[^\n]", newWorkout.name); // %[^\n] allows spaces
    printf("Enter workout duration (in minutes): ");
    scanf("%d", &newWorkout.duration);
    printf("Enter calories burned: ");
    scanf("%d", &newWorkout.caloriesBurned);
    
    tracker->workouts[tracker->workoutCount] = newWorkout;
    tracker->workoutCount++;
    
    printf("Workout added successfully!\n");
}

void viewWorkouts(const FitnessTracker *tracker) {
    if (tracker->workoutCount == 0) {
        printf("No workouts logged yet.\n");
        return;
    }
    
    printf("\n--- Workout History ---\n");
    for (int i = 0; i < tracker->workoutCount; i++) {
        printf("Workout %d: %s | Duration: %d minutes | Calories Burned: %d\n",
            i + 1, tracker->workouts[i].name, tracker->workouts[i].duration, tracker->workouts[i].caloriesBurned);
    }
}

void totalCaloriesBurned(const FitnessTracker *tracker) {
    int totalCalories = 0;
    for (int i = 0; i < tracker->workoutCount; i++) {
        totalCalories += tracker->workouts[i].caloriesBurned;
    }
    printf("Total calories burned: %d\n", totalCalories);
}

void displayMenu() {
    printf("\n--- Fitness Tracker Menu ---\n");
    printf("1. Add Workout\n");
    printf("2. View Workouts\n");
    printf("3. Total Calories Burned\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    FitnessTracker tracker = { .workoutCount = 0 };
    int choice;

    do {
        displayMenu();
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
                printf("Exiting the program. Keep fit!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}